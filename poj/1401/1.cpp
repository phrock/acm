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

////////////////////////////////////////////////////////////////////////////////


int fun(long long x)
{
  int res=0;
  long long k=5;
  while (k<=x) {
    res+=x/k;
    k*=5;
  }
  return res;
}

int main()
{
  int n;
  cin>>n;
  long long x;
  for (int i=0; i<n; ++i) {
    cin>>x;
    cout<<fun(x)<<endl;
  }
}
