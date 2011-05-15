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
  map<char, string> mm;
  mm['B']=mm['F']=mm['P']=mm['V']="1";
  mm['C']=mm['G']=mm['J']=mm['K']=mm['Q']=mm['S']=mm['X']=mm['Z']="2";
  mm['D']=mm['T']="3";
  mm['L']="4";
  mm['M']=mm['N']="5";
  mm['R']="6";
  #ifdef DEBUG
  printp(mm);  
  #endif
  string s;
  while (cin>>s) {
    string res;
    for (int i=0; i<(int)(s).size(); ++i)
      if (((mm).find(s[i])!=(mm).end()) && (!i || mm[s[i]]!=mm[s[i-1]])) res+=mm[s[i]];
    cout<<res<<endl;
  }
}
