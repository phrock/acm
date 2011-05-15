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

class Removal
{ 
public: 
  int finalPos(int n, int k, vector <string> remove);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 3; string Arr2[] = {"3-4","4-5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(0, Arg3, finalPos(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 13; string Arr2[] = {"19-50","19-50","19-19"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; verify_case(1, Arg3, finalPos(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 39; string Arr2[] = {"19-50","19-50","19-19"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(2, Arg3, finalPos(Arg0, Arg1, Arg2)); }

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
  Removal ___test; 
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

// struct node {
//   int a, b, x, y;
// };

// int Removal :: finalPos(int n, int k, vector <string> remove)
// {
//   node start; start.a=start.x=1; start.b=start.y=n;
//   vector<node> v; v.push_back(start);
//   for (int u=0; u<(int)(remove).size(); ++u) {
//     #ifdef DEBUG
//     for (int i=0; i<(int)(v).size(); ++i)
//       cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].x<<" "<<v[i].y<<endl;
//     cout<<"///////////////"<<endl;
//     #endif
//     vector<int> t=splitInt(remove[u], "-");
//     int p, q;
//     for (int i=0; i<(int)(v).size(); ++i) {
//       if (v[i].a<=t[0] && v[i].b>=t[0]) p=i;
//       if (v[i].a<=t[1] && v[i].b>=t[1]) q=i;
//     }
//     vector<node> aux;
//     for (int i=0; i<p; ++i) aux.push_back(v[i]);
//     node n1; n1.a=v[p].a; n1.b=t[0]-1; n1.x=v[p].x; n1.y=v[p].x+(n1.b-n1.a);
//     if (n1.a<=n1.b) aux.push_back(n1);
//     int z=t[1]-t[0]+1;
// #ifdef DEBUG
//     cout<<"FF<<"<<" "<<z<<" "<<p<<" "<<q<<" "<<t[0]<<" "<<t[1]<<endl;
// #endif
//     node n2; n2.a=n1.b+1; n2.b=v[q].b-z; n2.x=v[q].x+t[1]-v[q].a+1; n2.y=v[q].y;
//     if (n2.a<=n2.b) aux.push_back(n2);
//     for (int i=q+1; i<(int)(v).size(); ++i) {
//       node next=v[i];
//       next.a-=z; next.b-=z;
//       aux.push_back(next);
//     }
//     v=aux;
//   }
//   for (int i=0; i<(int)(v).size(); ++i)
//     if (v[i].a<=k && v[i].b>= k) return k-v[i].a+v[i].x;
//   return -1;
// }

int Removal :: finalPos(int n, int k, vector <string> remove)
{
  long long kk=k;
  for (int i=(int)(remove).size()-1; i>=0; --i) {
    vector<int> v=splitInt(remove[i], "-");
    int z=v[1]-v[0]+1;
    if (v[0]<=kk) {
      kk+=z;
      if (kk>n) return -1;
    }
  }
  return kk;
}
