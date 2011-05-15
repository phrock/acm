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


int main()
{
  char c;
  int start=0;
  for (int i=0; i<4; ++i) 
    for (int j=0; j<5; ++j) {
      c=getchar();
      if (j==4) continue;
      if (c=='+') {
	start^=1<<(i*4+j);
	for (int p=0; p<4; ++p) start^=1<<(i*4+p);
	for (int p=0; p<4; ++p) start^=1<<(p*4+j);
      }
    }
  cout<<__builtin_popcount(start)<<endl;
  for (int i=0; i<16; ++i)
    if (start & (1<<i)) printf("%d %d\n", i/4+1, i%4+1);
}
