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

class CalendarRecycle
{ 
public: 
  int useAgain(int year);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2002; int Arg1 = 2013; verify_case(0, Arg1, useAgain(Arg0)); }
	void test_case_1() { int Arg0 = 2013; int Arg1 = 2019; verify_case(1, Arg1, useAgain(Arg0)); }
	void test_case_2() { int Arg0 = 2008; int Arg1 = 2036; verify_case(2, Arg1, useAgain(Arg0)); }
	void test_case_3() { int Arg0 = 9999; int Arg1 = 10010; verify_case(3, Arg1, useAgain(Arg0)); }
	void test_case_4() { int Arg0 = 2525; int Arg1 = 2531; verify_case(4, Arg1, useAgain(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  CalendarRecycle ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int is_leap(int n)
{
  if (n%400==0 ||
      (n%4==0 && n%100!=0))
    return 1;
  else return 0;
}

int CalendarRecycle :: useAgain(int year)
{
  int leap=is_leap(year);
  int a=leap?366:365;
  int res=year+1;
  while (true) {
    if (leap==is_leap(res)) {
      if (a%7==0) break;
    }
    a+=is_leap(res)?366:365;
    res++;
  }
  return res;
}
