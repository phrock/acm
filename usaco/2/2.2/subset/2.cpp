/*
  ID:   rock2to1
  LANG: C++
  PROG: subset
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

ifstream fin("subset.in");
ofstream fout("subset.out");
////////////////////////////////////////////////////////////////////////////////

long long dp[500][500];
long long aux[500][500];

int main()
{
  int n;
  fin>>n;
  if (n*(n+1)%4) { fout<<0<<endl; return 0; }
  int x=n*(n+1)/4;
  dp[0][0]=1;
  for (int i=1; i<=n; ++i) {
    memset(aux, 0, sizeof(aux));
    for (int j=0; j<=x; ++j) {
      for (int k=0; k<=x; ++k) {
	long long a=dp[j][k];
	aux[i+j][k]+=a;
	aux[j][i+k]+=a;
      }
    }
    memcpy(dp, aux, sizeof(aux));
  }
  // cout<<x<<endl;
  fout<<dp[x][x]/2<<endl;
}
