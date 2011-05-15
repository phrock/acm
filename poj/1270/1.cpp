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

ifstream fin("in");
////////////////////////////////////////////////////////////////////////////////

int a[26];
int v[26];
int ban[50][50];
int res[50];
int n;

void dfs(int cur)
{
  if (cur==n) {
    string s;
    for (int i=0; i<n; ++i) s+=char('a'+res[i]);
    cout<<s<<endl;
    return;
  }
  for (int i=0; i<26; ++i) {
    if (!a[i] || v[i]) continue;
    bool ok=true;
    for (int j=0; j<cur; ++j)
      if (ban[res[j]][i]) { ok=false; break; }
    if (ok) { res[cur]=i; v[i]=1; dfs(cur+1); v[i]=0; }
  }
}
int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  string s1, s2;
  stringstream is;
  while (getline(cin, s1) && getline(cin, s2)) {
    memset(a, 0, sizeof(a));
    memset(ban, 0, sizeof(ban));
    n=0;
    is.clear();
    is.str(s1);
    char tmp, c1, c2;
    while (is>>tmp) a[tmp-'a']=1, n++;
    is.clear();
    is.str(s2);
    while (is>>c1>>c2) ban[c2-'a'][c1-'a']=1;
    dfs(0);
    cout<<endl;
  }   
}
