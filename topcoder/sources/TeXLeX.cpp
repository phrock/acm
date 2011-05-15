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

class TeXLeX
{ 
public: 
  vector <int> getTokens(string input);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "aAbB cd"; int Arr1[] = { 97,  65,  98,  66,  32,  99,  100 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getTokens(Arg0)); }
	void test_case_1() { string Arg0 = "^^ ^^5e"; int Arr1[] = { 96,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getTokens(Arg0)); }
	void test_case_2() { string Arg0 = "^^"; int Arr1[] = { 94,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getTokens(Arg0)); }
	void test_case_3() { string Arg0 = "^^^5e5e"; int Arr1[] = { 30,  53,  101,  53,  101 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getTokens(Arg0)); }
	void test_case_4() { string Arg0 = "^^5e^5e^5e^5e^ abASFs&*^@%#"; int Arr1[] = { 96,  97,  98,  65,  83,  70,  115,  38,  42,  94,  64,  37,  35 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getTokens(Arg0)); }
	void test_case_5() { string Arg0 = "^^5E ^^40"; int Arr1[] = { 117,  69,  32,  64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getTokens(Arg0)); }
	// void test_case_6() { string Arg0 = "^^`2^^^^OC^^c^^xJ^^Dq9GQpe^^)^^i_&_Q<^^@>|AL8^^d^^"; int Arr1[] = { 32,  50,  30,  94,  79,  67,  35,  56,  74,  4,  113,  57,  71,  81,  112,  101,  105,  41,  95,  38,  95,  81,  60,  0,  62,  124,  65,  76,  56,  36,  94,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, getTokens(Arg0)); }
  void test_case_6() { string Arg0 = "rBV^^^^^^30eP@K^^^^:z^^d1%r^^.^^^^^^!J0b^^Ei^^'Gvj"; int Arr1[] = { 32,  50,  30,  94,  79,  67,  35,  56,  74,  4,  113,  57,  71,  81,  112,  101,  105,  41,  95,  38,  95,  81,  60,  0,  62,  124,  65,  76,  56,  36,  94,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, getTokens(Arg0)); }

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
  TeXLeX ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

bool isHex(char c)
{
  if (c>='0' && c<='9' ||
      c>='a' && c<='f')
    return true;
  return false;
}

int hex(char a, char b)
{
  int x=isdigit(a)?a-'0':a-'a'+10;
  int y=isdigit(b)?b-'0':b-'a'+10;
  int z=x*16+y;
  return z;
}

void helper(string s, vector<int> &res)
{
  #ifdef DEBUG
  cout<<s<<endl;
  print(res);  
  #endif
  if (s.empty()) return;
  if (s[0]=='^') {
    if ((int)(s).size()>=4 && s[1]=='^' && isHex(s[2]) && isHex(s[3])) {
      int z=hex(s[2], s[3]);
      if (z==94) helper('^'+s.substr(4), res);
      else { res.push_back(z); helper(s.substr(4), res);}
    } else if ((int)(s).size()>=3 && s[1]=='^') {
      int z=s[2];
      if (z>63) z-=64;
      else z+=64;
      if (z==94) helper('^'+s.substr(3), res);
      else { res.push_back(z); helper(s.substr(3), res);}
    } else {
      res.push_back(94);
      helper(s.substr(1), res);
    }
  } else {
    res.push_back((int)s[0]);
    helper(s.substr(1), res);
  }
}

vector <int> TeXLeX :: getTokens(string s)
{
  vector<int> res;
  helper(s, res);

  return res;
}
