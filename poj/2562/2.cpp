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


int carry(int a, int b)
{
  int res=0;
  int carry=0;
  while (a || b) {
    carry=a%10+b%10+carry>9?1:0;
    if (carry) res++;
    a/=10;
    b/=10;
  }
  return res;
}

int main()
{
  int a, b;
  while (cin>>a>>b && (a || b)) {
    int res=carry(a, b);
    if (!res) cout<<"No carry operation."<<endl;
    else cout<<res<<" carry operation"<<(res==1?".":"s.")<<endl;
  }
}
