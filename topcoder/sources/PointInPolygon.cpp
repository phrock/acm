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

class PointInPolygon
{ 
public: 
  string testPoint(vector <string> vertices, int testPointX, int testPointY);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 5; string Arg3 = "INTERIOR"; verify_case(0, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; string Arg3 = "EXTERIOR"; verify_case(1, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 10; string Arg3 = "BOUNDARY"; verify_case(2, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"-100 -90", "-100 100","100 100", "100 -100",
 "-120 -100","-120 100","-130 100","-130 -110",
 "110 -110", "110 110", "-110 110","-110 -90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; string Arg3 = "EXTERIOR"; verify_case(3, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0 0","0 1000","1000 1000","1000 800",
 "200 800","200 600","600 600","600 400",
 "200 400","200 200","1000 200","1000 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 500; string Arg3 = "INTERIOR"; verify_case(4, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0 1000","1000 1000","1000 800",
 "200 800","200 600","600 600","600 400",
 "200 400","200 200","1000 200","1000 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 322; int Arg2 = 333; string Arg3 = "EXTERIOR"; verify_case(5, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"500 0","500 100","400 100","400 200","300 200",
 "300 300","200 300","200 400","100 400","100 500",
 "0 500","0 400","-100 400","-100 300","-200 300",
  "-200 200","-300 200","-300 100","-400 100","-400 0",
  "-500 0","-500 -100","-400 -100","-400 -200","-300 -200",
  "-300 -300","-200 -300","-200 -400","-100 -400","-100 -500",
  "0 -500","0 -400","100 -400","100 -300","200 -300",
  "200 -200","300 -200","300 -100","400 -100","400 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; int Arg2 = 200; string Arg3 = "INTERIOR"; verify_case(6, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {"1 0","2 0","2 1","3 1","3 0","4 0","4 -1","5 -1","5 0",
 "6 0","6 2","0 2","0 3","-1 3","-1 4","0 4","0 6","1 6",
 "1 7","0 7","0 8","-2 8","-2 2","-8 2","-8 0","-7 0",
 "-7 -1","-6 -1","-6 0","-4 0","-4 1","-3 1","-3 0",
 "-2 0","-2 -6","0 -6","0 -5","1 -5","1 -4","0 -4",
 "0 -3","-1 -3","-1 -2","0 -2","0 -1","1 -1"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; string Arg3 = "INTERIOR"; verify_case(7, Arg3, testPoint(Arg0, Arg1, Arg2)); }

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
  PointInPolygon ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 
vector<string> split( const string& s, const string& delim =" " ) {
  vector<string> res;
  string t;
  for ( int i = 0 ; i != (int)s.size() ; i++ ) {
    if ( delim.find( s[i] ) != string::npos ) {
      if ( !t.empty() ) {
	res.push_back( t );
	t = "";
      }
    } else {
      t += s[i];
    }
  }
  if ( !t.empty() ) {
    res.push_back(t);
  }
  return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
  vector<string> tok = split( s, delim );
  vector<int> res;
  for ( int i = 0 ; i != (int)tok.size(); i++ )
    res.push_back( atoi( tok[i].c_str() ) );
  return res;
}

// int cross(int ax, int ay, int bx, int by)
// {
//   return ax*by-ay*bx;
// }

// int check(vector<int> a, vector<int> b, int x, int y)
// {
//   return cross(a[0]-b[0], a[1]-b[1], a[0]-x, a[1]-y);
// }

string PointInPolygon :: testPoint(vector <string> vertices, int testPointX, int testPointY)
{
  int n=(int)(vertices).size();
  int cnt=0;
  for (int i=0; i<n; ++i) {
    int j=(i+1)%n;
    vector<int> a=splitInt(vertices[i]);
    vector<int> b=splitInt(vertices[j]);
    #ifdef DEBUG
    print(a); print(b);
    #endif
    if (testPointX>=min(a[0], b[0]) && testPointX<=max(a[0], b[0]) &&
	testPointY>=min(a[1], b[1]) && testPointY<=max(a[1], b[1])) return "BOUNDARY";
    if (a[1]==b[1]) continue;
    if (a[0]<testPointX && testPointY>=min(a[1], b[1]) && testPointY<max(a[1], b[1])) cnt++;
  }
  if (cnt%2==0) return "EXTERIOR";
  return "INTERIOR";
}
