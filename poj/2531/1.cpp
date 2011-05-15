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
  vector<vector<int> > g(n, vector<int>(n));
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j) cin>>g[i][j];
  int res=0;
  for (int k=0; k<(1<<(n-1)); ++k) {
    int aux=0;
    for (int i=0; i<n; ++i)
      for (int j=i+1; j<n; ++j)
	if (!(k&(1<<i))!=!(k&(1<<j))) aux+=g[i][j];
    res=max(res, aux);
  }
  cout<<res<<endl;
}
