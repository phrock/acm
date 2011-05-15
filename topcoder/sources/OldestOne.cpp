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

class OldestOne
{ 
public: 
  string oldest(vector <string> data);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"DOUG JONES 22 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BOB     A SMITH"; verify_case(0, Arg1, oldest(Arg0)); }
	void test_case_1() { string Arr0[] = {"DOUG JONES 102 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST",
 "A 1 999ELM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DOUG JONES"; verify_case(1, Arg1, oldest(Arg0)); }
	void test_case_2() { string Arr0[] = {"DOUG JONES 122 213 ALDEN LANE","   BOB     A SMITH  102 CLARK ST",
 "A 199 ELM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; verify_case(2, Arg1, oldest(Arg0)); }
	void test_case_3() { string Arr0[] = {"   DOUG                 JONES   122 213 ALDEN LANE",
"   BOB     A SMITH                       102  3",
 " J O H N N Y           199 ELM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "J O H N N Y"; verify_case(3, Arg1, oldest(Arg0)); }

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
  OldestOne ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string OldestOne :: oldest(vector <string> data)
{
  int x=0;
  string res;
  for (int i=0; i<(int)(data).size(); ++i) {
    stringstream is(data[i]);
    string s;
    int age=0;
    while (is>>s) {
      if (isdigit(s[0])) {
	age=*({stringstream ss; ss<<(s); static int _; ss>>_; &_;});
	break;
      }
    }
    #ifdef DEBUG
    cout<<age<<endl;    
    #endif
    if (age>x) {
      x=age;
      int p=data[i].find(s[0]);
      string aux=data[i].substr(0, p);
      #ifdef DEBUG
      cout<<p<<" "<<aux<<" "<<age<<endl;      
      #endif
      int a=0, b=(int)(aux).size()-1;
      while (aux[a]==' ') a++;
      while (aux[b]==' ') b--;
      #ifdef DEBUG
      cout<<a<<" "<<b<<endl;      
      #endif
      res=aux.substr(a, b-a+1);
    }
  }
  return res;
}
