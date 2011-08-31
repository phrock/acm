/*
  ID:   aphrodi1
  LANG: C++
  PROG: humble
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
#include "/home/Aphrodite/program/acm/topcoder/libs/debug.cpp"
#endif

ifstream fin("humble.in");
ofstream fout("humble.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/


int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int k, n;
    cin >> k >> n;
    vector<int> prime(k);
    for (int i = 0; i < k; ++i)
        cin >> prime[i];
    sort((prime).begin(), (prime).end()), (prime).erase(unique((prime).begin(), (prime).end()), (prime).end());
    k = (int)(prime).size();
    set<long long> st;
    st.insert(1);
    long long aux = 1;

    while (n) {
        long long x = *st.begin();
        st.erase(st.begin());
        --n;

        for (int i = 0; i < k; ++i) {
            long long candidate = x * prime[i];
            if (candidate > aux && (int)(st).size() > n)
                continue;
            st.insert(candidate);
            aux = max(aux, candidate);
        }
    }

    cout << *st.begin() << endl;
}
