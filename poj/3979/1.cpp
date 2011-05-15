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


int main()
{
  string s;
  while (cin>>s) {
    int a=s[0]-'0';
    int b=s[2]-'0';
    int c=s[4]-'0';
    int d=s[6]-'0';
    int x, y;
    if (s[3]=='+') x=a*d+b*c;
    else x=a*d-b*c;
    y=b*d;
    int g=__gcd(x, y);
    if (x) {
      if (x<0) cout<<"-";
      x=abs(x);
      g=abs(g);
      if (y/g>1) cout<<x/g<<"/"<<y/g<<endl;
      else cout<<x/g<<endl;
    } else cout<<0<<endl;
  }
}
