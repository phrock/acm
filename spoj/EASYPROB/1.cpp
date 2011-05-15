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

// 137=2(2(2)+2+2(0))+2(2+2(0))+2(0)
// 1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

string func(int n, int cur)
{
    if (!n) {
        if (!cur) return "0";
        else return "";
    }
    string res;
    if (n % 2) {
        res = func(n >> 1, cur + 1);
        if (!res.empty()) res += "+";
        res += "2(" + func(cur, 0) + ")";
    }
    else {
        res = func(n >> 1, cur + 1);
    }
    return res;
}

int main()
{
    int a[] = {137, 1315, 73, 136, 255, 1384, 16385};
    vector<string> v;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
        string s;
        stringstream os(s);
        os << a[i] << "=" << func(a[i], 0);
        v.push_back(os.str());
    }
    // Need replace "2(2(0))" with "2" in the result output
    string del = "2(2(0))";
    int pos = 0;
    for (int i = 0; i < (int)(v).size(); ++i)
        while ((pos = v[i].find(del)) != -1)
            v[i] = v[i].replace(pos, (int)(del).size(), "2");
    for (int i = 0; i < (int)(v).size(); ++i) cout << v[i] << endl;
}
