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
} board[100000*5];

void build(int a, int b, int k)
{
  // cout<<k<<endl;
  board[k].x=a;
  board[k].y=b;
  if (a==b) { board[k].color=1<<1; return; }
  build(a, (a+b)/2, 2*k);
  build((a+b)/2+1, b, 2*k+1);
  board[k].color=board[2*k].color|board[2*k+1].color;
}

void insert(int a, int b, int color, int k)
{
  // if (a==board[k].x && b==board[k].y) {
  if (board[k].x==board[k].y) {
    // if (__builtin_popcount(board[k].color)==1) {
      board[k].color=1<<color;
      return;
    // } else board[k].color=1<<color;
  }
  int mid=(board[k].x+board[k].y)/2;
  if (b<=mid) insert(a, b, color, 2*k);
  else if (a>mid) insert(a, b, color, 2*k+1);
  else insert(a, mid, color, 2*k), insert(mid+1, b, color, 2*k+1);
  board[k].color=board[2*k].color|board[2*k+1].color;
}

void checkout(int a, int b, int k, int &res)
{
  if (__builtin_popcount(board[k].color)==1) {
    res|=board[k].color;
    return;
  }
  // if (a==board[k].x && b==board[k].y) {
  //   res|=board[k].color;
  //   return;
  // }
  int mid=(board[k].x+board[k].y)/2;
  if (b<=mid) checkout(a, b, 2*k, res);
  else if (a>mid) checkout(a, b, 2*k+1, res);
  else checkout(a, mid, 2*k, res), checkout(mid+1, b, 2*k+1, res);
}
  

int main()
{
  int L, T, O;
  // cin>>L>>T>>O;
  scanf("%d%d%d", &L, &T, &O);
  build(1, L, 1);
  for (int i=0; i<O; ++i) {
    char c;
    int a, b, color;
    // cin>>c>>a>>b;
    getchar();
    scanf("%c%d%d", &c, &a, &b);
    if (a>b) swap(a, b);
    if (c=='C') {
      // cin>>color;
      scanf("%d", &color);
      insert(a, b, color, 1);
    } else {
      int res=0;
      checkout(a, b, 1, res);
      cout<<__builtin_popcount(res)<<endl;
    }
  }
}
