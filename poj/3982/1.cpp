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
////////////////////////////////////////////////////////////////////////////////

string addString(string a, string b)
{
  string result;
  int ai = a.length() - 1;
  int bi = b.length() - 1;
  int carry = 0;
  while ((ai >= 0) || (bi >= 0)) {
    int x = 0;
    int y = 0;
    int z = 0;
    if (ai >= 0) x = a[ai] - '0';
    if (bi >= 0) y = b[bi] - '0';
    z = x + y + carry;
    carry = z / 10;
    int m = z % 10;
    result = (char)(m+'0') + result;
    if (ai >= 0) ai--;
    if (bi >= 0) bi--;
  }
  if (carry > 0) result = (char)(carry+'0') + result;

  return result;
}

int main()
{
  vector<string> v(100);
  while (cin>>v[0]>>v[1]>>v[2]) {
    for (int i=3; i<=99; ++i) v[i]=addString(v[i-1], addString(v[i-2], v[i-3]));
    cout<<v[99]<<endl;
  }
}
