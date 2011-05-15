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

long long p[20];
long long q[20];

void construct()
{
  p[0]=1;
  for (int i=1; i<20; ++i)
    for (int j=0; j<i; ++j)
      p[i]+=p[j]*p[i-j-1];
  for (int i=1; i<20; ++i)
    q[i]=q[i-1]+p[i];
}  

string func(int n)
{
  int m=1;
  while (q[m]<n) m++;
  n-=q[m-1];
  int left, right;
  for (left=0; left<m; ++left) {
    right=m-left-1;
    if (p[left]*p[right]>=n) break;
    n-=p[left]*p[right];
  }
  string res;
  if (left) res+="("+func((n-1)/p[right]+q[left-1]+1)+")";
  res+="X";
  if (right) res+="("+func((n-1)%p[right]+q[right-1]+1)+")";
  return res;
}

int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  construct();
  int n;
  while (cin>>n && n) {
    cout<<func(n)<<endl;
  }
}
