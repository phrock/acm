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

class WhatSort
{ 
public: 
  string sortType(vector <string> name, vector <int> age, vector <int> wt);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BOB","BOB","DAVE","JOE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] =  {122, 122, 195,  200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "IND"; verify_case(0, Arg3, sortType(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"BOB","BOB","DAVE","DAVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] =  {122, 122, 195,  200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NOT"; verify_case(1, Arg3, sortType(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"BOB","BOB","DAVE","DAVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] =  {22, 35, 35, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {122, 122, 195,  190}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NWA"; verify_case(2, Arg3, sortType(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  WhatSort ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

struct node {
  string name;
  int age;
  int wt;
  bool operator ==(const node &a) const
  {
    if (name==a.name && age==a.age && wt==a.wt) return true;
    else return false;
  }
};
int m;
bool cmp(const node &a, const node &b)
{
  switch (m) {
  case 1:
    if (a.name!=b.name) return a.name<b.name;
    else if (a.age!=b.age) return a.age<b.age;
    else return a.wt>b.wt;
  case 2:
    if (a.name!=b.name) return a.name<b.name;
    else if (a.wt!=b.wt) return a.wt>b.wt;
    else return a.age<b.age;
  case 3:
    if (a.age!=b.age) return a.age<b.age;
    else if (a.name!=b.name) return a.name<b.name;
    else return a.wt>b.wt;
  case 4:
    if (a.age!=b.age) return a.age<b.age;
    else if (a.wt!=b.wt) return a.wt>b.wt;
    return a.name<b.name;
  case 5:
    if (a.wt!=b.wt) return a.wt>b.wt;
    else if (a.age!=b.age) return a.age<b.age;
    return a.name<b.name;
  case 6:
    if (a.wt!=b.wt) return a.wt>b.wt;
    else if (a.name!=b.name) return a.name<b.name;
    else return a.age<b.age;
  }
}
    
string WhatSort :: sortType(vector <string> name, vector <int> age, vector <int> wt)
{
  vector<node> v;
  int n=name.size();
  for (int i=0; i<n; ++i) {
    node x;
    x.name=name[i]; x.age=age[i]; x.wt=wt[i];
    v.push_back(x);
  }
  vector<node> orig=v;
  vector<int> a(7);
  for (int i=1; i<=6; ++i) {
    m=i;
    sort((v).begin(), (v).end(), cmp);
    if (v==orig) a[i]=1;
  }
  int sum=0;
  for (int i=0; i<(a).size(); ++i) sum+=a[i];
  if (!sum) return "NOT";
  else if (sum>1) return "IND";
  else {
    int k=0;
    for (int i=0; i<(a).size(); ++i) if (a[i]) k=i;
    switch (k) {
    case 1: return "NAW";
    case 2: return "NWA";
    case 3: return "ANW";
    case 4: return "AWN";
    case 5: return "WAN";
    case 6: return "WNA";
    }
  }
}
