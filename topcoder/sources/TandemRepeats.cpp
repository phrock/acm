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

class TandemRepeats
{ 
public: 
  int maxLength(string dna, int k);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "GATCATCA"; int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "GATCATGA"; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "GATCATGA"; int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AGAGAAAGAA"; int Arg1 = 3; int Arg2 = 5; verify_case(3, Arg2, maxLength(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ATTAGCATTGCACACCTTGAGGACTTAGACAAACCTAGTACACAGGTGTA"; int Arg1 = 5; int Arg2 = 11; verify_case(4, Arg2, maxLength(Arg0, Arg1)); }

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
  TandemRepeats ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

bool check(string s1, string s2, int k)
{
  int cnt=0;
  for (int i=0; i<(int)(s1).size(); ++i)
    if (s1[i]!=s2[i]) { cnt++; if (cnt>k) return false; }
  return true;
}

int TandemRepeats :: maxLength(string dna, int k)
{
  for (int len=(int)(dna).size()/2; len>=0; len--) {
    for (int i=0; i<(int)(dna).size(); ++i) {
      string s1=dna.substr(i, len);
      if ((int)(s1).size()<len) break;
      int j=i+len;
	string s2=dna.substr(j, len);
	if ((int)(s2).size()<len) break;
	if (check(s1, s2, k)) return len;
      
    }
  }
}
