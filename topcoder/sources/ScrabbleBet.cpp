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

class ScrabbleBet
{ 
public: 
  double estimate(int trials, int games, int winsNeeded, int winChance);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 50; double Arg4 = 0.9375; verify_case(0, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 50; double Arg4 = 0.4375; verify_case(1, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; int Arg3 = 25; double Arg4 = 0.5566860567603682; verify_case(2, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 20; int Arg2 = 5; int Arg3 = 10; double Arg4 = 0.08448495352665641; verify_case(3, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 15; int Arg2 = 1; int Arg3 = 0; double Arg4 = 0.0; verify_case(4, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 17; int Arg2 = 16; int Arg3 = 100; double Arg4 = 1.0; verify_case(5, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 10; int Arg2 = 10; int Arg3 = 75; double Arg4 = 0.9448701546682944; verify_case(6, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }

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
  ScrabbleBet ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

double ScrabbleBet :: estimate(int trials, int games, int winsNeeded, int winChance)
{
  double ncr[21][21];
  memset(ncr, 0, sizeof(ncr));
  for (int i=0; i<21; ++i) for (int j=0; j<=i; ++j) ncr[i][j]=!j?1:ncr[i-1][j-1]+ncr[i-1][j];
  double p=0;
  for (int i=0; i<winsNeeded; ++i) p+=ncr[games][i]*pow(winChance/100., i)*pow(1-winChance/100., games-i);
  return 1-pow(p, trials);
}
