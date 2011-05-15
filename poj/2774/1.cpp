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

const int M=100005;
int d1[M];
int d2[M];

int main()
{
  char s1[M], s2[M];
  scanf("%s", s1);
  scanf("%s", s2);
  int l1=strlen(s1);
  int l2=strlen(s2);
  int res=0;
  for (int i=1; i<=l1; ++i) {
    for (int j=1; j<=l2; ++j)
      if (i%2) {
	if (s1[i-1]==s2[j-1]) d2[j]=d1[j-1]+1, res=max(res, d2[j]);
	else d2[j]=0;
      }
      else {
	if (s1[i-1]==s2[j-1]) d1[j]=d2[j-1]+1, res=max(res, d1[j]);
	else d1[j]=0;
      }
  }
  cout<<res<<endl;
}
