const int MAX = 50005;

struct point {
    int idx;
    long long x;
    long long y;
};

point P[MAX];
point S[MAX];

struct closest_pair {
    int idx1;
    int idx2;
    long long distance;
};

bool cmp_x(const point &a, const point &b)
{
    return a.x < b.x;
}

bool cmp_y(const point &a, const point &b)
{
    return a.y < b.y;
}

long long sqr(long long x)
{
    return x * x;
}

closest_pair closest_distance(point P[], int left, int right)
{
    if (left >= right) {
        closest_pair res;
        res.distance = LLONG_MAX;
        return res;
    }

    int mid = (left + right) / 2;

    int k = mid;
    while (k >= left && P[k].x == P[mid].x) --k;
    closest_pair res1 = closest_distance(P, left, k);

    k = mid;
    while (k <= right && P[k].x == P[mid].x) ++k;
    closest_pair res2 = closest_distance(P, k, right);

    closest_pair res = res1.distance < res2.distance ? res1 : res2;

    long long dist = sqrt(res.distance) + 1;

    int m = 0;
    for (int i = mid; i >= left && P[mid].x - P[i].x <= dist; --i)
        S[m++] = P[i];
    for (int i = mid + 1; i <= right && P[i].x - P[mid].x <= dist; ++i)
        S[m++] = P[i];

    sort(S, S + m, cmp_y);

    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j) {
            long long aux = sqr(S[j].y - S[i].y);
            if (aux > res.distance) break;
            aux += sqr(S[i].x - S[j].x);
            if (aux < res.distance) {
                res.distance = aux;
                res.idx1 = min(S[i].idx, S[j].idx);
                res.idx2 = max(S[i].idx, S[j].idx);
            }
        }

    return res;
}            

// int main()
// {
//     cout << setiosflags(ios::fixed) << setprecision(6);
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         P[i].idx = i;
//         cin >> P[i].x >> P[i].y;
//     }
//     sort(P, P + n, cmp_x);
//     closest_pair res = closest_distance(P, 0, n - 1);
//     cout << res.idx1 << " " << res.idx2 << " " << sqrt((double)res.distance) << endl;
// }


////////////////////////////////////////////////////////////////////////////////

const int MAX = 50005;
const double INF = 1e100;

struct point {
    int idx;
    double x;
    double y;
};

point P[MAX];
point S[MAX];

struct closest_pair {
    int idx1;
    int idx2;
    double distance;
};

bool cmp_x(const point &a, const point &b)
{
    return a.x < b.x;
}

bool cmp_y(const point &a, const point &b)
{
    return a.y < b.y;
}

closest_pair closest_distance(point P[], int left, int right)
{
    if (left >= right) {
        closest_pair res;
        res.distance = INF;
        return res;
    }

    int mid = (left + right) / 2;

    int k = mid;
    while (k >= left && P[k].x == P[mid].x) --k;
    closest_pair res1 = closest_distance(P, left, k);

    k = mid;
    while (k <= right && P[k].x == P[mid].x) ++k;
    closest_pair res2 = closest_distance(P, k, right);

    closest_pair res = res1.distance < res2.distance ? res1 : res2;

    int m = 0;
    for (int i = mid; i >= left && P[mid].x - P[i].x <= res.distance; --i)
        S[m++] = P[i];
    for (int i = mid + 1; i <= right && P[i].x - P[mid].x <= res.distance; ++i)
        S[m++] = P[i];

    sort(S, S + m, cmp_y);

    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j) {
            if (S[j].y - S[i].y > res.distance) break;
            double aux = hypot(S[i].x - S[j].x, S[i].y - S[j].y);
            if (aux < res.distance) {
                res.distance = aux;
                res.idx1 = min(S[i].idx, S[j].idx);
                res.idx2 = max(S[i].idx, S[j].idx);
            }
        }

    return res;
}            

// int main()
// {
//     cout << setiosflags(ios::fixed) << setprecision(6);
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         P[i].idx = i;
//         cin >> P[i].x >> P[i].y;
//     }
//     sort(P, P + n, cmp_x);
//     closest_pair res = closest_distance(P, 0, n - 1);
//     cout << res.idx1 << " " << res.idx2 << " " << res.distance << endl;
// }
