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

////////////////////////////////////////////////////////////////////////////////

int main()
{
  int s, d;
  while (cin>>s>>d) {
    int m=INT_MIN;
    for (int k=1; k<=4; ++k) {
      if (s*(5-k)>=d*k) continue;
      vector<int> v(12);
      for (int i=0; i<8; ++i) {
	int cnt=0;
	for (int j=i; j<i+5; ++j) if (v[j]) cnt++;
	if (cnt<k) {
	  int need=k-cnt;
	  for (int j=i+5-1; j>=0; --j) {
	    if (v[j]) continue;
	    v[j]=1;
	    need--;
	    if (!need) break;
	  }
	}
      }
      int res=0;
      for (int i=0; i<(int)(v).size(); ++i)
	if (v[i]) res-=d; else res+=s;
      m=max(m, res);
    }
    if (m>0) cout<<m<<endl;
    else cout<<"Deficit"<<endl;
  }
}
