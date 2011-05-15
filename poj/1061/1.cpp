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
template<class T> inline void gcdxy(T a, T b, T &g, T& x, T& y) { if (!b) { g = a; x = 1; y = 0; } else { gcdxy(b, a%b, g, y, x); y -= x*(a/b); } }

int main()
{
  long long x, y, m, n, L;
  cin>>x>>y>>m>>n>>L;
  m%=L; n%=L;
  if (x>y) swap(x, y), swap(m, n);
  long long dis=m>n?y-x:L-(y-x);
  long long speed=llabs(m-n);
  speed%=L;
  if (!speed) { cout<<"Impossible"<<endl; return 0; }
  long long res=0;
  long long p, q, g;
  gcdxy(speed, L, g, p, q);
  while (p<0) p+=L/g, q-=speed/g;
#ifdef DEBUG
  cout<<speed<<" "<<L<<" "<<dis<<endl;
  cout<<p<<" "<<q<<" "<<g<<endl;
#endif
  if (dis%g) { cout<<"Impossible"<<endl; return 0; }
  res=dis/speed+p*(dis%speed/g);
  cout<<res<<endl;
}
