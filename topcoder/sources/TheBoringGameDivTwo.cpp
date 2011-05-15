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

class TheBoringGameDivTwo
{ 
public: 
  vector <int> find(int scoreJ, int killedJ, int scoreB, int killedB, int scoreF, int killedF);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 2; int Arr6[] = {2, 3 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arr6[] = {0, 0 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 7; int Arg2 = -2; int Arg3 = 5; int Arg4 = 1; int Arg5 = 9; int Arr6[] = { }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 5; int Arg2 = -1; int Arg3 = 4; int Arg4 = 3; int Arg5 = 6; int Arr6[] = {8, 9 }; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

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
  TheBoringGameDivTwo ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int score1, score2, score3, killed1, killed2, killed3;
int res1, res2;
bool ok;


void dfs(int a1, int b1, int a2, int b2, int a3, int b3, int game)
{
  cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<" "<<a3<<" "<<b3<<" "<<"** "<<game<<endl;
  if (a1==score1 && b1==killed1 && a2==score2 && b2==killed2 && a3==score3 && b3==killed3) {
    ok=true;
    res1=min(res1, game); res2=max(res2, game);
    return;
  }
  int na1, nb1, na2, nb2, na3, nb3;
  // na1=a1-1, nb1=b1, na2=a2+1, nb2=b2+2, na3=a3+1, nb3=b3+1;
  // if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  // na1=a1+2, nb1=b1+1, na2=a2-1, nb2=b2, na3=a3+1, nb3=b3+1;
  // if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  // na1=a1+1, nb1=b1, na2=a2+1, nb2=b2+1, na3=a3+1, nb3=b3+2;
  // if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  // na1=a1+1, nb1=b1+1, na2=a2+1, nb2=b2, na3=a3+1, nb3=b3+2;
  // if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  // na1=a1-1, nb1=b1+2, na2=a2-1, nb2=b2+1, na3=a3+1, nb3=b3;
  // if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  // na1=a1-1, nb1=b1+1, na2=a2-1, nb2=b2+2, na3=a3+1, nb3=b3;
  // if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  na1=a1-1, nb1=b1+1, na2=a2, nb2=b2+1, na3=a3+1, nb3=b3;
  if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  na1=a1+1, nb1=b1, na2=a2, nb2=b2; na3=a3, nb3=b3+1;
  if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  na1=a1, nb1=b1+1, na2=a2-1, nb2=b2+1, na3=a3+1, nb3=b3;
  if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  na1=a1, nb1=b1, na2=a2+1, nb2=b2, na3=a3, nb3=b3+1;
  if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  na1=a1, nb1=b1+1, na2=a2+1, nb2=b2, na3=a3+1, nb3=b3+1;
  if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);

  na1=a1+1, nb1=b1, na2=a2, nb2=b2+1, na3=a3+1, nb3=b3+1;
  if (nb1<=killed1 && nb2<=killed2 && nb3<=killed3) dfs(na1, nb1, na2, nb2, na3, nb3, game+1);
}
  

vector <int> TheBoringGameDivTwo :: find(int scoreJ, int killedJ, int scoreB, int killedB, int scoreF, int killedF)
{
  score1=scoreJ, killed1=killedJ, score2=scoreB, killed2=killedB, score3=scoreF, killed3=killedF;
  res1=INT_MAX; res2=INT_MIN;
  ok=false;
  dfs(0, 0, 0, 0, 0, 0, 0);
  vector<int> res;
  if (ok) { res.push_back(res1); res.push_back(res2); }
  return res;
}
