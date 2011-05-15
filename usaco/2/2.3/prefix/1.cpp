/*
  ID:   rock2to1
  LANG: C++
  PROG: prefix
*/

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

ifstream fin("prefix.in");
ofstream fout("prefix.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  set<string> st;
  string aux;
  while (fin>>aux && aux!=".") st.insert(aux);
  string s;
  while (fin>>aux) s+=aux;
  // cout<<s<<endl;
  int n=(int)(s).size();
  vector<int> dp(n+1);
  dp[0]=1;
  int res=0;
  for (int i=1; i<=n; ++i) {
    bool ok=false;
    for (int j=0; j<i; ++j) if (dp[j] && ((st).find(s.substr(j, i-j))!=(st).end())) { ok=true; break; }
    if (ok) dp[i]=1, res=i;
  }
  fout<<res<<endl;
}
