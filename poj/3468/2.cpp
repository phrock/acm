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

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif
////////////////////////////////////////////////////////////////////////////////

const int M=100005;
long long v[100005];

struct node {
  int x, y;
  long long value, change;
} tree[M*4];

void build(int x, int y, int idx)
{
  tree[idx].x=x;
  tree[idx].y=y;
  tree[idx].change=0;
  if (x==y) tree[idx].value=v[x];
  else {
    int mid=(x+y)/2, left=2*idx, right=2*idx+1;
    build(x, mid, left);
    build(mid+1, y, right);
    tree[idx].value=tree[left].value+tree[right].value;
  }
}

void update(int x, int y, int idx, long long inc)
{
  if (tree[idx].x==x && tree[idx].y==y) tree[idx].value+=inc;

    int mid=(tree[idx].x+tree[idx].y)/2, left=2*idx, right=2*idx+1;
    if (y<=mid) update(x, y, left, inc);
    else if (x>mid) update(x, y, right, inc);
    else update(x, mid, left, inc), update(mid+1, y, right, inc);
    tree[idx].value=tree[left].value+tree[right].value;

}

long long query(int x, int y, int idx)
{
  if (tree[idx].x==x && tree[idx].y==y) return tree[idx].value;
  else {
    int mid=(tree[idx].x+tree[idx].y)/2, left=2*idx, right=2*idx+1;
    if (y<=mid) return query(x, y, left);
    else if (x>mid) return query(x, y, right);
    else return query(x, mid, left)+query(mid+1, y, right);
  }
}
      

int main()
{
  int N, Q;
  cin>>N>>Q;
  for (int i=1; i<=N; ++i) cin>>v[i];
  build(1, N, 1);
  for (int T=0; T<Q; ++T) {
    char c;
    int x, y;
    cin>>c>>x>>y;
    cout<<c<<" "<<x<<" "<<y<<endl;
    if (c=='C') {
      long long z;
      cin>>z;
      update(x, y, 1, z);
      #ifdef DEBUG
      cout<<query(3, 3, 1)<<endl;
      cout<<query(4, 4, 1)<<endl;
      #endif
    } else {
      cout<<query(x,y, 1)<<endl;
    }
  }
}
