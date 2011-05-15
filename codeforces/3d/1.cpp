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

const int M=50000;
int a[M], b[M];
string s;
int n;
long long res=LLONG_MAX;
string res_s;

void dfs(int cur, int left, long long sum)
{
  if (cur==n) { if (!left && sum<res) res=sum, res_s=s; return; }
  if (s[cur]=='(') dfs(cur+1, left+1, sum);
  else if (s[cur]==')') { if (left>0) dfs(cur+1, left-1, sum); }
  else {
    s[cur]='(';
    dfs(cur+1, left+1, sum+a[cur]);
    s[cur]='?';
    if (left>0) s[cur]=')', dfs(cur+1, left-1, sum+b[cur]), s[cur]='?';
  }
}

int main()
{
  cin>>s;
  n=(int)(s).size();
  for (int i=0; i<n; ++i)
    if (s[i]=='?') cin>>a[i]>>b[i];
  dfs(0, 0, 0);
  cout<<res<<endl;
  cout<<res_s<<endl;
}
