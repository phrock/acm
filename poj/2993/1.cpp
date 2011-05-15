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

vector<string> split( const string& s, const string& delim =" " ) {
  vector<string> res;
  string t;
  for ( int i = 0 ; i != (int)s.size() ; i++ ) {
    if ( delim.find( s[i] ) != string::npos ) {
      if ( !t.empty() ) {
	res.push_back( t );
	t = "";
      }
    } else {
      t += s[i];
    }
  }
  if ( !t.empty() ) {
    res.push_back(t);
  }
  return res;
}

int main()
{
  string dump="+---+---+---+---+---+---+---+---+";
  string z1="|...|:::|...|:::|...|:::|...|:::|";
  string z2="|:::|...|:::|...|:::|...|:::|...|";
  vector<string> res;
  res.push_back(dump);
  for (int i=0; i<8; ++i) {
    if (i%2==0) res.push_back(z1);
    else res.push_back(z2);
    res.push_back(dump);
  }
  string s;
  getline(cin, s);
  for (int i=0; i<(int)(s).size(); ++i) if (s[i]==',') s[i]=' ';
  vector<string> v=split(s);
  if (v[0]=="White:") {
    for (int i=1; i<(int)(v).size(); ++i)
      if ((int)(v[i]).size()==3) v[i][0]=toupper(v[i][0]);
      else v[i]='P'+v[i];
  } else {
    for (int i=1; i<(int)(v).size(); ++i)
      if ((int)(v[i]).size()==3) v[i][0]=tolower(v[i][0]);
      else v[i]='p'+v[i];
  }
  for (int i=1; i<(int)(v).size(); ++i) {
    int row=8-(v[i][2]-'0');
    int column=v[i][1]-'a';
    row=2*row+1;
    column=4*column+2;
    res[row][column]=v[i][0];
  }

  getline(cin, s);
  for (int i=0; i<(int)(s).size(); ++i) if (s[i]==',') s[i]=' ';
  v=split(s);
  if (v[0]=="White:") {
    for (int i=1; i<(int)(v).size(); ++i)
      if ((int)(v[i]).size()==3) v[i][0]=toupper(v[i][0]);
      else v[i]='P'+v[i];
  } else {
    for (int i=1; i<(int)(v).size(); ++i)
      if ((int)(v[i]).size()==3) v[i][0]=tolower(v[i][0]);
      else v[i]='p'+v[i];
  }
  for (int i=1; i<(int)(v).size(); ++i) {
    int row=8-(v[i][2]-'0');
    int column=v[i][1]-'a';
    row=2*row+1;
    column=4*column+2;
    res[row][column]=v[i][0];
  }

  for (int i=0; i<(int)(res).size(); ++i) cout<<res[i]<<endl;
}
