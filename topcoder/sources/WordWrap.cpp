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

class WordWrap
{ 
public: 
  vector <string> justify(vector <string> lines, int columnWidth);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"now is the time for all good men",
 "to come to the aid of their country"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; string Arr2[] = { "now is the time for",  "all good men to come",  "to the aid of their",  "country" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, justify(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"now",
 "is the time for",
 "all",
 "good",
 "men",
 "to",
 "come to the aid",
 "of",
 "their",
 "country"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; string Arr2[] = { "now is the time for",  "all good men to come",  "to the aid of their",  "country" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, justify(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"four score and seven years ago", 
 "our fathers brought forth",
 "upon this continent",
 "a new nation",
 "conceived in liberty", 
 "and dedicated to the proposition", 
 "that all men are created",
 "equal"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; string Arr2[] = { "four score and seven years ago our fathers brought",  "forth upon this continent a new nation conceived",  "in liberty and dedicated to the proposition that",  "all men are created equal" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, justify(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"th e ow l an d th e pu ss yc at",
 "we nt to se a",
 "on a be au ti fu l pe a gr ee n bo at"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; string Arr2[] = { "th e",  "ow l",  "an d",  "th e",  "pu",  "ss",  "yc",  "at",  "we",  "nt",  "to",  "se a",  "on a",  "be",  "au",  "ti",  "fu l",  "pe a",  "gr",  "ee n",  "bo",  "at" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, justify(Arg0, Arg1)); }

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
  WordWrap ___test; 
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

vector <string> WordWrap :: justify(vector <string> lines, int columnWidth)
{
  string s;
  for (int i=0; i<(int)(lines).size(); ++i) s+=lines[i]+" ";
  vector<string> v=split(s);
  vector<string> res;
  s=v[0];
  for (int i=1; i<(int)(v).size(); ++i) {
    if ((int)(s).size()+(int)(v[i]).size()+1<=columnWidth) s+=" "+v[i];
    else { res.push_back(s); s=v[i]; }
  }
  res.push_back(s);
  return res;
}
