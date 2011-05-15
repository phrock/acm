/*
  ID:   rock2to1
  LANG: C++
  PROG: zerosum
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

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
////////////////////////////////////////////////////////////////////////////////

int n;
int path[10];
int cur;

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

vector<int> splitInt( const string& s, const string& delim =" " ) {
  vector<string> tok = split( s, delim );
  vector<int> res;
  for ( int i = 0 ; i != (int)tok.size(); i++ )
    res.push_back( atoi( tok[i].c_str() ) );
  return res;
}


bool check(string s)
{
  string sign="@";
  for (int i=0; i<(int)(s).size(); ++i) if (!isdigit(s[i])) sign+=s[i], s[i]=' ';
  vector<int> v=splitInt(s);
  int sum=v[0];
  for (int i=1; i<(int)(v).size(); ++i)
    if (sign[i]=='+') sum+=v[i];
    else sum-=v[i];
  return !sum;
}

void dfs(string s)
{
  if (cur>n) {
    if (check(s)) {
      // cout<<s<<endl;
      fout<<1;
      for (int i=2; i<=n; ++i)
	if (path[i]==2) fout<<"+"<<i;
	else if (path[i]==3) fout<<"-"<<i;
	else fout<<" "<<i;
      fout<<endl;
    }
    return;
  }
  for (int i=1; i<=3; ++i) {
    int oc=cur;
    path[cur++]=i;
    if (i==1) dfs(s+*({stringstream ss; ss<<(oc); static string _; ss>>_; &_;}));
    else if (i==2) dfs(s+"+"+*({stringstream ss; ss<<(oc); static string _; ss>>_; &_;}));
    else if (i==3) dfs(s+"-"+*({stringstream ss; ss<<(oc); static string _; ss>>_; &_;}));
    cur--;
  }
}

int main()
{
  fin>>n;
  cur=2;
  dfs("1");
}
