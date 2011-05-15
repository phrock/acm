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

void dfs(pair<int, int> a, pair<int, int> b, vector<string> &path)
{
#ifdef DEBUG
  cout<<a.first<<" "<<a.second<<endl;
  cout<<b.first<<" "<<b.second<<endl;
#endif
  string s;
  if (a.first<b.first) s+='R', a.first++;
  else if (a.first>b.first) s+='L', a.first--;
  if (a.second<b.second) s+='U', a.second++;
  else if (a.second>b.second) s+='D', a.second--;
  if (!s.empty()) { path.push_back(s); dfs(a, b, path); }
}

int main()
{
  string s1, s2;
  cin>>s1>>s2;
  pair<int, int> a, b;
  a.first=s1[0]-'a'; a.second=s1[1]-'1';
  b.first=s2[0]-'a'; b.second=s2[1]-'1';
  vector<string> path;
  dfs(a, b, path);
  cout<<(int)(path).size()<<endl;
  for (int i=0; i<(int)(path).size(); ++i) cout<<path[i]<<endl;
}
