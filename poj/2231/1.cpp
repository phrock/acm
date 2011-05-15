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


int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  int n;
  cin>>n;
  vector<long long> v(n);
  for (int i=0; i<n; ++i) cin>>v[i];
  sort((v).begin(), (v).end());
  long long sum=0;
  for (int i=0; i<(int)(v).size(); ++i) sum+=v[i];
  long long res=0;
  for (int i=0; i<n; ++i) {
    sum-=v[i];
    res+=sum-(n-i-1)*v[i];
  }
  cout<<res*2<<endl;
}
