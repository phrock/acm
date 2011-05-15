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

class DNASingleMatcher
{ 
public: 
  int longestMatch(string sequence1, string sequence2);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAACCCGGGGGGGGGGGGG"; string Arg1 = "AAAACCCGGGGGGGGGGGGGGGGTTTTTTTTTGGGGGGGGGGGG"; int Arg2 = 20; verify_case(0, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "CAT"; string Arg1 = "AT"; int Arg2 = 2; verify_case(1, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "TCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTCTC"; string Arg1 = "GAGAGGAGAAAGAGAGAGAAGAGAGGAGGAAAGAGAGAGAAAAGAGGGAA"; int Arg2 = 0; verify_case(2, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTAC"; string Arg1 = "GTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGTACGT"; int Arg2 = 48; verify_case(3, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "TC"; string Arg1 = "CATCAT"; int Arg2 = 2; verify_case(4, Arg2, longestMatch(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "CGCATTAGATTCAGAG"; string Arg1 = "CGCATGAGTAGATTC"; int Arg2 = 7; verify_case(5, Arg2, longestMatch(Arg0, Arg1)); }

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
  DNASingleMatcher ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int DNASingleMatcher :: longestMatch(string sequence1, string sequence2)
{
  for (int len=min((int)(sequence1).size(), (int)(sequence2).size()); len>=0; --len) 
    for (int i=0; i+len<=(int)(sequence1).size(); ++i)
      for (int j=0; j+len<=(int)(sequence2).size(); ++j)
	if (sequence1.substr(i, len)==sequence2.substr(j, len)) return len;
}
