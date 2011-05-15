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

class Mortgage
{ 
public: 
  int monthlyPayment(int loan, int interest, int term);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arg1 = 50; int Arg2 = 1; int Arg3 = 86; verify_case(0, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2000000000; int Arg1 = 6000; int Arg2 = 1; int Arg3 = 671844808; verify_case(1, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 1000000; int Arg2 = 1000; int Arg3 = 988143; verify_case(2, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 129; int Arg2 = 30; int Arg3 = 10868; verify_case(3, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1999999999; int Arg1 = 1000000; int Arg2 = 1; int Arg3 = 1976284585; verify_case(4, Arg3, monthlyPayment(Arg0, Arg1, Arg2)); }

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
  Mortgage ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

long long a, month;
double r;
int res;

bool check(int x)
{
  long long rest=a;
  for (int i=0; i<month; ++i) {
    rest-=x;
    if (rest<=0) return true;
    rest=ceil((double)rest*r);
  }
  return false;
}

void func(long long p, long long q)
{
  if (p+1>=q) return;
  int mid=(p+q)>>1;
  #ifdef DEBUG
  cout<<p<<" "<<q<<" "<<mid<<" "<<check(mid)<<endl;  
  #endif
  if (check(mid)) {
    res=min(res, mid);
    func(p, mid);
  } else func(mid, q);
}

int Mortgage :: monthlyPayment(int loan, int interest, int term)
{
  a=loan;
  r=1+interest/12000.0;
  month=term*12;
  res=INT_MAX;
#ifdef DEBUG
  cout<<check(86)<<endl;
#endif
  func(1, a);

  return res;
}
