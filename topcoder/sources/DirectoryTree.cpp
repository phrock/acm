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

class DirectoryTree
{ 
public: 
  vector <string> display(vector <string> files);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"/usr/lib/libc", "/usr/bin/find", "/home/schveiguy/bashrc",
 "/usr/bin/bash", "/usr/local/bin/ssh"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT",  "+-home",  "| +-schveiguy",  "|   +-bashrc",  "+-usr",  "  +-bin",  "  | +-bash",  "  | +-find",  "  +-lib",  "  | +-libc",  "  +-local",  "    +-bin",  "      +-ssh" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, display(Arg0)); }
	void test_case_1() { string Arr0[] = {"/dir/dir/file", "/dir/file", "/file",
 "/dir/sharedname/dir", "/dir/dir/sharedname"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT",  "+-dir",  "| +-dir",  "| | +-file",  "| | +-sharedname",  "| +-file",  "| +-sharedname",  "|   +-dir",  "+-file" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, display(Arg0)); }
	void test_case_2() { string Arr0[] = {"/a/a/a/a/a/a/a","/a/b/a/a/a/a/a","/a/a/a/a/b/a/a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ROOT",  "+-a",  "  +-a",  "  | +-a",  "  |   +-a",  "  |     +-a",  "  |     | +-a",  "  |     |   +-a",  "  |     +-b",  "  |       +-a",  "  |         +-a",  "  +-b",  "    +-a",  "      +-a",  "        +-a",  "          +-a",  "            +-a" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, display(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  DirectoryTree ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

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

vector <string> DirectoryTree :: display(vector <string> files)
{
  vector<string> res;
  res.push_back("ROOT");
  sort((files).begin(), (files).end());
  vector< pair<int, string> > a;
  set< pair<int, string> > st;
  for (unsigned i=0; i<(files).size(); ++i) {
    vector<string> v=split(files[i], "/");
    for (unsigned j=0; j<(v).size(); ++j)
      if (!((st).find(make_pair(j, v[j]))!=(st).end())) {
	a.push_back(make_pair(j, v[j]));
	st.insert(make_pair(j, v[j]));
      }
  }
  for (unsigned i=0; i<(a).size(); ++i) {
    string s;
    for (int j=0; j<a[i].first; ++j) s+="  ";
    s+="+-";
    s+=a[i].second;
    res.push_back(s);
  }

  for (int i=(a).size()-1; i>=0; --i) {
    int x=a[i].first*2;
    for (int j=i-1; j>=0; --j) {
      //      cout<<i<<" "<<j<<endl;
      if (a[i].first>=a[j].first) break;
      else res[j+1][x]='|';
    }
  }
    
  return res;
}
