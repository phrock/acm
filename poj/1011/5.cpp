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

ifstream fin("in");
////////////////////////////////////////////////////////////////////////////////

template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }
int a[51];
bool flag;

void dfs(int cur, int n, int start, int sum)
{
  if (flag) return;
  if (sum==0) { flag=true; return; }
  if (cur==n) dfs(0, n, 50, sum-n);
  else {
    for (int i=min(n-cur, start); i>=1; --i)
      if (a[i]) { a[i]--; dfs(cur+i, n, i, sum); a[i]++; }
  }
}

bool check(int n, int sum)
{
  flag=false;
  dfs(0, n, 50, sum);
  return flag;  
}

int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  int n;
  while (cin>>n && n) {
    int x;
    int m=-1;
    int sum=0;
    memset(a, 0, sizeof(a));
    // memset(b, 0, sizeof(a));
    for (int i=0; i<n; ++i) cin>>x, a[x]++, m=max(m, x), sum+=x;
    int res=0;
    for (int i=m; i<=sum; ++i)
      if (sum%i==0 && check(i, sum)) { res=i; break; }
    cout<<res<<endl;
  }
}
