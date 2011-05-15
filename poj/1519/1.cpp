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

int func(string s)
{
  int res=0;
  for (int i=0; i<(int)(s).size(); ++i) res+=s[i]-'0';
  while (res/10) {
    int aux=res;
    res=0;
    while (aux) res+=aux%10, aux/=10;
  }
  return res;
}

int main()
{
  string s;
  while (cin>>s && s!="0") {
    cout<<func(s)<<endl;
  }
}
