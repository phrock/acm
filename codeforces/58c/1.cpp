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
  vector<int> v(n);
  for (int i=0; i<n; ++i) cin>>v[i];
  vector<int> v2=v;
  int k=n/2;
  for (int i=0; i<k; ++i) v[i]-=i;
  if (n%2) v[k]-=k;
  for (int i=0; i<k; ++i) v[n-1-i]-=i;
  #ifdef DEBUG
  print(v);  
  #endif
  map<int, int> mm;
  for (int i=0; i<(int)(v).size(); ++i) {
    bool ok=true;
    if (i<k && v2[i]<=i) ok=false;
    if (i>=k && v2[i]<=n-i-1) ok=false;
    if (ok) mm[v[i]]++;
  }
  #ifdef DEBUG
  printp(mm);  
  #endif
  int aux=0;
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i) aux=max(aux, i->second);
  cout<<n-aux<<endl;
}
