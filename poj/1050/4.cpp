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

int n;
int a[105][105];
int b[105];

int main()
{
  cin>>n;
  int res=INT_MIN;
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      cin>>a[i][j], res=max(res, a[i][j]);
  for (int i=0; i<n; ++i) {
    memset(b, 0, sizeof(b));
    for (int j=i; j<n; ++j) {
      for (int k=0; k<n; ++k) b[k]+=a[j][k];
      int aux=0;
      for (int k=0; k<n; ++k) {
	aux+=b[k];
	if (aux<0) aux=0;
	else res=max(res, aux);
      }
    }
  }
  cout<<res<<endl;
}
