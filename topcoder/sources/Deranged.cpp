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

class Deranged
{ 
public: 
  long long numDerangements(vector <int> nums);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,2,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, numDerangements(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, numDerangements(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, numDerangements(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 14LL; verify_case(3, Arg1, numDerangements(Arg0)); }
  void test_case_4() { int Arr0[] = {0,5,4,2,3,6,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 640LL; verify_case(4, Arg1, numDerangements(Arg0)); }
  void test_case_5() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 481066515734LL; verify_case(5, Arg1, numDerangements(Arg0)); }


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
  Deranged ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

// long long a[20][20];

// long long Deranged :: numDerangements(vector <int> nums)
// {
//   for (int i=0; i<20; ++i) a[i][0]=1;
//   for (int i=1; i<20; ++i)
//     for (int j=1; j<20; ++j)
//       a[i][j]=a[i-1][j]+a[i-1][j-1];
//   #ifdef DEBUG
//   print2(a, 20, 20);  
//   #endif
//   int n=(int)(nums).size();
//   vector<int> v(n);
//   for (int i=0; i<(int)(nums).size(); ++i) v[nums[i]]++;
//   #ifdef DEBUG
//   print(v);  
//   #endif
//   int k=n;
//   long long res=1;
//   for (int i=0; i<(int)(v).size(); ++i) {
//     res*=a[k-v[i]][v[i]], k-=v[i];
//     #ifdef DEBUG
//     cout<<res<<" "<<i<<endl    ;
//     #endif
//   }
//   return res;
// }

const int M=20;
long long fac[M];

long long cal(const vector<int> &a, int mask)
{
  map<int, int> mm;
  int n=(int)(a).size();
  for (int i=0; i<n; ++i)
    if (!(mask & (1<<i))) mm[a[i]]++;
  int k=0;
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i) k+=i->second;
  long long res=fac[k];
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i) res/=fac[i->second];
  return res;
}

long long Deranged :: numDerangements(vector <int> nums)
{
  fac[0]=1;
  for (int i=1; i<M; ++i) fac[i]=fac[i-1]*i;
  int n=(int)(nums).size();
  long long res=0;
  for (int i=0; i<(1<<n); ++i)
    if (__builtin_popcount(i)%2) res-=cal(nums, i);
    else res+=cal(nums, i);
  return res;
}
