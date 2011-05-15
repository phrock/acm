/*
  ID:   rock2to1
  LANG: C++
  PROG: kimbits
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

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
////////////////////////////////////////////////////////////////////////////////

const int M=35;
long long ncr[M][M];

long long calculate(int k, int p)
{
  long long res=0;
  for (int i=0; i<=p; ++i) res+=ncr[k][i];
  return res;
}

int main()
{
  for (int i=0; i<M; ++i) ncr[i][0]=1;
  for (int i=1; i<M; ++i) for (int j=1; j<M; ++j) ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];

  long long N, L, I;
  fin>>N>>L>>I;
  string res;
  for (int i=0; i<N; ++i) res+="0";
  int p=L;
  while (true) {
    int k=0;
    while (true) {
      long long aux=calculate(k, p);
      if (aux>=I) break;
      k++;
    }
    if (!k) break;
    res[k-1]='1';
    I-=calculate(k-1, p);
    k--; p--;
  }
  reverse((res).begin(), (res).end());
  fout<<res<<endl;
}
