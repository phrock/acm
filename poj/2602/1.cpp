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

int a[1000005];
int b[1000005];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; ++i) scanf("%d%d", &a[n-i-1], &b[n-i-1]);
  #ifdef DEBUG
  print(a, n);
  print(b, n);
  #endif
  int carry=0;
  for (int i=0; i<=n; ++i) {
    a[i]+=b[i]+carry;
    if (a[i]>9) carry=1, a[i]%=10;
    else carry=0;
  }
  int k=n;
  while (!a[k]) k--;
  while (k!=-1) printf("%d", a[k--]);
  printf("\n");
}
