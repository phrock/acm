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

class ScoringEfficiency
{ 
public: 
  double getPointsPerShot(vector <string> gameLog);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Made 3 point field goal",
 "Missed 2 point field goal"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5; verify_case(0, Arg1, getPointsPerShot(Arg0)); }
	void test_case_1() { string Arr0[] = {"Made free throw",
 "Missed free throw",
 "Missed free throw",
 "Missed free throw",
 "Made free throw"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.8; verify_case(1, Arg1, getPointsPerShot(Arg0)); }
	void test_case_2() { string Arr0[] = {"Made 2 point field goal", "Made 2 point field goal", "Made 2 point field goal", 
 "Made 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Made 3 point field goal", "Made 3 point field goal",
 "Missed 3 point field goal", "Missed 3 point field goal", 
 "Missed 3 point field goal", "Missed 3 point field goal",
 "Made free throw", "Made free throw", "Made free throw", 
 "Made free throw", "Made free throw", "Made free throw", 
 "Made free throw", "Missed free throw", "Missed free throw"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.4545454545454546; verify_case(2, Arg1, getPointsPerShot(Arg0)); }
	void test_case_3() { string Arr0[] = {"Made 2 point field goal", "Missed free throw",
 "Made free throw", "Missed free throw", "Made free throw", 
 "Made 2 point field goal", "Made 2 point field goal",
 "Missed 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Missed 2 point field goal",
 "Made 2 point field goal", "Missed 2 point field goal",
 "Made 3 point field goal", "Missed 2 point field goal",
 "Missed 2 point field goal", "Missed 3 point field goal",
 "Made free throw", "Made free throw", 
 "Missed 3 point field goal", "Missed 2 point field goal",
 "Missed 2 point field goal", "Made 2 point field goal",
 "Missed 2 point field goal", "Made 2 point field goal",
 "Missed 3 point field goal"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.9565217391304348; verify_case(3, Arg1, getPointsPerShot(Arg0)); }

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
  ScoringEfficiency ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

double ScoringEfficiency :: getPointsPerShot(vector <string> gameLog)
{
  double x=0, y=0, z=0;
  for (int i=0; i<(int)(gameLog).size(); ++i) {
    if (gameLog[i]=="Made 2 point field goal") x+=2, y++;
    if (gameLog[i]=="Made 3 point field goal") x+=3, y++;
    if (gameLog[i]=="Made free throw") x++, z++;
    if (gameLog[i]=="Missed 2 point field goal" || gameLog[i]=="Missed 3 point field goal") y++;
    if (gameLog[i]=="Missed free throw") z++;
  }
  return x/(y+0.5*z);
}
