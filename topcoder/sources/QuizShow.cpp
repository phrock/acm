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

class QuizShow
{ 
public: 
  int wager(vector <int> scores, int wager1, int wager2);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 100, 100, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; int Arg2 = 75; int Arg3 = 76; verify_case(0, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 10, 50, 60 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 41; int Arg3 = 0; verify_case(1, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 10, 50, 60 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; int Arg2 = 41; int Arg3 = 10; verify_case(2, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 2, 2, 12 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 10; int Arg3 = 1; verify_case(3, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 10000, 10000, 10000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9998; int Arg2 = 9997; int Arg3 = 9999; verify_case(4, Arg3, wager(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = { 5824, 4952, 6230 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 364; int Arg2 = 287; int Arg3 = 694; verify_case(5, Arg3, wager(Arg0, Arg1, Arg2)); }

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
  QuizShow ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int QuizShow :: wager(vector <int> scores, int wager1, int wager2)
{
  vector<int> wager(3);
  wager[1]=wager1, wager[2]=wager2;
  double p=-1, res=0;
  for (wager[0]=0; wager[0]<=scores[0]; ++wager[0]) {
    int cnt=0;
    for (int k=0; k<8; ++k) {
      vector<int> aux=scores;
      for (int i=0; i<3; ++i)
	if (k&(1<<i)) aux[i]+=wager[i];
	else aux[i]-=wager[i];
      if (aux[0]>aux[1] && aux[0]>aux[2]) cnt++;
    }
    if (cnt/8.0>p) p=cnt/8.0, res=wager[0];
    // cout<<wager[0]<<" "<<p<<" "<<cnt<<endl;
  }
  return res;
}
