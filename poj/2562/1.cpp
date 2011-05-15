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

int addString(string a, string b)
{
  while (!a.empty() && a[0]=='0') a=a.substr(1);
  while (!b.empty() && b[0]=='0') b=b.substr(1);
  reverse((a).begin(), (a).end());
  reverse((b).begin(), (b).end());
  a+="0"; b+="0";
  int n=max((int)(a).size(), (int)(b).size());
  for (int i=0; i<n-(int)(a).size(); ++i) a+="0";
  for (int i=0; i<n-(int)(b).size(); ++i) b+="0";
  int carry=0;
  int cnt=0;
  string res;
  for (int i=0; i<n; ++i) {
    int x=*({stringstream ss; ss<<(a[i]); static int _; ss>>_; &_;});
    int y=*({stringstream ss; ss<<(b[i]); static int _; ss>>_; &_;});
    int z=x+y+carry;
    carry=z>9?1:0;
    if (carry) cnt++;
    z%=10;
    res+=*({stringstream ss; ss<<(z); static string _; ss>>_; &_;});
  }
  reverse((res).begin(), (res).end());
  while ((int)(res).size()>1 && res[0]=='0') res=res.substr(1);
  return cnt;
}


int main()
{
  int a, b;
  while (cin>>a>>b && (a || b)) {
    int res=addString(*({stringstream ss; ss<<(a); static string _; ss>>_; &_;}), *({stringstream ss; ss<<(b); static string _; ss>>_; &_;}));
    if (!res) cout<<"No carry operation."<<endl;
    else cout<<res<<" carry operation."<<endl;
  }
}
