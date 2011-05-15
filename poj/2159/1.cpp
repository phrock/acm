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


int main()
{
  string a, b;
  cin>>a>>b;
  map<char, int> m1, m2;
  for (int i=0; i<(int)(a).size(); ++i) m1[a[i]]++;
  for (int i=0; i<(int)(b).size(); ++i) m2[b[i]]++;
  vector<int> p, q;
  for (__typeof((m1).begin()) i=(m1).begin(); i!=(m1).end(); ++i) p.push_back(i->second);
  for (__typeof((m2).begin()) i=(m2).begin(); i!=(m2).end(); ++i) q.push_back(i->second);
  sort((p).begin(), (p).end()); sort((q).begin(), (q).end());
  if (p==q) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
