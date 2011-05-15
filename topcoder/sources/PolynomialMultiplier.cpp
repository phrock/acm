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

class PolynomialMultiplier
{ 
public: 
  string product(string f1, string f2);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1 + x"; string Arg1 = "1 + x"; string Arg2 = "x^2 + 2*x + 1"; verify_case(0, Arg2, product(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "4*x^4 + 1"; string Arg1 = "3*x^5 + 7*x"; string Arg2 = "12*x^9 + 31*x^5 + 7*x"; verify_case(1, Arg2, product(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1 + x + 1 + x"; string Arg1 = "5 + 5"; string Arg2 = "20*x + 20"; verify_case(2, Arg2, product(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "8*x^5"; string Arg1 = "9*x^7"; string Arg2 = "72*x^12"; verify_case(3, Arg2, product(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "5*x^3 + x^4 + 8 + 2*x^6"; string Arg1 = "3*x^5 + 4*x + 7*x^9"; string Arg2 = "14*x^15 + 7*x^13 + 35*x^12 + 6*x^11 + 59*x^9 + 15*x^8 + 8*x^7 + 28*x^5 + 20*x^4 + 32*x"; verify_case(4, Arg2, product(Arg0, Arg1)); }

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
  PolynomialMultiplier ___test; 
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

pair<int, int> parse(string s)
{
  pair<int, int> res;
  if ((int)(s).size()==1) {
    if (isdigit(s[0])) res.first=s[0]-'0', res.second=0;
    else res.first=1, res.second=1;
  } else if ((int)(s).size()==3) {
    if (s.substr(0, 2)=="x^") res.first=1, res.second=s[2]-'0';
    else if (s.substr(1, 2)=="*x") res.first=s[0]-'0', res.second=1;
  } else res.first=s[0]-'0', res.second=s[4]-'0';
  return res;
}

string PolynomialMultiplier :: product(string f1, string f2)
{
  vector<string> v1=split(f1," + "), v2=split(f2, " + ");
  vector<pair<int, int> > a1, a2;
  for (int i=0; i<(int)(v1).size(); ++i) a1.push_back(parse(v1[i]));
  for (int i=0; i<(int)(v2).size(); ++i) a2.push_back(parse(v2[i]));

  map<int, int> mm;
  for (int i=0; i<(int)(a1).size(); ++i)
    for (int j=0; j<(int)(a2).size(); ++j)
      mm[a1[i].second+a2[j].second]+=a1[i].first*a2[j].first;

  vector<pair<int, int> > res;
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i)
    res.push_back(make_pair(i->first, i->second));
  reverse((res).begin(), (res).end());

  string s;
  for (int i=0; i<(int)(res).size(); ++i) {
    if (i) s+=" + ";
    if (!res[i].first) s+=*({stringstream ss; ss<<(res[i].second); static string _; ss>>_; &_;});
    else {
      if (res[i].second>1) s+=*({stringstream ss; ss<<(res[i].second); static string _; ss>>_; &_;})+"*";
      s+="x";
      if (res[i].first>1) s+="^"+*({stringstream ss; ss<<(res[i].first); static string _; ss>>_; &_;});
    }
  }
  return s;
}
