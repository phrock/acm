/*
  ID:   aphrodi1
  LANG: C++
  PROG: job
*/

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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

ifstream fin("job.in");
ofstream fout("job.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

bool check(const vector<int> &v, int n, int x)
{
    int aux = 0;
    for (int i = 0; i < (int)(v).size(); ++i)
        aux += x / v[i];
    return aux >= n;
}

int binary_search(const vector<int> &v, int n)
{
    int low = 0, high = 1000000;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(v, n, mid))
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    /////////////////////////////////////////////////////////////////////////

    int n, A, B;
    cin >> n >> A >> B;
    vector<int> va(A), vb(B);
    for (int i = 0; i < A; ++i)
        cin >> va[i];
    sort((va).begin(), (va).end());
    for (int i = 0; i < B; ++i)
        cin >> vb[i];
    sort((vb).begin(), (vb).end());

    int res_A = INT_MAX, res_B = INT_MAX;
    for (int i = 1; i <= A; ++i) {
        vector<int> tmp(va.begin(), va.begin() + i);
        int aux = binary_search(tmp, n);
        res_A = min(res_A, aux);
        for (int j = 1; j <= B; ++j) {
            int source = n, intermediate = 0, dest = 0, time = 0;
            vector<int> v1(i), v2(j);
            while (dest < n) {
                ++time;
                for (int k = 0; k < (int)(v2).size(); ++k) {
                    if (v2[k] == 0) {
                        if (intermediate > 0) {
                            --intermediate;
                            ++v2[k];
                            if (v2[k] == vb[k]) {
                                ++dest;
                                v2[k] = 0;
                            }
                        }
                    } else {
                        ++v2[k];
                        if (v2[k] == vb[k]) {
                            ++dest;
                            v2[k] = 0;
                        }
                    }
                }
                for (int k = 0; k < (int)(v1).size(); ++k) {
                    if (v1[k] == 0) {
                        if (source > 0) {
                            --source;
                            ++v1[k];
                            if (v1[k] == va[k]) {
                                ++intermediate;
                                v1[k] = 0;
                            }
                        }
                    } else {
                        ++v1[k];
                        if (v1[k] == va[k]) {
                            ++intermediate;
                            v1[k] = 0;
                        }
                    }
                }
            }
            res_B = min(res_B, time);
        }
    }
    cout << res_A << " " << res_B << endl;
}
