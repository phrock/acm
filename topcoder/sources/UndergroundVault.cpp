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

class UndergroundVault
{ 
public: 
  vector <int> sealOrder(vector <string> rooms);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1","2",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  1,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sealOrder(Arg0)); }
	void test_case_1() { string Arr0[] = {"1","2","3","1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  2,  1,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sealOrder(Arg0)); }
	void test_case_2() { string Arr0[] = {"3,5","2","8","","","6,7","","1,8","4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  1,  3,  4,  6,  8,  7,  5,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sealOrder(Arg0)); }
	void test_case_3() { string Arr0[] = {"1,2","3","3,5","4","",""}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  4,  3,  5,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sealOrder(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  UndergroundVault ___test; 
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

int n;
int g[55][55];

bool connect(int a, int b)
{
  vector<int> visited(n);
  queue<int> q;
  q.push(a);
  visited[a]=1;
  while (!q.empty()) {
    int x=q.front();
    q.pop();
    if (x==b) return true;
    for (int i=0; i<n; ++i)
      if (g[x][i] && !visited[i]) {
	visited[i]=1;
	q.push(i);
      }
  }
  return false;
}

vector <int> UndergroundVault :: sealOrder(vector <string> rooms)
{
  n=(int)(rooms).size();
  memset(g, 0, sizeof(g));
  for (int i=0; i<n; ++i) {
    vector<int> v=splitInt(rooms[i], ",");
    for (int j=0; j<(int)(v).size(); ++j)
      g[i][v[j]]=1;
  }
  #ifdef DEBUG
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) cout<<g[i][j]<<" ";
    cout<<endl;
  }
#endif

  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j) {
      if (!g[i][j]) continue;
      g[i][j]=0;
      #ifdef DEBUG
      cout<<i<<" "<<j<<" "<<connect(0, j)<<endl;
#endif
      if (!connect(0, j)) g[i][j]=1;
    }
  #ifdef DEBUG
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) cout<<g[i][j]<<" ";
    cout<<endl;
  }
#endif
  vector<int> res;
  vector<int> visited(n);
  while (true) {
    #ifdef DEBUG
    print(visited);
#endif
    for (int i=0; i<n; ++i) {
      if (visited[i]) continue;
      bool ok=true;
      for (int j=0; j<n; ++j)
	if (g[i][j] && !visited[j])
	  { ok=false; break; }
      if (ok) { res.push_back(i), visited[i]=1; break; }
    }
    bool ok=true;
    for (int i=0; i<n; ++i)
      if (!visited[i]) { ok=false; break; }
    if (ok) break;
  }

  return res;
}
