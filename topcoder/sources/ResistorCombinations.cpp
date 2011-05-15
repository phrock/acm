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

class ResistorCombinations
{ 
public: 
  double closestValue(vector <string> resistances, double target);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"2","3","5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.5; double Arg2 = 2.5; verify_case(0, Arg2, closestValue(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"2","3","5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1; double Arg2 = 0.967741935483871; verify_case(1, Arg2, closestValue(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10.25","13.31","6.777","12.2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 10.5; double Arg2 = 10.510805181371511; verify_case(2, Arg2, closestValue(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"10000","2000","300","40","5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 20000; double Arg2 = 12345.0; verify_case(3, Arg2, closestValue(Arg0, Arg1)); }
  //	void test_case_4() { string Arr0[] = {"125.10000","00270.9","000625.55","90.100000","0015.60000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 153; double Arg2 = 152.75975812465552; verify_case(4, Arg2, closestValue(Arg0, Arg1)); }
  	void test_case_4() { string Arr0[] = {"999999.00", "999999", "999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 153; double Arg2 = 300000.0; verify_case(4, Arg2, closestValue(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  ResistorCombinations ___test; 
  ___test.run_test(4); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

template<class T> set< vector<T> > getAllSubSet(const vector<T> &v)
{
  set< vector<T> > res;
  vector<T> empty;
  res.insert(empty);
  if (v.empty()) return res;
  T x=*v.begin();
  set< vector<T> > aux=getAllSubSet(vector<T> (v.begin()+1, v.end()));
  for (__typeof((aux).begin()) i=(aux).begin(); i!=(aux).end(); ++i) {
    vector<T> tmp=*i;
    res.insert(tmp);
    tmp.push_back(x);
    sort((tmp).begin(), (tmp).end());
    res.insert(tmp);
  }
  return res;
}

set<double> go(const vector<double> &v, const vector<int> &num)
{
  // print(v);
  if ((int)(num).size()==1) {
    set<double> tmp;
    tmp.insert(v[num[0]]);
    return tmp;
  }
  set<vector<int> > st=getAllSubSet(num);
  // print2(st);
  set<double> res;
  for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i)
    for (__typeof((st).begin()) j=i; j!=(st).end(); ++j) {
      if ((*i).empty() || (*j).empty()) continue;
      vector<int> tmp;
      set_intersection((*i).begin(), (*i).end(), (*j).begin(), (*j).end(), back_inserter(tmp));
      if (!tmp.empty()) continue;
      set<double> a, b;
      a=go(v, *i); b=go(v, *j);
      for (__typeof((a).begin()) p=(a).begin(); p!=(a).end(); ++p)
	for (__typeof((b).begin()) q=(b).begin(); q!=(b).end(); ++q) {
	  double x=*p;
	  double y=*q;
	  res.insert(x+y);
	  res.insert(x*y/(x+y));
	}
    }
  // print(res);
  return res;
}

double ResistorCombinations :: closestValue(vector <string> resistances, double target)
{
  int n=(int)(resistances).size();
  vector<double> v(n);
  for (int i=0; i<n; ++i)
    v[i]=*({stringstream ss; ss<<(resistances[i]); static double r; ss>>r; &r;});
  // print(v);
  vector<int> num(n);
  for (int i=0; i<(int)(num).size(); ++i) num[i]=i;
  set<double> aux=go(v, num);
  // print(aux);
  double res=0;
  double m=INT_MAX;
  for (__typeof((aux).begin()) i=(aux).begin(); i!=(aux).end(); ++i) {
    double tmp=*i-target;
    if (tmp<0) tmp=-tmp;
    if (tmp<m) res=*i, m=tmp;
  }
  return res;
}
