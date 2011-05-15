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

class Fifteen
{ 
public: 
  string outcome(vector <int> moves);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 5, 9, 6, 8, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 4"; verify_case(0, Arg1, outcome(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 8, 6, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(1, Arg1, outcome(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 4, 7, 6, 9, 8, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 1"; verify_case(2, Arg1, outcome(Arg0)); }
	void test_case_3() { int Arr0[] = {9, 2, 1, 6, 3, 4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 5"; verify_case(3, Arg1, outcome(Arg0)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(4, Arg1, outcome(Arg0)); }
	void test_case_5() { int Arr0[] = {6, 3, 7, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 2"; verify_case(5, Arg1, outcome(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Fifteen ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 
int win(vector<int> &a, int k);
bool check(vector<int> &a, int k)
{
  for (int i=1; i<(int)(a).size(); ++i) {
    if (a[i]!=k) continue;
    for (int j=i+1; j<(int)(a).size(); ++j) {
      if (a[j]!=k) continue;
      for (int t=j+1; t<(int)(a).size(); ++t) {
	if (a[t]!=k) continue;
	if (i+j+t==15) return true;
      }
    }
  }
  bool ok=true;
  for (int i=1; i<(int)(a).size(); ++i)
    if (a[i]) { ok=false; break; }
  if (ok) return k==-1;
  return !win(a, -k);
}

int win(vector<int> &a, int k)
{
  for (int i=1; i<=9; ++i) {
    if (a[i]) continue;
    a[i]=k;
    if (check(a, k)) { a[i]=0; return i; }
    else a[i]=0;
  }
  return 0;
}

string Fifteen :: outcome(vector <int> moves)
{
  vector<int> a(10);
  for (int i=0; i<(int)(moves).size(); ++i)
    if (i%2==0) a[moves[i]]=-1;
    else a[moves[i]]=1;
  int x=win(a, 1);
  string res=x?"WIN "+*({stringstream ss; ss<<(x); static string _; ss>>_; &_;}):"LOSE";
  return res;
}
