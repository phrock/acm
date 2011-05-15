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


int a[8];
int b[8];

int main()
{
  int n, x, y;
  cin>>n;
  int res=-1;
  for (int i=0; i<n; ++i) {
    cin>>x>>y;
    if (!i) for (int j=0; j<8; ++j) a[j]=x, b[j]=y;
    else {
      for (int j=0; j<8; ++j) {
	int aux=(x-a[j])*(x-a[j])+(y-b[j])*(y-b[j]);
	res=max(res, aux);
      }
      if (x>
}
