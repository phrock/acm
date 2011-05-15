/*
  ID:   rock2to1
  LANG: C++
  PROG: rockers
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

ifstream fin("rockers.in");
ofstream fout("rockers.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

int bad[1<<20];
int a[25];

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  int n, t, m;
  cin>>n>>t>>m;
  for (int i=0; i<n; ++i) cin>>a[i];
  int res=0;
  for (int mask=0; mask<(1<<n); ++mask) {
    int k=1;
    bool ok=true;
    while (mask>k) {
      if (bad[mask&k]) { ok=false; break; }
      k=(k<<1)+1;
    }
    if (!ok) { bad[mask]=1; continue; }

    int auxt=t, auxm=m;
    for (int i=0; i<n; ++i) {
      if (mask&(1<<i)) {
	if (a[i]>t) { ok=false; break; }
	if (a[i]<=auxt) auxt-=a[i];
	else { auxt=t-a[i]; auxm--; if (!auxm) { ok=false; break; } }
      }
    }
    if (ok) res=max(res, __builtin_popcount(mask));
    else bad[mask]=1;
  }
  cout<<res<<endl;
}
