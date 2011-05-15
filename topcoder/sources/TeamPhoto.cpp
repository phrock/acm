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

class TeamPhoto
{ 
public: 
  int minDiff(vector <int> height);
  
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {80,82,81,50,90,65}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 79; verify_case(0, Arg1, minDiff(Arg0)); }
  void test_case_1() { int Arr0[] = {70,82,91,50,50,50,50,50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 113; verify_case(1, Arg1, minDiff(Arg0)); }
  void test_case_2() { int Arr0[] = {13, 17, 11, 12, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minDiff(Arg0)); }

  // END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  TeamPhoto ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

// int n;
// int a[55];
// int b[55];
// int m;

// void dfs(int k, int cnt, const vector<int> &height)
// {
//   // cout<<cnt<<endl;
//   if (cnt>=m) return;
//   if (k==n) { m=min(m, cnt);
//     for (int i=0; i<n; ++i) cout<<a[i]<<" ";
//     cout<<endl;
//     for (int i=0; i<n; ++i) cout<<b[i]<<" ";
//     cout<<endl;
    
//     return; }
//   for (int i=0; i<n; ++i) {
//     if (a[i]!=-1) continue;
//     for (int j=0; j<n; ++j) {
//       if (b[j]) continue;
//       if ((i==0 || i==n-1) && j!=1 && j!=2) continue;
//       int aux=0;
//       if (i>0 && a[i-1]!=-1) aux+=abs(height[j]-height[a[i-1]]);
//       if (i<n-1 && a[i+1]!=-1) aux+=abs(height[j]-height[a[i+1]]);
//       a[i]=j; b[j]=1;
//       dfs(k+1, cnt+aux, height);
//       a[i]=-1; b[j]=0;
//     }
//   }
// }
 
// int TeamPhoto :: minDiff(vector <int> height)
// {
//   n=height.size();
//   memset(a, -1, sizeof(a));
//   memset(b, 0, sizeof(b));
//   int c1=n/2;
//   a[c1]=0;
//   b[0]=1;
//   m=INT_MAX;
//   dfs(1, 0, height);
//   return m;
// }

int TeamPhoto :: minDiff(vector <int> height)
{
  int n=height.size();
  int c1=n/2;
  vector<int> v(height.begin()+3, height.end());
  sort((v).begin(), (v).end());
  int m=v.size();
  vector<int> a1(v.begin(), v.begin()+m/2);
  vector<int> a2(v.begin()+m/2, v.end());
  vector<int> t1, t2;
  t1.push_back(a1.front()); t1.push_back(a1.back());
  t2.push_back(a2.front()); t2.push_back(a2.back());
  int res=INT_MAX;
  int k=0;
  for (unsigned i=1; i<(a1).size(); ++i) k+=a1[i]-a1[i-1];
  for (unsigned i=0; i<(a2).size(); ++i) k+=a2[i]-a2[i-1];
  for (int i=0; i<2; ++i) {
    vector<int> v1, v2;
    if (n%2) {
      v1=i?t1:t2;
      v2=i?t2:t1;
    } else {
      v1=t1;
      v2=t2;
    }
    for (int j=0; j<2; ++j) {
      int x1=j?v1[0]:v1[1];
      int x2=j?v1[1]:v1[0];
      for (int k=0; k<2; ++k) {
	int y1=k?v2[0]:v2[1];
	int y2=k?v2[1]:v2[0];
	res=min(res, abs(x1-height[1])+abs(x2-height[0])+abs(y1-height[0])+abs(y2-height[2]));
      }
    }
  }
  res+=k;
  return res;
    
}
