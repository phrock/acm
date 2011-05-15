/*
  ID:   rock2to1
  LANG: C++
  PROG: sprime
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

ifstream fin("sprime.in");
ofstream fout("sprime.out");
////////////////////////////////////////////////////////////////////////////////

bool isPrime(int n)
{
  if (n==0 || n==1) return false;
  if (n==2) return true;
  if (n%2==0) return false;
  for (int i=3; i*i<=n; i+=2) if (n%i==0) return false;
  return true;
}

void dfs(int n, int cur, vector<int>& res)
{
  if (!n) { res.push_back(cur); return; }
  for (int i=1; i<10; ++i) {
    int next=cur*10+i;
    if (isPrime(next)) dfs(n-1, next, res);
  }
}

int main()
{
  int n;
  fin>>n;
  vector<int> res;
  dfs(n, 0, res);
  for (int i=0; i<(int)(res).size(); ++i) fout<<res[i]<<endl;
}
