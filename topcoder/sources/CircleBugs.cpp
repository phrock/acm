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

class CircleBugs
{ 
public: 
  int cycleLength(string formation);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRG"; int Arg1 = 1; verify_case(0, Arg1, cycleLength(Arg0)); }
	void test_case_1() { string Arg0 = "RRGRG"; int Arg1 = 3; verify_case(1, Arg1, cycleLength(Arg0)); }
	void test_case_2() { string Arg0 = "RRRRRRRRRR"; int Arg1 = 1; verify_case(2, Arg1, cycleLength(Arg0)); }
	void test_case_3() { string Arg0 = "RGGGGGGGGG"; int Arg1 = 6; verify_case(3, Arg1, cycleLength(Arg0)); }
	void test_case_4() { string Arg0 = "GGRRGGRGRGRRGRRRGGR"; int Arg1 = 511; verify_case(4, Arg1, cycleLength(Arg0)); }
	void test_case_5() { string Arg0 = "RGGGGGGGGGGGGGGGGGGGGGGGGGGGR"; int Arg1 = 16383; verify_case(5, Arg1, cycleLength(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  CircleBugs ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

// int n;
// int mask;
// set<int> rotate(int x)
// {
//   set<int> res;
//   for (int i=0; i<n; ++i) {
//     int y=(x<<i)|(x>>(n-i));
//     y&=mask;
//     // cout<<mask<<" "<<(x<<i)<<" "<<(x>>(n-i))<<" "<<x<<" : "<<y<<endl;
//     res.insert(y);
//   }
//   return res;
// }

// int generate(int x)
// {
//   int res=0;
//   for (int i=0; i<n; ++i) {
//     int p, q;
//     if (!i) p=0, q=n-1;
//     else p=i, q=i-1;
//     res+=(((x>>p)&1)^((x>>q)&1))<<i;
//     // cout<<p<<" "<<q<<":"<<((x>>p)&1)<<" "<<((x>>q)&1)<<" "<<res<<endl;
//   }
//   return res;
// }

// int CircleBugs :: cycleLength(string formation)
// {
//   n=formation.size();
//   mask=(1<<n)-1;
//   int res=0;
//   int aux=0;
//   for (unsigned i=0; i<(formation).size(); ++i) aux<<=1, aux+=formation[i]=='G'?1:0;
//   // cout<<aux<<endl;
//   map<int, int> mm;
//   set<int> st=rotate(aux);
//   // print(st);
//   // cout<<"***"<<endl;
//   for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i) mm[*i]=0;
//   int cnt=0;
//   while (true) {
//     int next=generate(aux);
//     // cout<<aux<<" "<<next<<endl;
//     cnt++;
//     set<int> st=rotate(next);
//     // print(st);
//     bool ok=false;
//     for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i) 
//       if (((mm).find(*i)!=(mm).end())) { ok=true; res=cnt-mm[*i]; break; }
//     if (ok) break;
//     else for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i) mm[*i]=cnt;
//     aux=next;
//   }
//   return res;
// }

string rotate(string s)
{
  string res=s;
  for (unsigned i=0; i<(s).size(); ++i) {
    string tmp=s;
    rotate(tmp.begin(), tmp.begin()+i, tmp.end());
    res=min(res, tmp);
  }
  return res;
}

int CircleBugs :: cycleLength(string formation)
{
  map<string, int> mm;
  string aux=rotate(formation);
  // cout<<aux<<endl;
  mm[aux]=0;
  int cnt=0;
  int res=0;
  while (true) {
    string next;
    for (unsigned i=0; i<(aux).size(); ++i)
      if (!i) next+=aux[i]==aux[aux.size()-1]?'R':'G';
      else next+=aux[i]==aux[i-1]?'R':'G';
    next=rotate(next);
    // cout<<aux<<" "<<next<<endl;
    cnt++;
    if (((mm).find(next)!=(mm).end())) { res=cnt-mm[next]; break; }
    mm[next]=cnt;
    aux=next;
  }
  return res;
}
