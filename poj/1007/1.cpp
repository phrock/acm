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

ifstream fin("in");
////////////////////////////////////////////////////////////////////////////////

map<string, int> mm;

int count(string s)
{
  int res=0;
  for (int i=0; i<(int)(s).size(); ++i)
    for (int j=i+1; j<(int)(s).size(); ++j)
      if (s[i]>s[j]) res++;
  return res;
}

bool cmp(string a, string b)
{
  return mm[a]<mm[b];
}

int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  int n, dump;
  cin>>dump>>n;
  vector<string> v(n);
  for (int i=0; i<n; ++i) cin>>v[i];
  for (int i=0; i<n; ++i) mm[v[i]]=count(v[i]);
  stable_sort((v).begin(), (v).end(), cmp);
  for (int i=0; i<(int)(v).size(); ++i) cout<<v[i]<<endl;
}
