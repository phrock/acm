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
  string s;
  while (getline(cin, s)) {
    string res;
    int cur=0;
    while (cur<(int)(s).size()) {
      if (s.substr(cur, 3)=="you" && (cur+3==(int)(s).size() || s[cur+3]==' '))
	res+="we", cur+=3;
      else res+=s[cur++];
    }
    cout<<res<<endl;
  }
}
