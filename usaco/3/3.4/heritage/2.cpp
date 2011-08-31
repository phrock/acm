/*
  ID:   aphrodi1
  LANG: C++
  PROG: heritage
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

ifstream fin("heritage.in");
ofstream fout("heritage.out");
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

void dfs(const string &in_order, const string &pre_order, string &post_order)
{
    if (in_order.empty())
        return;
    char root = pre_order[0];
    int idx = in_order.find(root);
    int left_size = idx, right_size = (int)(in_order).size() - left_size - 1;
    dfs(in_order.substr(0, left_size), pre_order.substr(1, left_size),
        post_order);
    dfs(in_order.substr(idx + 1, right_size),
        pre_order.substr(left_size + 1, right_size),
        post_order);
    post_order += root;
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

    string in_order, pre_order, post_order;
    cin >> in_order >> pre_order;
    dfs(in_order, pre_order, post_order);
    cout << post_order << endl;
}
