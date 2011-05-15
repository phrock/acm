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

class MovieSeating
{ 
public: 
  long long getSeatings(int numFriends, vector <string> hall);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = { ".#..",
  ".##.",
  "...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 34LL; verify_case(0, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "..#",
  ".##",
  "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 16LL; verify_case(1, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = { "..####..", 
  ".###.##.",
  ".######.",
  "#.#.#.#." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; string Arr1[] = { "........" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 40320LL; verify_case(3, Arg2, getSeatings(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  MovieSeating ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

long long ncr[55][55];

long long MovieSeating :: getSeatings(int numFriends, vector <string> hall)
{
  if (numFriends==1) {
    int k=0;
    for (int i=0; i<(int)(hall).size(); ++i)
      for (int j=0; j<(int)(hall[i]).size(); ++j)
	if (hall[i][j]=='.') k++;
    return k;
  }
  long long res=0;
  for (int i=0; i<55; ++i) ncr[i][0]=1;
  for (int i=1; i<55; ++i)
    for (int j=1; j<55; ++j)
      ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
  int n=(int)(hall).size();
  int m=(int)(hall[0]).size();
  for (int i=0; i<n; ++i) {
    int k=0;
    for (int j=0; j<m; ++j)
      if (hall[i][j]=='.') k++;
    res+=ncr[k][numFriends];
  }
  for (int i=0; i<m; ++i) {
    int k=0;
    for (int j=0; j<n; ++j)
      if (hall[j][i]=='.') k++;
    res+=ncr[k][numFriends];
  }
  long long p=1;
  for (long long  i=0; i<numFriends; ++i) p*=(i+1);
  return res*p;
}
