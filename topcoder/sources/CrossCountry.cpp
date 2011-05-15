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

class CrossCountry
{ 
public: 
  string scoreMeet(int numTeams, string finishOrder);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 = "AABBABBABBA"; string Arg2 = "AB"; verify_case(0, Arg2, scoreMeet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "CCCBBBBBAAACC"; string Arg2 = "BC"; verify_case(1, Arg2, scoreMeet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arg1 = "ABDCBADBDCCDBCDBCAAAC"; string Arg2 = "BDCA"; verify_case(2, Arg2, scoreMeet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; string Arg1 = "BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG"; string Arg2 = "BCDAHEG"; verify_case(3, Arg2, scoreMeet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; string Arg1 = "BABCAABABAB"; string Arg2 = "AB"; verify_case(4, Arg2, scoreMeet(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  CrossCountry ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

bool cmp(const pair<vector<int> , char > &a, const pair<vector<int> , char > &b)
{
  int x=0;
  for (int i=0; i<5; ++i) x+=a.first[i];
  int y=0;
  for (int i=0; i<5; ++i) y+=b.first[i];
  if (x!=y) return x<y;
  if ((int)(a.first).size()==5 && (int)(b.first).size()==5) return a.second<b.second;
  else if ((int)(a.first).size()==5) return false;
  else if ((int)(b.first).size()==5) return true;
  else return a.first[5]<b.first[5];
}
    

string CrossCountry :: scoreMeet(int numTeams, string finishOrder)
{
  map<char, vector<int> > score;
  for (int i=0; i<(int)(finishOrder).size(); ++i)
    score[finishOrder[i]].push_back(i+1);
  vector<pair<vector<int> , char> > v;
  for (__typeof((score).begin()) i=(score).begin(); i!=(score).end(); ++i) {
    if ((int)(i->second).size()<5) continue;
    // sort((i->second).begin(), (i->second).end());
    v.push_back(make_pair(i->second, i->first));
  }
  sort((v).begin(), (v).end(), cmp);
  string res;
  for (int i=0; i<(int)(v).size(); ++i) res+=v[i].second;
  return res;
}
