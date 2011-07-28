/*
  ID:   aphrodi1
  LANG: C++
  PROG: pprime
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

ifstream fin("pprime.in");
ofstream fout("pprime.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

bool is_prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    int a, b;
    cin >> a >> b;
    // because if a palindrome has even length, it could be divided by 11.
    vector<int> res;
    if (11 >= a && 11 <= b)
        res.push_back(11);
    for (int p1 = 1; p1 <= 9; p1 += 2) {
        int x = p1;
        if (x >= a && x <= b && is_prime(x))
            res.push_back(x);
        for (int p2 = 0; p2 <= 9; ++p2) {
            int x = p1 * 100 + p2 * 10 + p1;
            if (x >= a && x <= b && is_prime(x))
                res.push_back(x);
            for (int p3 = 0; p3 <= 9; ++p3) {
                int x = p1 * 10000 + p2 * 1000 + p3 * 100 + p2 * 10 + p1;
                if (x >= a && x <= b && is_prime(x))
                    res.push_back(x);
                for (int p4 = 0; p4 <= 9; ++p4) {
                    int x = p1 * 1000000 + p2 * 100000 + p3 * 10000 + p4 * 1000 +
                        p3 * 100 + p2 * 10 + p1;
                    if (x >= a && x <= b && is_prime(x))
                        res.push_back(x);
                }
            }
        }
    }
    sort((res).begin(), (res).end());
    for (int i = 0; i < (int)(res).size(); ++i)
        cout << res[i] << endl;
}
