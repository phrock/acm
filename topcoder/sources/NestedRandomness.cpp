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

class NestedRandomness
{ 
public: 
  double probability(int N, int nestings, int target);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.21666666666666667; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 0; double Arg3 = 0.19942680776014104; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 10; int Arg2 = 990; double Arg3 = 1.0461776397050886E-30; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }

int main()
{
  NestedRandomness ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

double dfs(int N, int nestings, int target)
{
  if (nestings==1) return 1.0/N;
  else {
    double res=0;
    for (int i=target+1; i<N; ++i) res+=dfs(i, nestings-1, target)*1.0/N;
    return res;
  }
}

double a[1005];
double b[1005];

double NestedRandomness :: probability(int N, int nestings, int target)
{
  // return dfs(N, nestings, target);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  a[N]=1;
  for (int loop=1; loop<=nestings; ++loop) {
    memset(b, 0, sizeof(b));
    for (int i=1; i<=N; ++i)
      for (int j=0; j<i; ++j)
	b[j]+=a[i]*1.0/i;
    memcpy(a, b, sizeof(a));
  }
  return a[target];
}

//   memset(dp, 0, sizeof(dp));
//   for (int i=0; i<=N; ++i) dp[0][i+1][i]=1;
//   for (int i=1; i<=nestings; ++i)
//     for (int j=1; j<=N; ++j) {
//       double aux=0;
//       for (int k=j+1; k<=N+1; ++k) aux+=dp[i-1][k][j];
//       cout<<aux<<endl;
//       for (int k=0; k<j; ++k)
// 	dp[i][j][k]=aux*1.0/j;
//       cout<<dp[i][j][target]<<endl;
//     }
//   return dp[nestings][N][target];
// }
