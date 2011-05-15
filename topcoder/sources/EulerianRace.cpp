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

class EulerianRace
{ 
public: 
  vector <int> planRoute(vector <string> bridges);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "0110000",
  "1001000",
  "1001110",
  "0110011",
  "0010010",
  "0011101",
  "0001010" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  3,  5,  2,  4,  5,  6,  3,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, planRoute(Arg0)); }
	void test_case_1() { string Arr0[] = 
{ "0101000000",
  "1010110000",
  "0101000000",
  "1010000011",
  "0100011100",
  "0100100000",
  "0000100100",
  "0000101000",
  "0001000001",
  "0001000010" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  4,  6,  7,  4,  5,  1,  2,  3,  8,  9,  3,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, planRoute(Arg0)); }
	void test_case_2() { string Arr0[] = { "01111",
  "10111",
  "11011",
  "11101",
  "11110" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  3,  2,  4,  3,  1,  4,  0,  1,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, planRoute(Arg0)); }
	void test_case_3() { string Arr0[] = { "01000000001",
  "10100000000",
  "01010000000",
  "00101000000",
  "00010100000",
  "00001010000",
  "00000101000",
  "00000010100",
  "00000001010",
  "00000000101",
  "10000000010" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, planRoute(Arg0)); }
	void test_case_4() { string Arr0[] = { "00011",
  "00101",
  "01001",
  "10001",
  "11110" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  3,  4,  1,  2,  4,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, planRoute(Arg0)); }
	void test_case_5() { string Arr0[] = {"011111111",
 "101000000",
 "110000000",
 "100010000",
 "100100000",
 "100000100",
 "100001000",
 "100000001",
 "100000010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  7,  8,  0,  5,  6,  0,  3,  4,  0,  1,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, planRoute(Arg0)); }
  	void test_case_6() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  7,  8,  0,  5,  6,  0,  3,  4,  0,  1,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, planRoute(Arg0)); }

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
  EulerianRace ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

// void eulerianLoop(vector<string> &g, int x, vector<int> &res)
// {
//   #ifdef DEBUG
//   cout<<x<<endl;
//   print(g);
//   #endif
//   for (int i=0; i<(int)(g[x]).size(); ++i)
//     if (g[x][i]=='1') g[x][i]=g[i][x]='0', eulerianLoop(g, i, res);
//   res.push_back(x);
// }

vector <int> EulerianRace :: planRoute(vector <string> g)
{
  vector<int> res;

  res.push_back(0);
  while (true) {
    bool ok=false;
    int x;
    for (int i=0; i<(int)(res).size(); ++i) {
      bool ok2=false;
      for (int j=0; j<(int)(g[res[i]]).size(); ++j)
	if (g[res[i]][j]=='1') { ok2=true; break; }
      if (ok2) { ok=true; x=i; break; }
    }
    if (!ok) break;
    vector<int> pre, post, aux;
    for (int i=0; i<x; ++i) pre.push_back(res[i]);
    for (int j=x+1; j<(int)(res).size(); ++j) post.push_back(res[j]);
    aux.push_back(res[x]);
    int tmp=res[x];
    do {
      for (int i=0; i<(int)(g[tmp]).size(); ++i)
	if (g[tmp][i]=='1') {
	  aux.push_back(i);
	  g[tmp][i]=g[i][tmp]='0';
	  tmp=i;
	  break;
	}
    } while (tmp!=res[x]);
    res.clear();
    for (int i=0; i<(int)(pre).size(); ++i) res.push_back(pre[i]);
    for (int i=0; i<(int)(aux).size(); ++i) res.push_back(aux[i]);
    for (int i=0; i<(int)(post).size(); ++i) res.push_back(post[i]);
  }
  return res;
}

  // eulerianLoop(g, 0, res);
  // #ifdef DEBUG
  // print(res);  
  // #endif
  // reverse((res).begin(), (res).end());

