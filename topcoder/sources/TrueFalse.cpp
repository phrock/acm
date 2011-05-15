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

class TrueFalse
{ 
public: 
  string answerKey(vector <string> graded);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "10 TTTTTTTTTTTTTTT", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF", "5 FFFFFFFFFFFFFFF"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TTT"; verify_case(0, Arg1, answerKey(Arg0)); }
	void test_case_1() { string Arr0[] = {"7 TTFFTFT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TTFFTFT"; verify_case(1, Arg1, answerKey(Arg0)); }
	void test_case_2() { string Arr0[] = {"9 TTTFFFFTTFFTTFT",
 "7 FFFFFFFFFFFFFFF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "inconsistent"; verify_case(2, Arg1, answerKey(Arg0)); }
	void test_case_3() { string Arr0[] = {"9 TTTFFFFTTFFTTFT",
 "7 FFFFFFFFFFFFFFF",
 "8 TTTTTTTTTTTTTTT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "FFFFFFFTTTTTTTT"; verify_case(3, Arg1, answerKey(Arg0)); }

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
  TrueFalse ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string TrueFalse :: answerKey(vector <string> graded)
{
  vector<pair<int, string> > v;
  for (int i=0; i<(int)(graded).size(); ++i) {
    stringstream is(graded[i]);
    int x;
    string s;
    is>>x>>s;
    v.push_back(make_pair(x, s));
  }
  int n=(int)(v[0].second).size();
  int m=(int)(graded).size();
  bool ok=false;
  string res;
  res.resize(n);
  for (int i=0; i<(1<<n); ++i) {
    for (int j=0; j<n; ++j) if (i & (1<<j)) res[j]='T'; else res[j]='F';
    reverse((res).begin(), (res).end());
    bool ok2=true;
    vector<int> aux(n);
    for (int j=0; j<m; ++j) {
      int cnt=0;
      for (int k=0; k<n; ++k) if (res[k]==v[j].second[k]) cnt++, aux[k]=1;
      if (cnt!=v[j].first) { ok2=false; break; }
    }
    if (accumulate((aux).begin(), (aux).end(), 0)!=n) ok2=false;
    if (ok2) { ok=true; break; }
  }

  if (ok) return res;
  else return "inconsistent";
}
