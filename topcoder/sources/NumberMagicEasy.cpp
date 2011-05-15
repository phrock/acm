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

class NumberMagicEasy
{ 
public: 
  int theNumber(string answer);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYY"; int Arg1 = 5; verify_case(0, Arg1, theNumber(Arg0)); }
	void test_case_1() { string Arg0 = "YNNN"; int Arg1 = 8; verify_case(1, Arg1, theNumber(Arg0)); }
	void test_case_2() { string Arg0 = "NNNN"; int Arg1 = 16; verify_case(2, Arg1, theNumber(Arg0)); }
	void test_case_3() { string Arg0 = "YYYY"; int Arg1 = 1; verify_case(3, Arg1, theNumber(Arg0)); }
	void test_case_4() { string Arg0 = "NYNY"; int Arg1 = 11; verify_case(4, Arg1, theNumber(Arg0)); }

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
  NumberMagicEasy ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int NumberMagicEasy :: theNumber(string answer)
{
  int a[4][8]={{1, 2, 3, 4, 5, 6, 7, 8}
	       ,{1, 2, 3, 4, 9, 10, 11, 12}
	       ,{1, 2, 5, 6, 9, 10, 13, 14}
	       ,{1, 3, 5, 7, 9, 11, 13, 15} };
  for (int i=1; i<16; ++i) {
    int ok=true;
    for (int j=0; j<(int)(answer).size(); ++j) {
      bool found=false;
      for (int k=0; k<8; ++k)
	if (a[j][k]==i) found=true;
      if (answer[j]=='N' && found==true) ok=false;
      if (answer[j]=='Y' && found==false) ok=false;
    }
    if (ok) return i;
  }
  return 16;
}
