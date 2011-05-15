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

class ColoredStrokes
{ 
public: 
  int getLeast(vector <string> picture);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getLeast(Arg0)); }
	void test_case_1() { string Arr0[] = {"..B.",
 "..B."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLeast(Arg0)); }
	void test_case_2() { string Arr0[] = {".BB."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getLeast(Arg0)); }
	void test_case_3() { string Arr0[] = {"...B..",
 ".BRGRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLeast(Arg0)); }
	void test_case_4() { string Arr0[] = {"...B..",
 ".BRBRR",
 ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, getLeast(Arg0)); }
	void test_case_5() { string Arr0[] = {"GR",
 "BG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, getLeast(Arg0)); }

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
  ColoredStrokes ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 
template<class T> vector<T> split(const string& s, const string& delim =" ") {
  vector<string> aux;
  string t;
  for (int i=0; i!=(int)(s).size(); i++)
    if (delim.find(s[i])!=string::npos) { if (!t.empty()) { aux.push_back(t); t=""; } }
    else t+=s[i];
  if (!t.empty()) aux.push_back(t);
  vector<T> res;
  for (int i=0; i<(int)(aux).size(); ++i)
    res.push_back(*({stringstream ss; ss<<(aux[i]); static T _; ss>>_; &_;}));
  return res;
}

int ColoredStrokes :: getLeast(vector <string> picture)
{
  int n=(int)(picture).size(), m=(int)(picture[0]).size();
  int res=0;
  for (int i=0; i<n; ++i) {
    string s=picture[i];
    for (int j=0; j<(int)(s).size(); ++j)
      if (s[j]!='R' && s[j]!='G') s[j]=' ';
    vector<string> v=split<string>(s);
    res+=(int)(v).size();
  }
  for (int i=0; i<m; ++i) {
    string s;
    for (int j=0; j<n; ++j) s+=picture[j][i];
    for (int j=0; j<(int)(s).size(); ++j)
      if (s[j]!='B' && s[j]!='G') s[j]=' ';
    vector<string> v=split<string>(s);
    res+=(int)(v).size();
  }
  return res;
}
