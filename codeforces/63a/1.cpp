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

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
  return a.second<b.second;
}

int main()
{
  int n;
  cin>>n;
  vector<pair<string, int> > v;
  for (int i=0; i<n; ++i) {
    pair<string, int> x;
    string s;
    cin>>x.first>>s;
    if (s=="rat") x.second=0;
    else if (s=="woman" || s=="child") x.second=1;
    else if (s=="man") x.second=2;
    else x.second=3;
    v.push_back(x);
  }
  stable_sort((v).begin(), (v).end(), cmp);
  for (int i=0; i<n; ++i) cout<<v[i].first<<endl;
}
