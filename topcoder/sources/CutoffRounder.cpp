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

class CutoffRounder
{ 
public: 
  int round(string num, string cutoff);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "003.656930"; string Arg1 = "0.5000"; int Arg2 = 4; verify_case(0, Arg2, round(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = ".001"; string Arg1 = "0.0001"; int Arg2 = 1; verify_case(1, Arg2, round(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1.99999999"; string Arg1 = "0.9999"; int Arg2 = 2; verify_case(2, Arg2, round(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "135"; string Arg1 = "0.6531"; int Arg2 = 135; verify_case(3, Arg2, round(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "135."; string Arg1 = "0.6531"; int Arg2 = 135; verify_case(4, Arg2, round(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "1356.13671"; string Arg1 = "0.1367"; int Arg2 = 1357; verify_case(5, Arg2, round(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "0.00010001"; string Arg1 = "0.0001"; int Arg2 = 1; verify_case(6, Arg2, round(Arg0, Arg1)); }

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
  CutoffRounder ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 
vector<string> split( const string& s, const string& delim =" " ) {
  vector<string> res;
  string t;
  for ( int i = 0 ; i != (int)s.size() ; i++ ) {
    if ( delim.find( s[i] ) != string::npos ) {
      if ( !t.empty() ) {
	res.push_back( t );
	t = "";
      }
    } else {
      t += s[i];
    }
  }
  if ( !t.empty() ) {
    res.push_back(t);
  }
  return res;
}

int CutoffRounder :: round(string num, string cutoff)
{
  num="0"+num;
  vector<string> v=split(num, ".");
  if (v[0].empty()) v[0]="0";
  if ((int)(v).size()==1) v.push_back("0");
  if (v[1].empty()) v[1]="0";
  v[1]="0."+v[1];
  #ifdef DEBUG
  print(v);  
  #endif
  int res=*({stringstream ss; ss<<(v[0]); static int _; ss>>_; &_;});
  if (v[1]>cutoff) res++;
  return res;
}
