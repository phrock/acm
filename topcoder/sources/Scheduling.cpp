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

class Scheduling
{ 
public: 
  int fastest(vector <string> dag);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3:","2:","4:","7:0,1,2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, fastest(Arg0)); }
	void test_case_1() { string Arr0[] = {"9:","8:","6:","4:","7:","7:0,1,2,3,4","3:2,3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(1, Arg1, fastest(Arg0)); }
	void test_case_2() { string Arr0[] = { "10:", "5:", "5:1", "5:1", "5:2,3" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, fastest(Arg0)); }
	void test_case_3() { string Arr0[] = {"1:","2:","4:","8:","6:","3:","7:","5:","9:","5:","10:","3:"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(3, Arg1, fastest(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Scheduling ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

vector<string> split( const string& s, const string& delim =" " ) {
  vector<string> res;
  string t;
  for ( int i = 0 ; i != s.size() ; i++ ) {
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

int Scheduling :: fastest(vector <string> dag)
{
  int n=dag.size();
  for (unsigned i=0; i<(dag).size(); ++i)
    for (unsigned j=0; j<(dag[i]).size(); ++j)
      if (dag[i][j]==':' || dag[i][j]==',') dag[i][j]=' ';
  vector<int> time(n);
  vector< vector<int> > g(n);
  for (unsigned i=0; i<(dag).size(); ++i) {
    vector<string> a=split(dag);
    time[i]=*({stringstream ss; ss<<(a[0]); static int r; ss>>r; &r;});
    for (unsigned j=1; j<(a).size(); ++j)
      g[i].push_back(*({stringstream ss; ss<<(a[j]); static int r; ss>>r; &r;}));
  }
  // if (n==1) return time[0];
  vector<int> visited(n);
  int res=0;
  multiset<pair<int, int> > st;
  while (check(visited)) {
    for (unsigned i=0; i<(visited).size(); ++i) {
      if (!visited[i]) {
	bool ok=true;
	for (unsigned j=0; j<(g[i]).size(); ++j) {
	  if (!visited[g[i][j]]) {
	    ok=false;
	    break;
	  }
	}
	if (ok) st.insert(make_pair(time, i));
      }
    }
    int aux=0;
    for (int i=0; i<2; ++i) {
      if (!st.empty());
      pair<int, int> x=*st.begin();
      st.erase(st.begin());
      aux+=x.first;
      if (x.second!=-1) visited[x.second]=1;
    }
    st.insert(make_pair(aux, -1));
  }
}
