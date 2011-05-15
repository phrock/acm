/*
  ID:   rock2to1
  LANG: C++
  PROG: nocows
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

ifstream fin("nocows.in");
ofstream fout("nocows.out");
////////////////////////////////////////////////////////////////////////////////

const int M=205;
long long dp[2][M][M];
long long a[M][M];

int main()
{
  int n, k;
  fin>>n>>k;
  if (n%2==0) { fout<<0<<endl; return 0; }
  for (int i=0; i<M; ++i)
    for (int j=0; j<=i; ++j) 
      if (!j) a[i][j]=1;
      else a[i][j]=a[i-1][j]+a[i-1][j-1];
  dp[0][1][1]=1;
  for (int i=2; i<=k; ++i) {
    int dest, src;
    if (i%2==0) { dest=1; src=0; }
    else { dest=0; src=1; }
    memset(dp[dest], 0, sizeof(dp[dest]));
    for (int j=2; j<=n; j+=2) {
      for (int total=max(j, 2*(i-1)+1); total<=n-(k-i)*2; total++) {
	int p=total-j;
	for (int father=j/2; father<=p; ++father)
	  dp[dest][j][total]+=dp[src][father][p]*a[father][j/2], dp[dest][j][total]%=9901;
      }
    }
  }
  long long res=0;
  int dest=(k%2==0)?1:0;
  for (int i=1; i<=n; ++i) res+=dp[dest][i][n];
  cout<<n<<" "<<k<<" "<<res<<" "<<res%9901<<endl;
  fout<<res%9901<<endl;
}
