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

class RangeGame
{ 
public: 
  vector <int> bestDoors(vector <string> possible, vector <string> hints);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1-100","100-200","200-300"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"50-75","250-1000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 100,  200,  100 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, bestDoors(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"100-900 1111","200-800 2222","300-700 3333","4444"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2000-4000","500"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 300,  100,  4444 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, bestDoors(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"346591240","858005279","1321831520","1453846384","1972718383","530431653-1848872872"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1400000000-2000000000","400000000-600000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 858005279,  346591240,  346591240 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, bestDoors(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  RangeGame ___test; 
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

vector<vector< pair<int, int> > > parse(const vector<string> a)
{
  vector<vector< pair<int, int> > > res;
  for (int i=0; i<(int)(a).size(); ++i) {
    vector<string> t=split(a[i]);
    vector< pair<int, int> > aux;
    for (int j=0; j<(int)(t).size(); ++j) {
      vector<int> v=splitInt(t[j], "-");
      if ((int)(v).size()==1) aux.push_back(make_pair(v[0], v[0]));
      else aux.push_back(make_pair(v[0], v[1]));
    }
    res.push_back(aux);
  }
  return res;
}

bool overlap(const vector< pair<int, int> > &a, const vector< pair<int, int> > &b)
{
  for (int i=0; i<(int)(a).size(); ++i)
    for (int j=0; j<(int)(b).size(); ++j)
      if (a[i].second<b[j].first || b[j].second<a[i].first) continue;
      else return true;
  return false;
}

int best(const vector<vector< pair<int, int> > > &a)
{
  map<int, int> mm;
  for (int i=0; i<(int)(a).size(); ++i)
    for (int j=0; j<(int)(a[i]).size(); ++j) 
      for (int p=0; p<(int)(a).size(); ++p)
	for (int q=0; q<(int)(a[p]).size(); ++q)
	  if (!(a[i][j].second<a[p][q].first || a[p][q].second<a[i][j].first))
	    mm[max(a[i][j].first, a[p][q].first)]++;
  int res=-1;
  int cnt=-1;
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i)
    if (i->second>cnt) { cnt=i->second; res=i->first; }
  return res;
}

vector <int> RangeGame :: bestDoors(vector <string> possible, vector <string> hints)
{
  vector<vector< pair<int, int> > > v1=parse(possible);
  vector<vector< pair<int, int> > > v2=parse(hints);
  #ifdef DEBUG
  for (int i=0; i<(int)(v1).size(); ++i) printp(v1[i]);
  #endif
  vector<int> res;
  res.push_back(best(v1));
  for (int i=0; i<(int)(v2).size(); ++i) {
    vector<vector< pair<int, int> > > aux;
    for (int j=0; j<(int)(v1).size(); ++j)
      if (!overlap(v1[j], v2[i])) aux.push_back(v1[j]);
    v1=aux;
    res.push_back(best(v1));
  }
  return res;
}
