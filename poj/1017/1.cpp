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
  while (true) {
    vector<int> v(7, 0);
    for (int i=1; i<=6; ++i) cin>>v[i];
    bool ok=false;
    for (int i=1; i<=6; ++i) if (v[i]) ok=true;
    if (!ok) break;
    int res=0;
    // res+=v[1]/36; v[1]%=36;
    // res+=v[2]/9; v[2]%=9;
    res+=v[3]/4; v[3]%=4;
    res+=v[6];
    if (v[5]>0) { res+=v[5]; v[1]-=min(v[1], v[5]*11); }
    if (v[4]>0) { res+=v[4]; int k=v[4]*20; if (v[2]>0) { int p=min(v[2], k/4); v[2]-=p; k-=p*4; } v[1]-=min(v[1], k); }
    if (v[3]>0) {
      res++;
      int t=0;
      if (v[3]==1) t=5;
      else if (v[3]==2) t=3;
      else t=1;
      int p=0;
      if (v[2]>0) { p=min(v[2], t); v[2]-=p; t-=p; }
      v[1]-=min(v[1], 36-9*v[3]-p*4);
    }
    res+=v[2]/9;
    v[2]%=9;
    if (v[2]>0) {
      res++;
      v[1]-=36-4*v[2];
    }
    res+=(v[1]+35)/36;
    cout<<res<<endl;
  }
}
