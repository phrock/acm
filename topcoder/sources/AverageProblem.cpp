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

class AverageProblem
{ 
public: 
  int numberOfParticipants(vector <string> marks);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0.000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numberOfParticipants(Arg0)); }
	void test_case_1() { string Arr0[] = {"0.500 0.250", "0.125"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, numberOfParticipants(Arg0)); }
	void test_case_2() { string Arr0[] = {"0.500","0.300"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, numberOfParticipants(Arg0)); }
	void test_case_3() { string Arr0[] = {"0.500","0.301"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 106; verify_case(3, Arg1, numberOfParticipants(Arg0)); }

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
  AverageProblem ___test; 
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

int AverageProblem :: numberOfParticipants(vector <string> marks)
{
  vector<int> v;
  for (int i=0; i<(int)(marks).size(); ++i) {
    vector<double> aux=split<double>(marks[i]);
    for (int j=0; j<(int)(aux).size(); ++j) v.push_back(aux[j]*1000+0.5);
  }
  #ifdef DEBUG
  print(v);  
  #endif
  for (int i=1; i<=1000; ++i) {
    bool ok=true;
    for (int j=0; j<(int)(v).size(); ++j) {
      int x=(v[j]*i+999)/1000;
      if (x*1000>=(v[j]+1)*i) { ok=false; break; }
    }
    if (ok) return i;
  }
}
