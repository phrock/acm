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

long long a[100005];

int main()
{
  int N, Q;
  cin>>N>>Q;
  for (int i=1; i<=N; ++i) cin>>a[i];
  for (int T=0; T<Q; ++T) {
    char c;
    int x, y;
    cin>>c>>x>>y;
    if (c=='C') {
      long long z;
      cin>>z;
      for (int i=x; i<=y; ++i) a[i]+=z;
    } else {
      long long sum=0;
      for (int i=x; i<=y; ++i) sum+=a[i];
      cout<<sum<<endl;
    }
  }
}
