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
  string s;
  while (getline(cin, s)) {
    if (s=="#") break;
    int res=0;
    for (int i=0; i<(int)(s).size(); ++i)
      if (s[i]!=' ') res+=(i+1)*(s[i]-'A'+1);
    cout<<res<<endl;
  }
}
