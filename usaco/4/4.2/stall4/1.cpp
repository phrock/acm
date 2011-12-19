/*
  ID:   aphrodi1
  LANG: C++
  PROG: stall4
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

ifstream fin("stall4.in");
ofstream fout("stall4.out");
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

const int MAX = 205;
int g[MAX][MAX], match[MAX], visited[MAX];
int n1, n2;

bool hungaryHelper(int idx)
{
    for (int i = 1; i <= n2; ++i)
	if (g[idx][i] && !visited[i]) {
	    visited[i] = 1;
	    if (match[i] == -1 || hungaryHelper(match[i])) {
		match[i] = idx;
		return true;
	    }
	}
    return false;
}

int hungary()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n1; ++i) {
	memset(visited, 0, sizeof(visited));
	if (hungaryHelper(i))
            ++res;
    }
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

    cin >> n1 >> n2;
    for (int i = 1; i <= n1; ++i) {
        int s;
        cin >> s;
        for (int j = 0; j < s; ++j) {
            int tmp;
            cin >> tmp;
            g[i][tmp] = 1;
        }
    }
    cout << hungary() << endl;
}
