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
    for (int i = 0; i < B; ++i)
        cin >> vb[i];

    vector<int> v1(A), v2(B);
    int source = n;
    while (source) {
        int idx = 0, m = INT_MAX;
        for (int i = 0; i < A; ++i) {
            int aux = v1[i] + va[i];
            if (aux < m) {
                idx = i;
                m = aux;
            }
        }
        v1[idx] += va[idx];
        --source;
    }
    int res_A = 0;
    for (int i = 0; i < A; ++i)
        res_A = max(res_A, v1[i]);
    
    for (int time = 1; time <= res_A; ++time) {
        int cnt = 0;
        for (int i = 0; i < A; ++i) {
            if (v1[i] > 0 && time % va[i] == 0) {
                ++cnt;
                v1[i] -= va[i];
            }
        }
        for (int i = 0; i < B; ++i) {
            if (v2[i])
                --v2[i];
        }
        for (int i = 0; i < cnt; ++i) {
            int idx = 0, m = INT_MAX;
            for (int j = 0; j < B; ++j) {
                int aux = v2[j] + vb[j];
                if (aux < m) {
                    idx = j;
                    m = aux;
                }
            }
            v2[idx] += vb[idx];
        }
    }

    cout << res_A << " " << res_A + *max_element((v2).begin(), (v2).end()) << endl;
}
