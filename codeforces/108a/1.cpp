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

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

string int_to_time(int x)
{
    int hours = x / 60, seconds = x % 60;
    stringstream is;
    is << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << seconds;
    return is.str();
}

bool check(int x)
{
    string a = int_to_time(x), b = a;
    reverse((b).begin(), (b).end());
    return a == b;
}

int main()
{
    string s;
    cin >> s;
    int x = *({stringstream ss; ss << (s.substr(0, 2)); static int _; ss >> _; &_;}) * 60 + *({stringstream ss; ss << (s.substr(3)); static int _; ss >> _; &_;});
    const int MOD = 1440;
    x = (x + 1) % MOD;
    while (!check(x))
        x = (x + 1) % MOD;
    cout << int_to_time(x) << endl;
}
