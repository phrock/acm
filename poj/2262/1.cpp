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

bool isPrime(int x)
{
  for (int i=2; i*i<=x; ++i)
    if (x%i==0) return false;
  return true;
}

const int M=1000005;
int prime[M];
vector<int> p;
vector< pair<int, int> > a(M);

int main()
{
  for (int i=2; i*i<M; ++i) {
    if (prime[i]) continue;
    for (int j=i*i; j<M; j+=i) prime[j]=1;
  }
  for (int i=2; i<M; ++i) if (!prime[i]) p.push_back(i);
  // cout<<(int)(p).size()<<endl;
  // for (int i=0; i<(int)(p).size(); ++i)
  //   for (int j=i; j<(int)(p).size(); ++j) {
  //     int x=p[i]+p[j];
  //     if (x>=M) break;
  //     if (p[j]-p[i]>a[x].second-a[x].first) a[x].first=p[i], a[x].second=p[j];
  //   }
  
  int n;
  while (cin>>n) {
    if (!n) break;
    bool ok=false;
    for (int i=0; i<(int)(p).size(); ++i) {
      int x=p[i];
      int y=n-x;
      if (!prime[y]) { ok=true; cout<<n<<" = "<<x<<" + "<<y<<endl; break; }
    }
    if (!ok) cout<<"Goldbach's conjecture is wrong."<<endl;
  }
}
