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

class Alliteration
{ 
public: 
  int count(vector <string> words);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"He", "has", "four", "fanatic", "fantastic", "fans"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"There", "may", "be", "no", "alliteration", "in", "a", "sequence"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"Round", "the", "rugged", "rock", "the", "ragged", "rascal", "ran"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }

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
  Alliteration ___test; 
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

int Alliteration :: count(vector <string> words)
{
  // char c='.';
  // int res=0;
  // int cnt=0;
  // for (int i=0; i<(int)(words).size(); ++i) {
  //   char p=tolower(words[i][0]);
  //   if (p==c) { if (!cnt) res++, cnt++; }
  //   else c=p, cnt=0;
  // }
  // return res;
  string s;
  char c='.';
  for (int i=0; i<(int)(words).size(); ++i) {
    char p=tolower(words[i][0]);
    if (p!=c) s+=" ", c=p;
    s+=p;
  }
  vector<string> v=split<string>(s);
  int res=0;
  for (int i=0; i<(int)(v).size(); ++i) if ((int)(v[i]).size()>1) res++;
  #ifdef DEBUG
  print(v);  
  #endif
  return res;
}
