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


void dfs(string s, string &res)
{
  if (s[0]==')') res+="()", dfs(s.substr(1), res);
  if (s[0]==']') res+="[]", dfs(s.substr(1), res);
  if (s[0]=='(') {
    int k=0;
    while (k<(int)(s).size()) if (s[k]==')') break; else k++;
    res+="(";
    if (k<(int)(s).size()) dfs(s.substr(1, k-1), res), res+=")", dfs(s.substr(k+1), res);
    else dfs(s.substr(1), res), res+=")";
  }
  if (s[0]=='[') {
    int k=0;
    while (k<(int)(s).size()) if (s[k]==']') break; else k++;
    res+="[";
    if (k<(int)(s).size()) dfs(s.substr(1, k-1), res), res+="]", dfs(s.substr(k+1), res);
    else dfs(s.substr(1), res), res+="]";
  }
}

int main()
{
  string s, res;
  cin>>s;
  dfs(s, res);
  cout<<res<<endl;
}
