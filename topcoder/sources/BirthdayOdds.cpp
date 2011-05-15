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

class BirthdayOdds
{ 
public: 
  int minPeople(int minOdds, int daysInYear);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 75; int Arg1 = 5; int Arg2 = 4; verify_case(0, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 50; int Arg1 = 365; int Arg2 = 23; verify_case(1, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 365; int Arg2 = 4; verify_case(2, Arg2, minPeople(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 84; int Arg1 = 9227; int Arg2 = 184; verify_case(3, Arg2, minPeople(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  BirthdayOdds ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int BirthdayOdds :: minPeople(int minOdds, int daysInYear)
{
  if (daysInYear==1) return 2;
  for (int i=2; i<=INT_MAX; ++i) {
    double x=100;
    for (int j=0; j<i; ++j) 
      x=x*(daysInYear-j)/daysInYear;
    x=100-x;
    #ifdef DEBUG
    cout<<x<<endl;    
    #endif
    if (x>minOdds) return i;
  }
}
