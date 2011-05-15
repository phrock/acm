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

class Twain
{ 
public: 
  string getNewSpelling(int year, string phrase);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "i fixed the chrome xerox by the cyclical church"; string Arg2 = "i fiksed the chrome zeroks by the cyclical church"; verify_case(0, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "i fixed the chrome xerox by the cyclical church"; string Arg2 = "i fiksed the chrome zeroks bi the ciclical church"; verify_case(1, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; string Arg1 = "this is unchanged"; string Arg2 = "this is unchanged"; verify_case(2, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; string Arg1 = "sch kn x xschrx cknnchc cyck xxceci"; string Arg2 = "sk n z zskrks nchk sik zksesi"; verify_case(3, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; string Arg1 = "  concoction   convalescence   cyclical   cello   "; string Arg2 = "  konkoktion   konvalesense   siklikal   selo   "; verify_case(4, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 7; string Arg1 = ""; string Arg2 = ""; verify_case(5, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 7; string Arg1 = "cck xzz aaaaa"; string Arg2 = "k z aaaaa"; verify_case(6, Arg2, getNewSpelling(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Twain ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string Twain :: getNewSpelling(int year, string phrase)
{
  if (year<1) goto out;
  {
      if (phrase[0]=='x') phrase[0]='z';
      vector<string> v;
      for (unsigned i=0; i<(phrase).size(); ++i) v.push_back(*({stringstream ss; ss<<(phrase[i]); static string r; ss>>r; &r;}));
      for (unsigned i=0; i<(v).size(); ++i) if (v[i]=="x") v[i]="ks";
      string tmp;
      for (unsigned i=0; i<(v).size(); ++i) tmp+=v[i];
      phrase=tmp;
      if (year<2) goto out;
  }
  {
      for (unsigned i=0; i<(phrase).size(); ++i) if (phrase[i]=='y') phrase[i]='i';
      if (year<3) goto out;
  }
  {
      for (unsigned i=0; i<(phrase).size()-1; ++i)
	if (phrase[i]=='c' && (phrase[i+1]=='e' || phrase[i+1]=='i')) phrase[i]='s';
      if (year<4) goto out;
  }
  {
      while (true) {
	bool ok=true;
	for (unsigned i=0; i<(phrase).size()-1; ++i)
	  if (phrase[i]=='c' && phrase[i+1]=='k') {
	    ok=false;
	    phrase=phrase.substr(0, i)+phrase.substr(i+1);
	    break;
	  }
	if (ok) break;
      }
      if (year<5) goto out;
  }
  
if (phrase.substr(0, 3)=="sch") phrase="sk"+phrase.substr(3);
 out:

}
