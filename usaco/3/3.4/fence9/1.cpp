/*
  ID:   rock2to1
  LANG: C++
  PROG: fence9
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

ifstream fin("fence9.in");
ofstream fout("fence9.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

long long func(long long n, long long m)
{
  long long res=0;
  for (int i=1; i<n; ++i) res+=(m*i-1)/n;
  return res;
}

long long func2(long long n, long long m)
{
  long long res=0;
  for (int i=1; i<n; ++i) res+=(m*i)/n;
  return res;
}

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  long long n, m, p;
  cin>>n>>m>>p;
  long long cnt=func(n, m);
  if (p!=n) {
    if (p>n) { cnt+=func(m, p-n); if (n) cnt+=m-1; }
    else cnt-=func2(m, n-p);
  }
  cout<<cnt<<endl;
  // cout<<func(7, 5)<<endl;
}
