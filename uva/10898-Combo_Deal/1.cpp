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

struct node {
  int item[6];
  int price;
};

node p[100];
int dp[11][11][11][11][11][11];

int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  int n;
  while (cin>>n) {
    for (int i=0; i<n; ++i) {
      node aux;
      memset(aux.item, 0, sizeof(aux.item));
      aux.item[i]=1;
      cin>>aux.price;
      p[i]=aux;
    }
    int cnt=n;
    int m;
    cin>>m;
    for (int i=0; i<m; ++i) {
      node aux;
      memset(aux.item, 0, sizeof(aux.item));
      for (int j=0; j<n; ++j) cin>>aux.item[j];
      cin>>aux.price;
      p[cnt++]=aux;
    }
    memset(dp, 100, sizeof(dp));
    dp[0][0][0][0][0][0]=0;
    for (int i=0; i<cnt; ++i) {
      for (int j1=p[i].item[0]; j1<=10; ++j1)
	for (int j2=p[i].item[1]; j2<=10; ++j2)
	  for (int j3=p[i].item[2]; j3<=10; ++j3)
	    for (int j4=p[i].item[3]; j4<=10; ++j4)
	      for (int j5=p[i].item[4]; j5<=10; ++j5)
		for (int j6=p[i].item[5]; j6<=10; ++j6) {
		  // cout<<i<<"  "<<j1<<" "<<j2<<" "<<j3<<" "<<j4<<" "<<j5<<" "<<j6<<endl;
		  int k1=j1-p[i].item[0], k2=j2-p[i].item[1], k3=j3-p[i].item[2], k4=j4-p[i].item[3], k5=j5-p[i].item[4], k6=j6-p[i].item[5];
		  dp[j1][j2][j3][j4][j5][j6]=min(dp[j1][j2][j3][j4][j5][j6], dp[k1][k2][k3][k4][k5][k6]+p[i].price);
		}
    }
    cin>>m;
    int need[6];
    for (int i=0; i<m; ++i) {
      memset(need, 0, sizeof(need));
      for (int j=0; j<n; ++j) cin>>need[j];
      cout<<dp[need[0]][need[1]][need[2]][need[3]][need[4]][need[5]]<<endl;
    }
  }
}
