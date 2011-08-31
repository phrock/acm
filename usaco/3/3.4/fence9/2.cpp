/*
  ID:   aphrodi1
  LANG: C++
  PROG: fence9
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

ifstream fin("fence9.in");
ofstream fout("fence9.out");
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

int lattices_on_line(int x, int y)
{
    int res = __gcd(abs(x), abs(y));
    return res;
}

// s = a + b / 2 - 1;
int pick(int n, int m, int p)
{
    int s = p * m / 2;
    int b = lattices_on_line(n, m) + lattices_on_line(p, 0) + lattices_on_line(n - p, m);
    int a = s + 1 - b / 2;
    return a;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n, m, p;
    cin >> n >> m >> p;
    cout << pick(n, m, p) << endl;
}
