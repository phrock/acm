/*
  ID:   rock2to1
  LANG: C++
  PROG: game1
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

ifstream fin("game1.in");
ofstream fout("game1.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////
const int M=101;
int dp[M][M];
int sum[M][M];
int n;
int v[M];

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  cin>>n;
  for (int i=0; i<n; ++i) cin>>v[i];
  for (int i=0; i<n; ++i)
    for (int j=1; i+j<=n; ++j)
      sum[i][j]=sum[i][j-1]+v[i+j-1];

  for (int k=1; k<=n; ++k)
    for (int i=0; i+k<=n; ++i)
      dp[i][k]=max(sum[i][k-1]-dp[i][k-1]+v[i+k-1], sum[i+1][k-1]-dp[i+1][k-1]+v[i]);
  cout<<dp[0][n]<<" "<<sum[0][n]-dp[0][n]<<endl;
}
