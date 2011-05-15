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

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif
////////////////////////////////////////////////////////////////////////////////

struct node {
  string s;
  int bull, cow;
};

int main()
{
  int n;
  cin>>n;
  vector<node> v(n);
  for (int i=0; i<n; ++i) cin>>v[i].s>>v[i].bull>>v[i].cow;
  int cnt=0;
  string res;
  for (int i=0; i<=9; ++i)
    for (int j=0; j<=9; ++j) {
      if (i==j) continue;
      for (int k=0; k<=9; ++k) {
	if (k==i || k==j) continue;
	for (int l=0; l<=9; ++l) {
	  if (l==i || l==j || l==k) continue;
	  string aux;
	  aux+='0'+i;
	  aux+='0'+j;
	  aux+='0'+k;
	  aux+='0'+l;
	  bool ok=true;
	  for (int p=0; p<n; ++p) {
	    int x=0, y=0;
	    for (int q1=0; q1<4; ++q1) 
	      for (int q2=0; q2<4; ++q2) 
		if (v[p].s[q1]==aux[q2]) {
		  if (q1==q2) x++;
		  else y++;
		}
	    if (x!=v[p].bull || y!=v[p].cow) { ok=false; break; }
	  }
	  if (ok) cnt++, res=aux;
	}
      }
    }
  if (cnt==1) cout<<res<<endl;
  else if (cnt>1) cout<<"Need more data"<<endl;
  else cout<<"Incorrect data"<<endl;
}
