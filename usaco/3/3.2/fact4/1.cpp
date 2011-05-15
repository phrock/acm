/*
  ID:   rock2to1
  LANG: C++
  PROG: fact4
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

ifstream fin("fact4.in");
ofstream fout("fact4.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  int n;
  fin>>n;
  int m=10000;
  int res=1;
  for (int i=1; i<=n; ++i) {
    res*=i;
    while (res%10==0) res/=10;
    res%=m;
  }
  fout<<res%10<<endl;
}
