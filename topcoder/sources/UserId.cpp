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

class UserId
{ 
public: 
  string id(vector <string> inUse, string first, string middle, string last);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bjones","bjones03","bmjones","old34id"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob"; string Arg2 = ""; string Arg3 = "Jones"; string Arg4 = "bjones01"; verify_case(0, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"bjones","bjones03","bmjones","old34id"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 =  "Bob Mack"; string Arg2 = "Hertobise"; string Arg3 = "Jone's" ; string Arg4 = "bhjones"; verify_case(1, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"bjonesto","bjones01","bjonesto","old34id"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BoB-Mack"; string Arg2 = "Mo"; string Arg3 = "Jonestone" ; string Arg4 = "BAD DATA"; verify_case(2, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"momorris","mmmm","momorr01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "'m m"; string Arg2 = ""; string Arg3 = "O'Morrisy"; string Arg4 = "momorr02"; verify_case(3, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"bjonesto", "bjones01", "bmjonest", "old34id"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BoB Mack"; string Arg2 = "Mo"; string Arg3 = "Jonestone"; string Arg4 = "BAD DATApp"; verify_case(4, Arg4, id(Arg0, Arg1, Arg2, Arg3)); }


// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  UserId ___test; 
  ___test.run_test(4); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

bool check(string s)
{
  for (int i=0; i<(s).size(); ++i) {
    char c=s[i];
    if (!(c>='a' && c<='z') &&
	!(c>='A' && c<='Z'))
      return false;
  }
  return true;
}

string UserId :: id(vector <string> inUse, string first, string middle, string last)
{
  bool ok=true;
  string a, b, c;
  for (int i=0; i<(first).size(); ++i)
    if (first[i]!=' ' && first[i] !='\'') a+=first[i];
  for (int i=0; i<(middle).size(); ++i)
    if (middle[i]!=' ' && middle[i]!='\'') b+=middle[i];
  for (int i=0; i<(last).size(); ++i)
    if (last[i]!=' ' && last[i]!='\'') c+=last[i];
  if (!check(a) || !check(b) || !check(c) || (int)a.size()<2 || (int)c.size()<2)
    return "BAD DATA";
  for (int i=0; i<(a).size(); ++i) a[i]=tolower(a[i]);
  for (int i=0; i<(b).size(); ++i) b[i]=tolower(b[i]);
  for (int i=0; i<(c).size(); ++i) c[i]=tolower(c[i]);
  string s=a[0]+c;
  cout<<s<<endl;
  s=s.substr(0, 8);
  cout<<s<<endl;
  if (!(find((inUse).begin(), (inUse).end(), s)!=(inUse).end())) return s;
  if (!b.empty()) {
    s.clear();
    s=s+a[0]+b[0]+c;
    s=s.substr(0, 8);
    cout<<s<<endl;
    if (!(find((inUse).begin(), (inUse).end(), s)!=(inUse).end())) return s;
    cout<<s<<endl;
  } 
    cout<<s<<endl;
    s.clear();
    s=s+a[0]+c;
    cout<<s<<endl;
    cout<<s<<endl;
    s=s.substr(0, 6);
    for (char i='0'; i<='9'; ++i)
      for (char j='1'; j<='9'; ++j) {
	if (!(find((inUse).begin(), (inUse).end(), s+i+j)!=(inUse).end())) return s+i+j;
      }
    
  
}
