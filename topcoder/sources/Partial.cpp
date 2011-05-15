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

class Partial
{ 
public: 
  string derivative(string expr, string vars);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "7*x"; string Arg1 = "x"; string Arg2 = "7"; verify_case(0, Arg2, derivative(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "x + z + 9*z^2 + y*z^3"; string Arg1 = "z"; string Arg2 = "3*y*z^2 + 18*z + 1"; verify_case(1, Arg2, derivative(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "x^2*y^2*z^2"; string Arg1 = "xy"; string Arg2 = "4*x*y*z^2"; verify_case(2, Arg2, derivative(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "y*8*z*x^3 + x^5 + y*2*x^4 + 9*x^4*z + x^5*5"; string Arg1 = ""; string Arg2 = "6*x^5 + 2*x^4*y + 9*x^4*z + 8*x^3*y*z"; verify_case(3, Arg2, derivative(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "9*x^9*y^9*z^9 + x^2*y^2*z^2"; string Arg1 = "xyzzy"; string Arg2 = "419904*x^8*y^7*z^7 + 8*x"; verify_case(4, Arg2, derivative(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "x + y + z"; string Arg1 = "yy"; string Arg2 = "0"; verify_case(5, Arg2, derivative(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "9*x^9 + 9*x^9 + 9*x^9 + 9*x^9 + 9*x^9 + 9*x^9"; string Arg1 = ""; string Arg2 = "54*x^9"; verify_case(6, Arg2, derivative(Arg0, Arg1)); }

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
  Partial ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string Partial :: derivative(string expr, string vars)
{
  
}
