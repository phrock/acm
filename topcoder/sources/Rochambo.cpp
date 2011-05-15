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

class Rochambo
{ 
public: 
  int wins(string opponent);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "PS"; int Arg1 = 1; verify_case(0, Arg1, wins(Arg0)); }
	void test_case_1() { string Arg0 = "PSRRPS"; int Arg1 = 3; verify_case(1, Arg1, wins(Arg0)); }
	void test_case_2() { string Arg0 = "PSRPSRPRSR"; int Arg1 = 7; verify_case(2, Arg1, wins(Arg0)); }
	void test_case_3() { string Arg0 = "SRPSRPSPRSPRPSRPSRP"; int Arg1 = 16; verify_case(3, Arg1, wins(Arg0)); }
	void test_case_4() { string Arg0 = "RPPPRRPSSSRRRSRSPPSSPRRPSRRRRSPPPPSSPSSSSSRSSSRPRR"; int Arg1 = 18; verify_case(4, Arg1, wins(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Rochambo ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int Rochambo :: wins(string opponent)
{
  int res=0;
  char x='R';
  for (int i=0; i<(opponent).size(); ++i) {
    if (i<2) x='R';
    else {
      char a=opponent[i-1];
      char b=opponent[i-2];
      if (a==b) {
	if (a=='R') x='P';
	else if (a=='P') x='S';
	else if (a=='S') x='R';
      } else {
	if (a!='R' && b!='R') x='P';
	else if (a!='P' && b!='P') x='S';
	else if (a!='S' && b!='S') x='R';
      }
    }
    if (x=='R' && opponent[i]=='S' ||
	x=='P' && opponent[i]=='R' ||
	x=='S' && opponent[i]=='P')
      res++;
  }
  return res;
}
