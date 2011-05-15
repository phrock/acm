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


int main()
{
  int n, k, c;
  cin>>n>>k>>c;
  vector<int> v(c);
  for (int i=0; i<(int)(v).size(); ++i) cin>>v[i];
  int cur=0, res=0, cnt=0;
  for (int i=1; i<=n; ++i) {
    cnt++;
    if (c && i==v[cur]) res++, cur++, cnt=0;
    else if (cnt==k) res++, cnt=0;
  }
  cout<<res<<endl;
}
