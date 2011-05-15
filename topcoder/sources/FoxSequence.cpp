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

class FoxSequence
{ 
public: 
  string isValid(vector <int> seq);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { int Arr0[] = {6,1,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

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
  FoxSequence ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

bool pos(const vector<int> &seq, int x, int y)
{
  int diff=seq[x+1]-seq[x];
  if (diff<=0) return false;
  for (int i=x+1; i<=y; ++i)
    if (seq[i]-seq[i-1]!=diff) return false;
  return true;
}

bool neg(const vector<int> &seq, int x, int y)
{
  int diff=seq[x+1]-seq[x];
  if (diff>=0) return false;
  for (int i=x+1; i<=y; ++i)
    if (seq[i]-seq[i-1]!=diff) return false;
  return true;
}

bool equ(const vector<int> &seq, int x, int y)
{
  for (int i=x; i<=y; ++i)
    if (seq[i]!=seq[x]) return false;
  return true;
}

string FoxSequence :: isValid(vector <int> seq)
{
  int n=(int)(seq).size();
  for (int a=1; a<n-1; ++a) {
    if (!pos(seq, 0, a)) continue;
    for (int b=a+1; b<n-1; ++b) {
      if (!neg(seq, a, b)) continue;
      for (int c=b; c<n-1; ++c) {
	if (!equ(seq, b, c)) continue;
	for (int d=c+1; d<n-1; ++d) {
	  if (pos(seq, c, d) && neg(seq, d, n-1)) return "YES";
	}
      }
    }
  }
  return "NO";
}
