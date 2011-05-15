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


struct node {
  int x, y, color;
} board[2*100005];

int t[31];

void build(int a, int b, int k)
{
  board[k].x=a;
  board[k].y=b;
  if (a==b) { board[k].color=1; return; }
  build(a, (a+b)/2, 2*k);
  build((a+b)/2+1, b, 2*k+1);
}

void insert(int a, int b, int color, int k)
{
  if (board[k].x==board[k].y) {
    board[k].color=color;
    return;
  }
  int mid=(board[k].x+board[k].y)/2;
  if (b<=mid) insert(a, b, color, 2*k);
  else if (a>mid) insert(a, b, color, 2*k+1);
  else insert(a, mid, color, 2*k), insert(mid+1, b, color, 2*k+1);
}

void countColor(int a, int b, int k)
{
  if (board[k].x==board[k].y) {
    t[board[k].color]=1;
    return;
  }
  int mid=(board[k].x+board[k].y)/2;
  if (b<=mid) countColor(a, b, 2*k);
  else if (a>mid) countColor(a, b, 2*k+1);
  else countColor(a, mid, 2*k), countColor(mid+1, b, 2*k+1);
}
  

int main()
{
  int L, T, O;
  cin>>L>>T>>O;
  build(1, L, 1);
  for (int i=0; i<O; ++i) {
    char c;
    int a, b, color;
    // cin>>c;
    getchar();
    scanf("%c", &c);
    // cout<<c<<endl;
    if (c=='C') {
      // cin>>a>>b>>color;
      scanf("%d%d%d", &a, &b, &color);
      insert(a, b, color, 1);
    } else {
      // cin>>a>>b;
      scanf("%d%d", &a, &b);
      memset(t, 0, sizeof(t));
      countColor(a, b, 1);
      // cout<<accumulate(t, t+T+1, 0)<<endl;
      printf("%d\n", accumulate(t, t+T+1, 0));
    }
  }
}
