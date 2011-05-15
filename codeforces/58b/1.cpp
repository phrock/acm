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
  cin>>n;
  vector<int> v;
  v.push_back(n);
  for (int i=n-1; i>=1; --i) {
    bool ok=true;
    for (int j=0; j<(int)(v).size(); ++j)
      if (v[j]%i) { ok=false; break; }
    if (ok) v.push_back(i);
  }
  for (int i=0; i<(int)(v).size(); ++i) cout<<v[i]<<" ";
  cout<<endl;
}
