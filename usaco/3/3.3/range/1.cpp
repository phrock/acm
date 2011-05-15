/*
  ID:   rock2to1
  LANG: C++
  PROG: range
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

ifstream fin("range.in");
ofstream fout("range.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

int a[251][251];
int b[251][251];

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
  vector<string> v(n);
  for (int i=0; i<n; ++i) cin>>v[i];
  vector<set<int> > st(n+1);
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      if (v[i][j]=='1') a[i][j]=1;

  for (int k=2; k<=n; ++k) {
    memset(b, 0, sizeof(b));
    int cnt=0;
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j) 
	if (i+k-1<n && j+k-1<n) {
	  if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) cnt++, b[i][j]=1;
	}
    if (cnt) cout<<k<<" "<<cnt<<endl;
    memcpy(a, b, sizeof(a));
  }

}
