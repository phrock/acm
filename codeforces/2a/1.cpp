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
  int n;
  cin>>n;
  string name;
  int x;
  map<string, int> mm;
  vector<pair<string, int> > v;
  for (int i=0; i<n; ++i) {
    cin>>name>>x;
    mm[name]+=x;
    v.push_back(make_pair(name, mm[name]));
  }
  int m=INT_MIN;
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i) 
    m=max(m, i->second);
  set<string> st;
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i)
    if (i->second==m) st.insert(i->first);
  for (int i=0; i<(int)(v).size(); ++i)
    if (((st).find(v[i].first)!=(st).end()) && v[i].second>=m) {
      cout<<v[i].first<<endl;
      return 0;
    }
}
