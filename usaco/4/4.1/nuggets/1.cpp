/*
  ID:   rock2to1
  LANG: C++
  PROG: nuggets
*/

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

ifstream fin("nuggets.in");
ofstream fout("nuggets.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

const int M=65536;
int a[M];

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  int n;
  cin>>n;
  vector<int> v(n);
  for (int i=0; i<n; ++i) cin>>v[i];
  sort((v).begin(), (v).end());
  if (n==1 || v[0]==1) { cout<<0<<endl; return 0; }
  for (int i=0; i<(int)(v).size(); ++i) a[v[i]]=1;
  int res=0;
  for (int i=1; i<M; ++i)
    if (a[i]) for (int j=0; j<(int)(v).size(); ++j) { if (i+v[j]<M) a[i+v[j]]=1; }
    else res=i;;
  cout<<(res==M-1?0:res)<<endl;
}
