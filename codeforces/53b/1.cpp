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

bool check(long long x, long long y)
{
  if (x<y) swap(x, y);
  return 4*x<=5*y;
}

int main()
{
  long long h, w;
  cin>>h>>w;
  // if (h<w) swap(h, w);
  long long height=0, width=0, area=0;
  for (long long a=1; a<=h; a*=2) {
    long long b=min(w, (4*a+4)/5);
    // cout<<a<<" "<<b<<endl;
    if (check(a, b) && (a*b>area || (a*b==area && a>height))) { height=a; width=b; area=a*b;/*cout<<a<<" "<<b<<" "<<area<<endl;*/ }
    b=min(w, 5*a/4);
    // cout<<a<<" "<<b<<endl;
    if (check(a, b) && (a*b>area || (a*b==area && a>height))) { height=a; width=b; area=a*b;/*cout<<a<<" "<<b<<" "<<area<<endl;*/ }
  }
  for (long long b=1; b<=width; b*=2) {
    long long a=min(h, 5*b/4);
    // cout<<a<<" "<<b<<endl;
    if (check(a, b) && (a*b>area || (a*b==area && a>height))) { height=a; width=b; area=a*b;/*cout<<a<<" "<<b<<" "<<area<<endl;*/ }
    a=min(h, (4*b+4)/5);
    // cout<<a<<" "<<b<<endl;
    if (check(a, b) && (a*b>area || (a*b==area && a>height))) { height=a; width=b; area=a*b;/*cout<<a<<" "<<b<<" "<<area<<endl;*/ }
  }
  cout<<height<<" "<<width<<endl;
}
