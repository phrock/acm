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
  int n;
  int cnt=0;
  while (cin>>n && n) {
    cout<<"SET "<<++cnt<<endl;
    vector<string> v(n), res(n);
    for (int i=0; i<n; ++i) cin>>v[i];
    int p=0, q=n-1;
    for (int i=0; i<n; ++i)
      if (i%2==0) res[p++]=v[i];
      else res[q--]=v[i];
    for (int i=0; i<(int)(res).size(); ++i) cout<<res[i]<<endl;
  }
}
