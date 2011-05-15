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

class Inchworm
{ 
public: 
  int lunchtime(int branch, int rest, int leaf);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 2; int Arg2 = 4; int Arg3 = 3; verify_case(0, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 6; int Arg2 = 4; int Arg3 = 2; verify_case(1, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 3; int Arg2 = 7; int Arg3 = 1; verify_case(2, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 21; int Arg1 = 7; int Arg2 = 3; int Arg3 = 2; verify_case(3, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 16; int Arg2 = 5; int Arg3 = 1; verify_case(4, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 3; int Arg2 = 7; int Arg3 = 48; verify_case(5, Arg3, lunchtime(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 1000; int Arg1 = 7; int Arg2 = 3; int Arg3 = 48; verify_case(6, Arg3, lunchtime(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Inchworm ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 
    
int Inchworm :: lunchtime(int branch, int rest, int leaf)
{
  int x=0;
  int res=0;
  while (x<=branch) {
    if (x%rest==0) res++;
    x+=leaf;
  }
  return res;
}
