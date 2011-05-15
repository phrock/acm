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

const int M=1000005;
int p[M];
int main()
{
  p[0]=p[1]=1;
  for (int i=2; i*i<M; ++i) {
    if (p[i]) continue;
    for (int j=i*i; j<M; j+=i) p[j]=1;
  }
  int a, d, n;
  while (cin>>a>>d>>n) {
    if (!n) break;
    while (true) { if (!p[a]) n--; if (!n) break; a+=d; }
    cout<<a<<endl;
  }
}
