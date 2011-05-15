#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

const int MAX = 50005;

struct point {
    int idx;
    int x;
    int y;
};

point P[MAX];
point S[MAX];

struct closest_pair {
    int idx1;
    int idx2;
    long long distance;
};

inline bool cmp_x(const point &a, const point &b)
{
    return a.x < b.x;
}

inline bool cmp_y(const point &a, const point &b)
{
    return a.y < b.y;
}

inline long long sqr(long long x)
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

int main()
{
    cout << setiosflags(ios::fixed) << setprecision(6);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        P[i].idx = i;
        scanf("%d%d", &P[i].x, &P[i].y);
    }
    sort(P, P + n, cmp_x);
    closest_pair res = closest_distance(P, 0, n - 1);
    cout << res.idx1 << " " << res.idx2 << " " << sqrt((double)res.distance) << endl;
}
