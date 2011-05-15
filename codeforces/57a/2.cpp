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


int func(int x, int y, int n)
{
  if (!y) return x;
  else if (x==n) return n+y;
  else if (y==n) return 3*n-x;
  else return 4*n-y;
}

int main()
{
  int n, x1, y1, x2, y2;
  cin>>n>>x1>>y1>>x2>>y2;
  int a=func(x1, y1, n), b=func(x2, y2, n);
  cout<<min(abs(a-b), 4*n-abs(a-b))<<endl;
}
