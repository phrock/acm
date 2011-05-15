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
const int LAYER = 16;

struct point {
    int idx;
    long long x;
    long long y;
};

point P[MAX];
point PX[LAYER][MAX];
point PY[LAYER][MAX];

point SY[MAX];

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

closest_pair closest_distance_helper(int n, int cur)
{
    if (n <= 3) {
        closest_pair res;
        res.distance = INT_MAX;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                long long aux = sqr(PX[cur][i].x - PX[cur][j].x) + sqr(PX[cur][i].y - PX[cur][j].y);
                if (aux < res.distance) {
                    res.distance = aux;
                    res.idx1 = min(PX[cur][i].idx, PX[cur][j].idx);
                    res.idx2 = max(PX[cur][i].idx, PX[cur][j].idx);
                }
            }
        return res;
    }

    sort(PX[cur], PX[cur] + n, cmp_x);
    sort(PY[cur], PY[cur] + n, cmp_y);


    int m1 = n / 2, m2 = n - m1;
    
    memcpy(PX[cur + 1], PX[cur], m1 * sizeof(point));
    memcpy(PY[cur + 1], PY[cur], m1 * sizeof(point));
    // sort(PX[cur + 1], PX[cur + 1] + m1, cmp_x);
    // sort(PY[cur + 1], PY[cur + 1] + m1, cmp_y);
    closest_pair delta_q = closest_distance_helper(m1, cur + 1);

    memcpy(PX[cur + 1], PX[cur] + m1, m2 * sizeof(point));
    memcpy(PY[cur + 1], PX[cur] + m1, m2 * sizeof(point));
    // sort(PX[cur + 1], PX[cur + 1] + m2, cmp_x);
    // sort(PY[cur + 1], PY[cur + 1] + m2, cmp_y);
    closest_pair delta_r = closest_distance_helper(m2, cur + 1);

    closest_pair delta = delta_q.distance < delta_r.distance ? delta_q : delta_r;

    long long dist = sqrt(delta.distance) + 5;

    int split_line = PX[cur][n / 2].x;
    int m = 0;
    for (int i = 0; i < n; ++i)
        if (PY[cur][i].x >= split_line - dist &&
            PY[cur][i].x <= split_line + dist)
            SY[m++] = PY[cur][i];

    for (int i = 0; i < m; ++i) {
        for (int j = 1; j + i < m; ++j) {
            long long aux = sqr(SY[j].x - SY[i].x) + sqr(SY[j].y - SY[i].y);
            // // if (aux > delta.distance) break;
            // aux += sqr(SY[j].x - SY[i].x);
            if (aux < delta.distance) {
                delta.distance = aux;
                delta.idx1 = min(SY[i].idx, SY[j].idx);
                delta.idx2 = max(SY[i].idx, SY[j].idx);
            }
        }
    }

    return delta;
}

closest_pair closest_distance(point P[], int n)
{
    memcpy(PX[0], P, n * sizeof(point));
    // sort(PX[0], PX[0] + n, cmp_x);
    memcpy(PY[0], P, n * sizeof(point));
    // sort(PY[0], PY[0] + n, cmp_y);

    return closest_distance_helper(n, 0);
}

int main()
{
    cout << setiosflags(ios::fixed) << setprecision(6);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        P[i].idx = i;
        cin >> P[i].x >> P[i].y;
    }
    closest_pair res = closest_distance(P, n);
    cout << res.idx1 << " " << res.idx2 << " " << (double)sqrt(res.distance) << endl;
}
