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

int a[100005];
int b[100005];

int main()
{
  int n, m;
  cin>>n>>m;
  for (int i=0; i<n; ++i) scanf("%d", &a[i]);
  for (int z=0; z<m; ++z) {
    int i, j, k;
    cin>>i>>j>>k;
    memcpy(b, a+i-1, (j-i+1)*sizeof(int));
    nth_element(b, b+k-1, b+j-i+1);
    #ifdef DEBUG
    print(b, j-i+1);    
    #endif
    cout<<b[k-1]<<endl;
  }
}
