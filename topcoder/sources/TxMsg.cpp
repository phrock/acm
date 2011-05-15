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

class TxMsg
{ 
public: 
  string getMessage(string original);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "text message"; string Arg1 = "tx msg"; verify_case(0, Arg1, getMessage(Arg0)); }
	void test_case_1() { string Arg0 = "ps i love u"; string Arg1 = "p i lv u"; verify_case(1, Arg1, getMessage(Arg0)); }
	void test_case_2() { string Arg0 = "please please me"; string Arg1 = "ps ps m"; verify_case(2, Arg1, getMessage(Arg0)); }
	void test_case_3() { string Arg0 = "back to the ussr"; string Arg1 = "bc t t s"; verify_case(3, Arg1, getMessage(Arg0)); }
	void test_case_4() { string Arg0 = "aeiou bcdfghjklmnpqrstvwxyz"; string Arg1 = "aeiou b"; verify_case(4, Arg1, getMessage(Arg0)); }

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
  TxMsg ___test; 
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

bool isVowel(char c)
{
  if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
  return false;
}

string convert(string s)
{
  string res;
  bool ok=true;
  for (int i=0; i<(int)(s).size(); ++i) if (!isVowel(s[i])) { ok=false; break; }
  if (ok) return s;
  for (int i=0; i<(int)(s).size(); ++i)
    if (!isVowel(s[i]) && (!i || isVowel(s[i-1]))) res+=s[i];
  return res;
}

string TxMsg :: getMessage(string original)
{
  vector<string> v=split(original);
  string res;
  for (int i=0; i<(int)(v).size(); ++i) {
    if (i) res+=" ";
    res+=convert(v[i]);
  }
  return res;
}
