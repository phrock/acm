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

class RectangleAvoidingColoringEasy
{ 
public: 
  int count(vector <string> board);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"??",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"B?",
 "?B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"WW",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
  void test_case_3() { string Arr0[] = {"??????????","??????????","??????????","??????????","??????????","??????????","??????????","??????????","??????????","??????????",}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, count(Arg0)); }

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
  RectangleAvoidingColoringEasy ___test; 
  ___test.run_test(3); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

vector<string> g;
int cnt, n, m;;
void dfs(int cur)
{
  // print(g);
  if (cur==(n*m)) {cnt++; return;}
  int a=cur/m;
  int b=cur%m;
  if (g[a][b]!='?') {
    bool ok=true;
    for (int i=0; i<a; ++i) {
      if (!ok) break;
      for (int j=0; j<b; ++j)  {
	if (!ok) break;
	if (g[i][j]==g[i][b] && g[i][b]==g[a][j] && g[a][j]==g[a][b]) { ok=false; break; }
      }
    }
    if (ok) dfs(cur+1);
  }
  else {
    g[a][b]='B';
    bool ok=true;
    for (int i=0; i<a; ++i) {
      if (!ok) break;
      for (int j=0; j<b; ++j)  {
	if (!ok) break;
	if (g[i][j]==g[i][b] && g[i][b]==g[a][j] && g[a][j]==g[a][b]) { ok=false; break; }
      }
    }
    if (ok) dfs(cur+1);
    g[a][b]='W';
    ok=true;
    for (int i=0; i<a; ++i) {
      if (!ok) break;
      for (int j=0; j<b; ++j)  {
	if (!ok) break;
	if (g[i][j]==g[i][b] && g[i][b]==g[a][j] && g[a][j]==g[a][b]) { ok=false; break; }
      }
    }
    if (ok) dfs(cur+1);
    g[a][b]='?';
  }
}

int RectangleAvoidingColoringEasy :: count(vector <string> board)
{
  g=board;
  n=(int)(board).size();
  m=(int)(board[0]).size();
  for (int i=0; i<n-1; ++i)
    for (int j=i+1; j<n; ++j)
      for (int p=0; p<m-1; ++p)
	for (int q=p+1; q<m; ++q) {
	  char c1=board[i][p], c2=board[i][q], c3=board[j][p], c4=board[j][q];
	  if (c1!='?' && c1==c2 && c2==c3 && c3==c4) { return 0; }
	}
  cnt=0;
  dfs(0);
  return cnt;
}
