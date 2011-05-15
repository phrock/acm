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

class InstantRunoff
{ 
public: 
  string outcome(string candidates, vector <string> ballots);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABC"; string Arr1[] = {"ACB", "BCA", "ACB", "BCA", "CBA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "B"; verify_case(0, Arg2, outcome(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "DCBA"; string Arr1[] = {"ACBD", "ACBD", "ACBD", "BCAD", "BCAD", "DBCA", "CBDA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "B"; verify_case(1, Arg2, outcome(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ACB"; string Arr1[] = {"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CBA", "CAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(2, Arg2, outcome(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CAB"; string Arr1[] = {"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CAB", "CAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "A"; verify_case(3, Arg2, outcome(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "PSNJTEHOWC"; string Arr1[] = {"EJCNTSHOWP", "SJWNTHECOP", "HSJEWCNTPO", "ETJHSWPOCN", "HPEJTSWNCO", "JCNWOTHSPE", "NHSJCTOPWE", "ENWPTCHJSO", "JESOHCTNWP", "EHJNSOWTPC", "NWJCOEHTPS", "ONPWSHCEJT", "HONCSJPWTE", "JPEOTSNWCH", "NOCTEPSWHJ", "TCHOENSJWP"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Z"; verify_case(4, Arg2, outcome(Arg0, Arg1)); }

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
  InstantRunoff ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string InstantRunoff :: outcome(string candidates, vector <string> ballots)
{
  set<char> st;
  while (true) {
    if ((int)(st).size()==(int)(candidates).size()) return "";
    map<char, int> mm;
    for (int i=0; i<(int)(candidates).size(); ++i)
      if (!((st).find(candidates[i])!=(st).end())) mm[candidates[i]]=0;
    for (int i=0; i<(int)(ballots).size(); ++i)
      for (int j=0; j<(int)(ballots[i]).size(); ++j)
	if (!((st).find(ballots[i][j])!=(st).end())) { mm[ballots[i][j]]++; break; }
    int max=-10000, min=10000;
    char c1=0, c2=0;
    for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i) {
      if (i->second>max) max=i->second, c1=i->first;
      if (i->second<min) min=i->second, c2=i->first;
    }
    if (max*2>(int)(ballots).size()) return *({stringstream ss; ss<<(c1); static string _; ss>>_; &_;});
    for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i)
      if (i->second==min) st.insert(i->first);
  }
}
