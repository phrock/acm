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


int num[26]={2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
char s[1000];
int v[10000000];

int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  int n;
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    int t=0;
    scanf("%s", s);
    for (unsigned j=0; j<strlen(s); ++j)
      if (isdigit(s[j])) t=t*10+(s[j]-'0');
      else if (isupper(s[j])) t=t*10+num[s[j]-'A'];
    v[t]++;
  }
  bool ok=false;
  for (int i=0; i<10000000; ++i) 
    if (v[i]>1) {
      ok=true;
      printf("%d%d%d-%d%d%d%d %d\n", i/1000000%10, i/100000%10, i/10000%10, i/1000%10, i/100%10, i/10%10, i%10, v[i]);
    }
  if (!ok) cout<<"No duplicates."<<endl;
}

