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
  vector<int> v(n);
  for (int i=0; i<n; ++i) cin>>v[i];
  sort((v).begin(), (v).end());
  long long sum=0, res=0;
  for (long long i=0; i<n; ++i) res+=v[i]*i-sum, sum+=v[i];
  cout<<res*2<<endl;
}
