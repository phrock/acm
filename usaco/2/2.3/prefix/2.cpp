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

ifstream fin("prefix.in3");
ofstream fout("prefix.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  vector<string> st;
  string aux;
  while (fin>>aux && aux!=".") st.push_back(aux);
  string s;
  while (fin>>aux) s+=aux;
  // cout<<s<<endl;
  int n=(int)(s).size();
  vector<int> dp(n+1);
  dp[0]=1;
  int res=0;
  for (int i=0; i<=n; ++i) {
    if (!dp[i]) continue;
    for (int j=0; j<(int)(st).size(); ++j)
      if (i+(int)(st[j]).size()<=n && s.substr(i, (int)(st[j]).size())==st[j])
	dp[i+(int)(st[j]).size()]=1, res=max(res, i+(int)(st[j]).size());
  }
  fout<<res<<endl;
}
