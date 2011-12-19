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

vector<int> func(const vector<int> &v, int n)
{
    vector<int> process((int)(v).size());
    vector<int> res;
    while (n) {
        int idx = 0, m = INT_MAX;
        for (int i = 0; i < (int)(v).size(); ++i) {
            int aux = process[i] + v[i];
            if (aux < m) {
                idx = i;
                m = aux;
            }
        }
        process[idx] += v[idx];
        res.push_back(process[idx]);
        --n;
    }
    sort((res).begin(), (res).end());
    return res;
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
    for (int i = 0; i < B; ++i)
        cin >> vb[i];

    vector<int> v1 = func(va, n), v2 = func(vb, n);
    reverse((v2).begin(), (v2).end());
    for (int i = 0; i < n; ++i)
        v2[i] += v1[i];
    cout << *max_element((v1).begin(), (v1).end()) << " "
         << *max_element((v2).begin(), (v2).end()) << endl;
}
