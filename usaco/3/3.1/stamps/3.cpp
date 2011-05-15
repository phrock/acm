/*
  ID:   rock2to1
  LANG: C++
  PROG: stamps
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

ifstream fin("stamps.in");
ofstream fout("stamps.out");
////////////////////////////////////////////////////////////////////////////////
const int M=200*10000+1;
int dp[M];

int main()
{
  int k, n;
  fin>>k>>n;
  vector<int> v(n);
  for (int i=0; i<n; ++i) fin>>v[i];
  sort((v).begin(), (v).end()), (v).erase(unique((v).begin(), (v).end()), (v).end());
  for (int i=1; i<M; ++i) {
    int p=M;
    for (int j=0; j<(int)(v).size(); ++j) {
      if (i<v[j]) break;
      int aux=i-v[j];
      if (!aux || dp[aux]) p=min(p, dp[aux]+1);
    }
    if (p>k) { fout<<i-1<<endl; return 0; }
    dp[i]=p;;
  }
  
}
