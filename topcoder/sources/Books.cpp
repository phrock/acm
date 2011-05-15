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

class Books
{ 
public: 
  int sortMoves(vector <string> titles);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Algorithms", "Purely Functional Data Structures",
"Intro to C", "Automata and Computability"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, sortMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"the fellowship of the ring",
"the return of the king",
"The two towers"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, sortMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"Basic Engineering Circuit Analysis", "A Course in Combinatorics",
"Artificial Intelligence", "Asimovs Guide to Shakespeare",
"The Nature of Space and Time", "A Time for Trumpets",
"Essentials of Artificial Intelligence", "Life by the Numbers",
"Cognitive Psychology", "ColdFusion"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, sortMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"A", "B", "A", "A", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, sortMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"This Book Has No Title", " This Book Does Have A Title"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, sortMoves(Arg0)); }
	void test_case_5() { string Arr0[] = {"What Is The", "What Is The ", "What Is The Title Of This Book"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, sortMoves(Arg0)); }

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
  Books ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

// int Books :: sortMoves(vector <string> titles)
// {
//   vector<string> aux=titles;
//   sort((aux).begin(), (aux).end());
//   vector<int> a;
//   for (int i=0; i<(int)(titles).size(); ++i)
//     a.push_back(find((aux).begin(), (aux).end(), titles[i])-aux.begin());
//   int n=(int)(titles).size();
//   int res=INT_MAX;
//   for (int i=0; i<(1<<n); ++i) {
//     int k=__builtin_popcount(i);
//     if (k>=res) continue;
//     vector<int>  aux;
//     for (int j=0; j<n; ++j) 
//       if (!(i & (1<<j))) aux.push_back(a[j]);
//     vector<int> order=aux;
//     sort((order).begin(), (order).end());
//     if (order==aux) res=k;
//   }
//   return res;
// }

int Books :: sortMoves(vector <string> titles)
{
  int n=(int)(titles).size();
  vector<int> d(n);
  for (int i=0; i<(int)(d).size(); ++i) {
    for (int j=0; j<i; ++j)
      if (titles[j]<=titles[i])
	d[i]=max(d[i], d[j]);
    d[i]++;
  }
  int k=-1;
  for (int i=0; i<(int)(d).size(); ++i) k=max(k, d[i]);
  return n-k;
}
