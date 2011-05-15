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

class TreasureHunt
{ 
public: 
  vector <int> findTreasure(vector <string> island, vector <string> instructions);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"..OOOO..",
 ".OOOO...",
 "OOXOOOOO",
 "OOOOOOO.",
 ".OOOO...",
 "..OOO..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"W 3","S 1","E 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".......",
 ".OOOOO.",
 ".OOOOO.",
 ".OOXOO.",
 ".OOOOO.",
 ".OOOOO.",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3,  4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"OOOOOOOOOOO.",
 "OX..........",
 "OOOOOOOOOOO."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"W 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"....OO.",
 "..OOXOO",
 "OOOO...",
 ".OOOOOO",
 "...OOOO",
 ".OOOOO.",
 "..OOO.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N 1","E 1","N 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N 1","E 1","S 1","W 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".................O..",
 "..OO.......OOOOO.O..",
 "..OOO..OOO.OOOOOOOO.",
 "..OOOOOOOOOOOOOOOOO.",
 "..OOOOOOOOOOOOOOOOO.",
 "...OOOOOOOOOOOOOOOO.",
 "OO.OOOOOOOXOOOOOO...",
 ".OOOOOOO..OOOOOOOO..",
 "OOOOOOOOO..OOOOOOOO.",
 "OOOOOOOOO..OOOOOOO..",
 ".OOOOOOOOO..........",
 "OOOOOOOOOOOOOOOOOO..",
 "..OOOOOOOOOOOOOOO...",
 "OOOOOOOOOOOOOOOOO...",
 ".OOOOOOOOOOOOOOOOOOO",
 "OOOOOOOOOOOOOOOOOO..",
 "..OOOOOOOOOOOOOOOOO.",
 "OOOOO.OOOOOO..OOO...",
 "O..OO.OOOO.....OOO..",
 "O......O.OO......OO."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N 2","E 3","N 4","E 2","S 1","W 2","E 9","E 2",
 "N 3","W 5","N 1","W 6","N 6","S 1","S 1","E 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 10,  6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, findTreasure(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  TreasureHunt ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 


bool check(int i, int j, const vector<string> &a)
{
  int n=(int)(a).size();
  int m=(int)(a[0]).size();
  if (i==0 || i==n-1 || j==0 || j==m-1) return true;
  int p[]={-1, 1, 0, 0};
  int q[]={0, 0, -1, 1};
  for (int k=0; k<4; ++k) {
    // cout<<i<<" "<<j<<" "<<i+p[k]<<" "<<j+q[k]<<" "<<a[i+p[k]][j+q[k]]<<"^^^^^"<<endl;
    if (a[i+p[k]][j+q[k]]=='.') return true;
  }
  return false;
}

vector <int> TreasureHunt :: findTreasure(vector <string> island, vector <string> instructions)
{
  int rx, ry;
  for (int i=0; i<(int)(island).size(); ++i)
    for (int j=0; j<(int)(island[i]).size(); ++j)
      if (island[i][j]=='X') { rx=i; ry=j; break; }
  vector< vector<int> > a;
  for (int i=0; i<(int)(instructions).size(); ++i) {
    stringstream is(instructions[i]);
    string s; int x;
    is>>s>>x;
    vector<int> v(2);
    if (s=="W") v[0]=-x;
    if (s=="E") v[0]=x;
    if (s=="N") v[1]=-x;
    if (s=="S") v[1]=x;
    a.push_back(v);
  }
  int dis=INT_MAX;  
  #ifdef DEBUG
  print2(a);
  #endif  
  vector<int> res(2);
  int n=(int)(island).size(), m=(int)(island[0]).size();
  for (int i=0; i<(int)(island).size(); ++i)
    for (int j=0; j<(int)(island[i]).size(); ++j) {
      #ifdef DEBUG
      cout<<i<<j<<"***   "<< endl<<check(i, j, island)<<endl;
      #endif
      if (!check(i, j, island)) continue;
      bool ok=true;
      int pi=i, pj=j;
      for (int k=0; k<(int)(a).size(); ++k) {
	if (!ok) break;
	pi+=a[k][0]; pj+=a[k][1];
	#ifdef DEBUG
	cout<<i<<" "<<j<<" "<<pi<<" "<<pj<<endl;	
	#endif
	if (pi>=0 && pi<n && pj>=0 && pj<m && island[pi][pj]!='.') continue;
	else ok=false;
      }
      if (ok) {
	int tmp=(pi-rx)*(pi-rx)+(pj-ry)*(pj-ry);
	if (tmp<dis) { dis=tmp; res[0]=pi; res[1]=pj; }
      }
    }
  return res;
}
