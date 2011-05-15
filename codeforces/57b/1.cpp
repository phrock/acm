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
  int a, b, c;
};

int main()
{
  int n, m, k;
  cin>>n>>m>>k;
  vector<node> v(m);
  for (int i=0; i<m; ++i) cin>>v[i].a>>v[i].b>>v[i].c;
  long long res=0;
  for (int i=0; i<k; ++i) {
    int x;
    cin>>x;
    for (int j=0; j<(int)(v).size(); ++j)
      if (x>=v[j].a && x<=v[j].b) res+=x-v[j].a+v[j].c;
  }
  cout<<res<<endl;
}
