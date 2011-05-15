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

class WordForm
{ 
public: 
  string getSequence(string word);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "WHEREABOUTS"; string Arg1 = "CVCVCVC"; verify_case(0, Arg1, getSequence(Arg0)); }
	void test_case_1() { string Arg0 = "yoghurt"; string Arg1 = "CVCVC"; verify_case(1, Arg1, getSequence(Arg0)); }
	void test_case_2() { string Arg0 = "YipPy"; string Arg1 = "CVCV"; verify_case(2, Arg1, getSequence(Arg0)); }
	void test_case_3() { string Arg0 = "AyYyEYye"; string Arg1 = "VCVCVCV"; verify_case(3, Arg1, getSequence(Arg0)); }
	void test_case_4() { string Arg0 = "yC"; string Arg1 = "C"; verify_case(4, Arg1, getSequence(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  WordForm ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string WordForm :: getSequence(string word)
{
  string s="aeiou";
  vector<int> v((int)(word).size());
  for (int i=0; i<(int)(word).size(); ++i) {
    word[i]=tolower(word[i]);
    if ((find((s).begin(), (s).end(), word[i])!=(s).end())) v[i]=1;
    if (i && word[i]=='y' && !v[i-1]) v[i]=1;
  }
  string res;
  for (int i=0; i<(int)(v).size(); ++i) {
    if (!i || v[i]!=v[i-1]) res+=v[i]?'V':'C';
  }
  return res;
}
