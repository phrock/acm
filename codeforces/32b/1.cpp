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


int main()
{
  string s, res;
  cin>>s;
  for (int i=0; i<(int)(s).size(); ) {
    if (s[i]=='.') res+="0", i++;
    else {
      if (s[i+1]=='.') res+="1", i+=2;
      else res+="2", i+=2;
    }
  }
  cout<<res<<endl;
}
