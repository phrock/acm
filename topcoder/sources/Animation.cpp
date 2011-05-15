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

class Animation
{ 
public: 
  vector <string> animate(int speed, string init);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 =  "..R...." ; string Arr2[] = { "..X....",  "....X..",  "......X",  "......." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, animate(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "RR..LRL" ; string Arr2[] = { "XX..XXX",  ".X.XX..",  "X.....X",  "......." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, animate(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arg1 = "LRLR.LRLR"; string Arr2[] = { "XXXX.XXXX",  "X..X.X..X",  ".X.X.X.X.",  ".X.....X.",  "........." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, animate(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; string Arg1 = "RLRLRLRLRL"; string Arr2[] = { "XXXXXXXXXX",  ".........." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, animate(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; string Arg1 = "..."; string Arr2[] = { "..." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, animate(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1; string Arg1 = "LRRL.LR.LRR.R.LRRL."; string Arr2[] = { "XXXX.XX.XXX.X.XXXX.",  "..XXX..X..XX.X..XX.",  ".X.XX.X.X..XX.XX.XX",  "X.X.XX...X.XXXXX..X",  ".X..XXX...X..XX.X..",  "X..X..XX.X.XX.XX.X.",  "..X....XX..XX..XX.X",  ".X.....XXXX..X..XX.",  "X.....X..XX...X..XX",  ".....X..X.XX...X..X",  "....X..X...XX...X..",  "...X..X.....XX...X.",  "..X..X.......XX...X",  ".X..X.........XX...",  "X..X...........XX..",  "..X.............XX.",  ".X...............XX",  "X.................X",  "..................." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, animate(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Animation ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

vector <string> Animation :: animate(int speed, string init)
{
  int n=init.size();
  vector<pair<int, int> > vp(n);
  for (unsigned i=0; i<(init).size(); ++i)
    if (init[i]=='.') vp[i]=make_pair(-1, -1);
    else if (init[i]=='L') vp[i]=make_pair(i, 0);
    else vp[i]=make_pair(i, 1);
  vector<string> res;
  while (true) {
    string s;
    for (int i=0; i<n; ++i) {
      bool ok=false;
      for (int j=0; j<n; ++j)
	if (vp[j].first==i) { ok=true; break; }
      if (ok) s+='X';
      else s+='.';
    }
    res.push_back(s);
    // cout<<s<<endl;
    for (unsigned i=0; i<(vp).size(); ++i)
      if (vp[i].second==0) {
	if (vp[i].first-speed<0) vp[i].first=vp[i].second=-1;
	else vp[i].first=vp[i].first-speed;
      } else if (vp[i].second==1) {
	if (vp[i].first+speed>=n) vp[i].first=vp[i].second=-1;
	else vp[i].first=vp[i].first+speed;
      }
    bool ok=false;
    for (unsigned i=0; i<(s).size(); ++i)
      if (s[i]=='X') { ok=true; break; }
    if (!ok) break;
  }
  return res;
}
