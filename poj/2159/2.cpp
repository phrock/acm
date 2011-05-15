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
  vector<int> v1(26), v2(26);
  for (int i=0; i<(int)(a).size(); ++i) v1[a[i]-'A']++;
  for (int i=0; i<(int)(b).size(); ++i) v2[b[i]-'A']++;
  sort((v1).begin(), (v1).end()); sort((v2).begin(), (v2).end());
  if (v1==v2) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
