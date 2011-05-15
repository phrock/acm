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

class AlphaDice
{ 
public: 
  int badData(vector <string> roll);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC","ZCB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, badData(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABC","DEF","BCA","GHI","ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, badData(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABA","CDE","CDE","CDE","CDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, badData(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABC","DEF","BCF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, badData(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  AlphaDice ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int a[][3]={ {0, 1, 2}, {0, 2, 4}, {0, 4, 3}, {0, 3, 1},
	     {1, 5, 2}, {2, 5, 4}, {3, 4, 5}, {1, 3, 5} };
vector<vector<int> > r;
bool ok;
int res;

void go(int k, const vector<int> &v)
{
  // print(v);
  if (ok) return;
  res=max(res, k);
  if (k==r.size()) { ok=true; return; }
  for (int i=0; i<8; ++i) {
    vector<int> tmp(a[i], a[i]+3);
    for (int p=0; p<3; ++p) {
      vector<int> t=tmp;
      rotate(t.begin(), t.begin()+p, t.end());
      vector<int> next=v;
      bool ok2=true;
      for (int j=0; j<3; ++j) {
	int x=r[k][j];
	if (((find((next).begin(), (next).end(), x)!=(next).end()) && next[t[j]]==-1) ||
	    (next[t[j]]>=0 && next[t[j]]!=x)) {
	  ok2=false;
	  break;
	}
	next[t[j]]=x;
      }
      if (ok2) go(k+1, next);
    }
  }
}

int AlphaDice :: badData(vector <string> roll)
{
  // r.clear();
  for (unsigned i=0; i<(roll).size(); ++i) {
    vector<int> v;
    for (unsigned j=0; j<(roll[i]).size(); ++j)
      v.push_back(roll[i][j]-'A');
    r.push_back(v);
  }
  // print2(r);
  // print(roll);
  // if (roll[0][0]==roll[0][1] || roll[0][0]==roll[0][2] || roll[0][1]==roll[0][2])
  //   return 0;
  vector<int> v(6, -1);
  res=-1;
  ok=false;
  go(0, v);
  cout<<ok<<endl;
  if (ok) return -1;
  else return res;
}
