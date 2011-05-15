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

class DesertWind
{ 
public: 
  int daysNeeded(vector <string> theMap);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"--*","@-*","X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, daysNeeded(Arg0)); }
	void test_case_1() { string Arr0[] = {"-X-*","-@X-","---X","--**"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, daysNeeded(Arg0)); }
	void test_case_2() { string Arr0[] = {"*--X-----",
 "--XX--@--",
 "*-X------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, daysNeeded(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  DesertWind ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int DesertWind :: daysNeeded(vector <string> theMap)
{
  int n=theMap.size();
  int m=theMap[0].size();
  vector< vector<int> > a(n, vector<int> (m, INT_MAX/2));
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      if (theMap[i][j]=='*') a[i][j]=0;
  cout<<"ff"<<endl;
  while (true) {
    bool ok=true;
    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j) {
	vector<int> v;
	for (int p=-1; p<2; ++p)
	  for (int q=-1; q<2; ++q) {
	    if (i+p>=0 && i+p<n && j+q>=0 && j+q<m &&
		theMap[i+p][j+q]!='X') 
	      v.push_back(a[i+p][j+q]);
	  }
	sort((v).begin(), (v).end());
	int m=INT_MAX;
	if (v.empty()) m=INT_MAX;
	else if (v.size()>=2) m=min(v[0]+3, v[1]+1);
	else m=v[0];
	if (m<a[i][j]) {ok=false; a[i][j]=m;}
      }
    if (ok) break;
  }
  int x, y;
  for (int i=0; i<(theMap).size(); ++i)
    for (int j=0; j<(theMap[i]).size(); ++j)
      if (theMap[i][j]=='@') x=i, y=j;
  int res=a[x][y]==INT_MAX/2?-1:a[x][y];
  return res;
}
