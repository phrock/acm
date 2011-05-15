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

class MineField
{ 
public: 
  vector <string> getMineField(string mineLocations);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "(0,0)(1,0)(2,0)(3,0)(4,0)"; string Arr1[] = { "M20000000",  "M30000000",  "M30000000",  "M30000000",  "M20000000",  "110000000",  "000000000",  "000000000",  "000000000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMineField(Arg0)); }
	void test_case_1() { string Arg0 = "(0,0)(0,8)(8,0)(8,8)"; string Arr1[] = { "M1000001M",  "110000011",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "110000011",  "M1000001M" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMineField(Arg0)); }
	void test_case_2() { string Arg0 = "(3,2)(3,3)(3,4)(4,2)(4,4)(5,2)(5,3)(5,4)(7,4)(6,7)"; string Arr1[] = { "000000000",  "000000000",  "012321000",  "02MMM2000",  "03M8M3000",  "02MMM2111",  "0124321M1",  "0001M1111",  "000111000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMineField(Arg0)); }
	void test_case_3() { string Arg0 = ""; string Arr1[] = { "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMineField(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  MineField ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

vector <string> MineField :: getMineField(string mineLocations)
{
  for (int i=0; i<(int)(mineLocations).size(); ++i)
    if (mineLocations[i]==',' || mineLocations[i]=='(' || mineLocations[i]==')')
      mineLocations[i]=' ';
  stringstream is(mineLocations);
  vector<string> res(9);
  for (int i=0; i<(int)(res).size(); ++i)
    for (int j=0; j<9; ++j) res[i].push_back('0');
  int a, b;
  while (is>>a>>b) res[a][b]='M';
  for (int i=0; i<(int)(res).size(); ++i)
    for (int j=0; j<(int)(res[i]).size(); ++j)
      if (res[i][j]=='M')
	for (int p=-1; p<2; ++p)
	  for (int q=-1; q<2; ++q)
	    if (i+p>=0 && i+p<9 && j+q>=0 && j+q<9 && res[i+p][j+q]!='M') res[i+p][j+q]++;
  return res;
  
		
						 
}
