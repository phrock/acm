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

class YearProgressbar
{ 
public: 
  double percentage(string currentDate);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "January 01, 2008 00:00"; double Arg1 = 0.0; verify_case(0, Arg1, percentage(Arg0)); }
	void test_case_1() { string Arg0 = "December 31, 2007 23:59"; double Arg1 = 99.99980974124807; verify_case(1, Arg1, percentage(Arg0)); }
	void test_case_2() { string Arg0 = "July 02, 2007 12:00"; double Arg1 = 50.0; verify_case(2, Arg1, percentage(Arg0)); }
	void test_case_3() { string Arg0 = "July 02, 2008 00:00"; double Arg1 = 50.0; verify_case(3, Arg1, percentage(Arg0)); }
	void test_case_4() { string Arg0 = "May 10, 1981 00:31"; double Arg1 = 35.348363774733635; verify_case(4, Arg1, percentage(Arg0)); }
	void test_case_5() { string Arg0 = "January 31, 1900 00:47"; double Arg1 = 8.228120243531203; verify_case(5, Arg1, percentage(Arg0)); }

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
  YearProgressbar ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

double YearProgressbar :: percentage(string currentDate)
{
  string s;;
  int day, year, month, hour, minute;
  for (int i=0; i<(int)(currentDate).size(); ++i) if (currentDate[i]==',' || currentDate[i]==':') currentDate[i]=' ';
  stringstream is(currentDate);
  is>>s>>day>>year>>hour>>minute;
  string sm[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  month=find(sm, sm+12, s)-sm;
  int d[2][12]={ { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
		 { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
  int leap=0;
  if (year%400==0 || (year%4==0 && year%100)) leap=1;
  int total=leap?366:365;
  total*=24*60;
  int elapse=0;
  for (int i=0; i<month; ++i) elapse+=d[leap][i]*24*60;
  elapse+=(day-1)*24*60;
  elapse+=hour*60+minute;
  return 100.*elapse/total;
}
