/*
  ID:   rock2to1
  LANG: C++
  PROG: runround
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

ifstream fin("runround.in");
ofstream fout("runround.out");
////////////////////////////////////////////////////////////////////////////////

int n;
int a[10];
int b[10];

bool check(int x)
{
  memset(b, 0, sizeof(b));
  string s=*({stringstream ss; ss<<(x); static string _; ss>>_; &_;});
  int len=(int)(s).size();
  int cur=0;
  while (true) {
    int aux=s[cur]-'0';
    if (b[aux]) {
      if (cur) return false;
      for (int i=0; i<(int)(s).size(); ++i) if (!b[s[i]-'0']) return false;
      return true;
    }
    b[aux]=1;
    cur=(cur+aux)%len;
  }
}

void dfs(int cur, int len, int aux)
{
  if (cur==len) {
    if (aux>n && check(aux)) {fout<<aux<<endl; exit(0); }
    return;
  }
  for (int i=1; i<=9; ++i)
    if (!a[i]) {
      a[i]=1;
      dfs(cur+1, len, aux*10+i);
      a[i]=0;
    }
}

int main()
{
  // cout<<check(147)<<endl;
  fin>>n;
  for (int i=1; i<=9; ++i) dfs(0, i, 0);
}
