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

class VolumeGuess
{ 
public: 
  int correctVolume(vector <string> queries, int numberOfBoxes, int ithBox);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1,2,10","1,3,10","2,3,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 10; verify_case(0, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1,02,10","2,3,010","1,3,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 10; verify_case(1, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 31; verify_case(2, Arg3, correctVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 9; verify_case(3, Arg3, correctVolume(Arg0, Arg1, Arg2)); }

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
  VolumeGuess ___test; 
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

// int a[40][3];
// int n;
// int res[10];
// int aux[10];

// bool check(const vector<int> &v)
// {
//   memset(res, -1, sizeof(res));
//   vector<int> t(n);
//   for (int i=0; i<n; ++i) t[v[i]]=i;
//   for (int i=0; i<n*(n-1)/2; ++i) {
//     int k=(t[a[i][0]]>t[a[i][1]])?a[i][0]:a[i][1];
//     if (res[k]==-1) res[k]=a[i][2];
//     else if (res[k]!=a[i][2]) return false;
//   }
//   return true;
// }

// int VolumeGuess :: correctVolume(vector <string> queries, int numberOfBoxes, int ithBox)
// {
//   n=numberOfBoxes;
//   memset(a, 0, sizeof(a));
//   for (int i=0; i<(int)(queries).size(); ++i) {
//     vector<int> v=splitInt(queries[i], ",");
//     a[i][0]=v[0]-1;
//     a[i][1]=v[1]-1;
//     a[i][2]=v[2];
//   }
//   vector<int> v(n);
//   for (int i=0; i<n; ++i) v[i]=i;
//   do {
//     if (check(v)) break;
//   } while (next_permutation((v).begin(), (v).end()));
//   return res[ithBox-1];
// }

int VolumeGuess :: correctVolume(vector <string> queries, int numberOfBoxes, int ithBox)
{
  vector<int> res(numberOfBoxes);
  for (int i=0; i<(int)(queries).size(); ++i) {
    vector<int> v=splitInt(queries[i], ",");
    res[v[0]-1]=max(res[v[0]-1], v[2]);
    res[v[1]-1]=max(res[v[1]-1], v[2]);
  }
  return res[ithBox-1];
}
