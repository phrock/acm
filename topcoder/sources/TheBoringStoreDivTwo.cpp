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

class TheBoringStoreDivTwo
{ 
public: 
  string find(string J, string B);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "StoreOfJohn"; string Arg1 = "StoreOfBrus"; string Arg2 = "or"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "JohnAndJohn"; string Arg1 = "John"; string Arg2 = ""; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "JohnPlaysGames"; string Arg1 = "BrusAlsoPlays"; string Arg2 = "ays"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abacaba"; string Arg1 = "abacabadabacaba"; string Arg2 = "abaabacaba"; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "zzzzzzzzzzzzzzz"; string Arg1 = "zzzzzzzzzzzzzzz"; string Arg2 = "aaaabaaaabab"; verify_case(3, Arg2, find(Arg0, Arg1)); }

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
  TheBoringStoreDivTwo ___test; 
  ___test.run_test(4); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string res;  
string aux;

string TheBoringStoreDivTwo :: find(string J, string B)
{
  aux=res="";
  for (int i=0; i<(int)(J).size(); ++i) {
    for (int len1=1; len1<(int)(J).size(); ++len1) {
      string s1=J.substr(i, len1);
      for (int j=i+len1; j<(int)(J).size(); ++j) {
	for (int len2=1; len2<(int)(J).size(); ++len2) {
	  string s2=J.substr(j, len2);
	  if ((int)(s2).size()<len2) continue;
	  bool ok=true;
	  for (int k=0; k<min(len1, len2); ++k)
	    if (s1[k]!=s2[k]) { ok=false; break; }
	  if (!ok) continue;
	  for (int p=0; p<(int)(B).size(); ++p) {
	    for (int len3=1; len3<(int)(B).size(); ++len3) {
	      string s3=B.substr(p, len3);
	      for (int q=p+len3; q<(int)(B).size(); ++q) {
		for (int len4=1; len4<(int)(B).size(); ++len4) {
		  string s4=B.substr(q, len4);
		  if ((int)(s4).size()<len4) continue;
		  bool ok2=true;
		  for (int k2=0; k2<min(len3, len4); ++k2)
		    if (s3[len3-1-k2]!=s4[len4-1-k2]) { ok2=false; break; }
		  if (!ok2) continue;
		  string z1=s1+s3, z2=s2+s4;
		  if (z1==z2) {
		    if ((int)(z1).size()>(int)(res).size()) res=z1;
		    else if ((int)(z1).size()==(int)(res).size() && z1<res) res=z1;
		  }
		  z1=s1+s4, z2=s2+s3;
		  if (z1==z2) {
		    if ((int)(z1).size()>(int)(res).size()) res=z1;
		    else if ((int)(z1).size()==(int)(res).size() && z1<res) res=z1;
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  return res;
}
