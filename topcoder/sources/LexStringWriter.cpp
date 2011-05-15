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

class LexStringWriter
{ 
public: 
  int minMoves(string s);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaa"; int Arg1 = 5; verify_case(0, Arg1, minMoves(Arg0)); }
	void test_case_1() { string Arg0 = "ba"; int Arg1 = 4; verify_case(1, Arg1, minMoves(Arg0)); }
	void test_case_2() { string Arg0 = "abba"; int Arg1 = 9; verify_case(2, Arg1, minMoves(Arg0)); }
	void test_case_3() { string Arg0 = "acbbc"; int Arg1 = 12; verify_case(3, Arg1, minMoves(Arg0)); }
	void test_case_4() { string Arg0 = "cdaccb"; int Arg1 = 17; verify_case(4, Arg1, minMoves(Arg0)); }

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
  LexStringWriter ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int LexStringWriter :: minMoves(string s)
{
  int n=(int)(s).size();
  int dp1=0, dp2=0, left=0, right=0;
  for (int i=0; i<26; ++i) {
    int x=s.find('a'+i), y=s.rfind('a'+i);
    if (x==-1) continue;
    int aux1=min(dp1+abs(left-y), dp2+abs(right-y))+y-x;
    int aux2=min(dp1+abs(left-x), dp2+abs(right-x))+y-x;
    dp1=aux1, dp2=aux2;
    left=x, right=y;
    #ifdef DEBUG
    cout<<dp1<<" "<<dp2<<endl;    
    #endif
  }
  return n+min(dp1, dp2);
}
