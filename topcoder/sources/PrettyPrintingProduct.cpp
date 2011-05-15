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

class PrettyPrintingProduct
{ 
public: 
  string prettyPrint(int A, int B);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; string Arg2 = "36288 * 10^2"; verify_case(0, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 7; string Arg2 = "7 * 10^0"; verify_case(1, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 211; int Arg1 = 214; string Arg2 = "2038974024 * 10^0"; verify_case(2, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 411; int Arg1 = 414; string Arg2 = "28952...24024 * 10^0"; verify_case(3, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 412; int Arg1 = 415; string Arg2 = "2923450236 * 10^1"; verify_case(4, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 47; int Arg1 = 4700; string Arg2 = "14806...28928 * 10^1163"; verify_case(5, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1; int Arg1 = 19; string Arg2 = "12164...08832 * 10^3"; verify_case(6, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 13; int Arg1 = 25; string Arg2 = "32382...26624 * 10^4"; verify_case(7, Arg2, prettyPrint(Arg0, Arg1)); }

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
  PrettyPrintingProduct ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string PrettyPrintingProduct :: prettyPrint(int A, int B)
{
  
}
