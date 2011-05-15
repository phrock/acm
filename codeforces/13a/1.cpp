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


int main()
{
  int n, res=0;
  cin>>n;
  for (int i=2; i<n; ++i) {
    int k=n;
    while (k) res+=k%i, k/=i;
    // cout<<i<<" "<<res<<endl;
  }
  n-=2;
  int g=__gcd(n, res);
  cout<<res/g<<"/"<<n/g<<endl;
}
