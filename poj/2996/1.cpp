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

string chess="KQRBN";

int color;

bool cmp(string a, string b)
{
  if ((int)(a).size()!=(int)(b).size()) return (int)(a).size()>(int)(b).size();
  if ((int)(a).size()==3 && a[0]!=b[0]) {
    int p=chess.find(a[0]), q=chess.find(b[0]);
    return p<q;
  }
  if (a[(int)(a).size()-1]!=b[(int)(b).size()-1]) {
    if (!color) return a[(int)(a).size()-1]<b[(int)(b).size()-1];
    else return a[(int)(a).size()-1]>b[(int)(b).size()-1];
  }
  return a[(int)(a).size()-2]<b[(int)(b).size()-2];
}

int main()
{
  vector<string> white, black;
  string s, dump;
  cin>>dump;
  for (int i=0; i<8; ++i) {
    cin>>s>>dump;
    string row=*({stringstream ss; ss<<(8-i); static string _; ss>>_; &_;});
    vector<string> v=split(s, "|");
    for (int j=0; j<(int)(v).size(); ++j) {
      string column=*({stringstream ss; ss<<char('a'+j); static string _; ss>>_; &_;});
      if (isalpha(v[j][1])) {
	string aux;
	if (v[j][1]!='p' && v[j][1]!='P') aux+=toupper(v[j][1]);
	aux+=column;
	aux+=row;
	if (isupper(v[j][1])) white.push_back(aux);
	else black.push_back(aux);
      }
    }
  }
  #ifdef DEBUG
  print(white);  
  #endif
  color=0;
  sort((white).begin(), (white).end(), cmp);
  color=1;
  sort((black).begin(), (black).end(), cmp);

  cout<<"White: ";
  for (int i=0; i<(int)(white).size(); ++i) {if (i) cout<<","; cout<<white[i];}
  cout<<endl;
  cout<<"Black: ";
  for (int i=0; i<(int)(black).size(); ++i) {if (i) cout<<","; cout<<black[i];}
  cout<<endl;
}
