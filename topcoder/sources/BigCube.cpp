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

class BigCube
{ 
public: 
  string largestCube(vector <string> range);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1-1000000000001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1000000000000"; verify_case(0, Arg1, largestCube(Arg0)); }
	void test_case_1() { string Arr0[] = {"10-999999999999990","11-999999999999991","12-999999999999992",
 "13-999999999999993","14-999999999999994","15-999999999999995",
 "16-999999999999996","17-999999999999993","18-999999999999994",
 "19-999999999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "999970000299999"; verify_case(1, Arg1, largestCube(Arg0)); }
	void test_case_2() { string Arr0[] = {"0-3","10-20","30-60","80-120"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1"; verify_case(2, Arg1, largestCube(Arg0)); }
	void test_case_3() { string Arr0[] = {"999700030000-999999999999","999400119993-999700029998",
 "999100269974-999400119991","998800479937-999100269972"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(3, Arg1, largestCube(Arg0)); }
	void test_case_4() { string Arr0[] = {"0-0","2-2","3-3","4-4","5-5","6-6","7-7","9-9","10-10","12-12",
 "14-14","16-16","18-18","20-20","22-22","24-24","26-26","28-28",
 "30-30","32-32","34-34","36-36","38-38","40-40","42-42","44-44",
 "46-46","48-48","50-50","52-52","54-54","56-56","58-58","60-60",
 "62-62","65-65","67-67","69-69","71-71","73-73","75-75","77-77",
 "79-79","81-81","83-83","85-85","87-87","89-89","99-99",
  "999970000300000-999999999999999" }
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0"; verify_case(4, Arg1, largestCube(Arg0)); }

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
  BigCube ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string BigCube :: largestCube(vector <string> range)
{
  int n=(int)(range).size();
  vector<pair<long long, long long> > v(n);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<(int)(range[i]).size(); ++j) if (range[i][j]=='-') range[i][j]=' ';
    stringstream is(range[i]);
    long long a, b;
    is>>a>>b;
    v[i].first=a;
    v[i].second=b;
  }
  #ifdef DEBUG
  printp(v);  
  #endif
  long long res=-1;
  for (long long i=0; i<=1e5; ++i) {
    long long x=i*i*i;
    bool ok=false;
    for (int j=0; j<(int)(v).size(); ++j)
      if (x>=v[j].first && x<=v[j].second) { ok=true; break; }
    if (ok) res=x;
  }
  #ifdef DEBUG
  cout<<res<<endl;  
  #endif
  if (res==-1) return "";
  else return *({stringstream ss; ss<<(res); static string _; ss>>_; &_;});
}
