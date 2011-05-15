/*
  ID:   rock2to1
  LANG: C++
  PROG: spin
*/

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

ifstream fin("spin.in");
ofstream fout("spin.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  vector<int> speed(5);
  vector<vector<int > > v(5, vector<int>(360));
  for (int i=0; i<5; ++i) {
    cin>>speed[i];
    int x;
    cin>>x;
    for (int j=0; j<x; ++j) {
      int a, b;
      cin>>a>>b;
      for (int k=a; k<=a+b; ++k) v[i][k%360]=1;
    }
  }
  for (int i=0; i<360; ++i) {
    for (int k=0; k<360; ++k) {
      bool ok=true;
      for (int j=0; j<5; ++j) 
	if (!v[j][(k-i*speed[j]%360+360)%360]) { ok=false; break; }
      if (ok) { cout<<i<<endl; return 0; }
    }
  }
  cout<<"none"<<endl;
}
