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
  int n, x1, y1, x2, y2;
  cin>>n>>x1>>y1>>x2>>y2;
  vector<pair<int, int> > v;
  for (int i=0; i<=n; ++i) v.push_back(make_pair(0, i));
  for (int i=1; i<=n; ++i) v.push_back(make_pair(i, n));
  for (int i=n-1; i>=0; --i) v.push_back(make_pair(n, i));
  for (int i=n-1; i>=1; --i) v.push_back(make_pair(i, 0));
  #ifdef DEBUG
  printp(v);  
  #endif
  int p=find((v).begin(), (v).end(), make_pair(x1, y1))-v.begin();
  int q=find((v).begin(), (v).end(), make_pair(x2, y2))-v.begin();
  if (p>q) swap(p, q);
  cout<<min(q-p, p+(int)(v).size()-q)<<endl;
}
