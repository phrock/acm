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
int b[51];

bool check(int n)
{
  if (n<=50 && b[n]>0) { b[n]--; return true; }
  for (int i=min(50, n); i>=1; --i)
    if (b[i]>0) {
      b[i]--;
      int res=check(n-i);
      if (res) return true;
      else b[i]++;
    }
  return false;
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
      if (sum%i==0) {
	memcpy(b, a, sizeof(a));
	bool ok=true;
	for (int j=0; j<sum/i; ++j) {
	  if (!check(i)) { ok=false; break; }
	}
	if (ok) { res=i; break; }
      }
    cout<<res<<endl;
  }
}
