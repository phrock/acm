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

double helper(double x)
{
  return round(x*10)/10;
}

int main()
{
  string s;
  while (getline(cin, s)) {
    if (s=="E") break;
    double T, D, H, h, e, x, y;
    T=D=H=INT_MAX;
    stringstream is(s);
    string a, b;
    is>>a>>x>>b>>y;
    if (a=="T") T=x;
    if (a=="D") D=x;
    if (a=="H") H=x;
    if (b=="T") T=y;
    if (b=="D") D=y;
    if (b=="H") H=y;
    cout.setf(ios_base::fixed);
    cout<<setprecision(1);
    #ifdef DEBUG
    cout<<"TTTTTTTTT "<<T<<" D "<<D<<" H "<<H<<endl;    
    #endif
    if (T==INT_MAX) {
      e=6.11*exp(5417.7530*((1.0/273.16)-(1.0/(D+273.16))));
      h=(0.5555)*(e-10.0);
      T=H-h;
    } else if (H==INT_MAX) {
      e=6.11*exp(5417.7530*((1.0/273.16)-(1.0/(D+273.16))));
      h=(0.5555)*(e-10.0);
      H=T+h;
    } else {
      h=H-T;
      e=h/0.5555+10;
      D=1.0/((1.0/273.16)-log(e/6.11)/5417.7530)-273.16;
    }
    helper(T); helper(D); helper(H);
    cout<<"T "<<T<<" D "<<D<<" H "<<H<<endl;
  }
}
