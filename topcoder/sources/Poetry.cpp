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

class Poetry
{ 
public: 
  string rhymeScheme(vector <string> poem);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"I hope this problem",
 "is a whole lot better than",
 "this stupid haiku"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; verify_case(0, Arg1, rhymeScheme(Arg0)); }
	void test_case_1() { string Arr0[] = {"     ",
 "Measure your height",
 "AND WEIGHT      ",
 "said the doctor",
 "",
 "And make sure to take your pills",
 "   to   cure   your    ills",
 "Every",
 "DAY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = " aab ccde"; verify_case(1, Arg1, rhymeScheme(Arg0)); }
	void test_case_2() { string Arr0[] = {"One bright day in the middle of the night",
 "Two dead boys got up to fight",
 "Back to back they faced each other",
 "Drew their swords and shot each other",
 "",
 "A deaf policeman heard the noise",
 "And came to arrest the two dead boys",
 "And if you dont believe this lie is true",
 "Ask the blind man he saw it too"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aabb cdef"; verify_case(2, Arg1, rhymeScheme(Arg0)); }
	void test_case_3() { string Arr0[] = {"",
 "",
 "",
 ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "    "; verify_case(3, Arg1, rhymeScheme(Arg0)); }
	void test_case_4() { string Arr0[] = {"This poem has uppercase letters",
 "In its rhyme scheme",
 "Alpha", "Blaster", "Cat", "Desert", "Elephant", "Frog", "Gulch", 
 "Horse", "Ireland", "Jam", "Krispy Kreme", "Loofah", "Moo", "Narf",
 "Old", "Pink", "Quash", "Rainbow", "Star", "Tour", "Uvula", "Very",
 "Will", "Xmas", "Young", "Zed", "deception", "comic", "grout",
 "oval", "cable", "rob", "steal", "steel", "weak"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abcdefghibjkblmnopqrstcuvwxyzABCbDEFG"; verify_case(4, Arg1, rhymeScheme(Arg0)); }
	void test_case_5() { string Arr0[] = {" ",
 "     ",
 "This poem",
 "         ",
 " ",
 " ",
 "",
 "Has lots of blank lines",
 " ",
 "      ",
 "                                            ",
 "         ",
 " ",
 "              ",
 "                                                  ",
 "  in      it           "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "  a    b       c"; verify_case(5, Arg1, rhymeScheme(Arg0)); }
	void test_case_6() { string Arr0[] = {"too bad   your",
 "     solution went   sour"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aa"; verify_case(6, Arg1, rhymeScheme(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Poetry ___test; 
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

bool isVowel(string s, int k)
{
  cout<<s<<" "<<k<<endl;
  string a="aeiou";
  string b="aeiouy";
  if (k==0 || k==(int)(s).size()-1) {
    cout<<"kk"<<endl;
    cout<<a<<endl;
    if ((find((a).begin(), (a).end(), s[k])!=(a).end())) {cout<<"ffo"<<endl;return true;}
    else return false;
  } else {
    if ((find((b).begin(), (b).end(), s[k])!=(b).end())) return true;
    else return false;
  }
}

bool isWord(string s)
{
  cout<<s<<endl;
  for (int i=0; i<(int)(s).size(); ++i)
    if (isVowel(s, i)) {cout<<"ffqqq"<<endl;return true;}
  return false;
}


bool rhyme(string a, string b)
{
  int n=min((int)(a).size(), (int)(b).size());
  for (int k=1; k<=n; ++k) {
    string t1=a.substr((int)(a).size()-k);
    string t2=b.substr((int)(b).size()-k);
    if (t1!=t2) continue;
    int p=(int)(a).size()-k;
    int q=(int)(b).size()-k;
    if (!isVowel(a, p) || !isVowel(b, q)) continue;
    int tmp=p;
    while (tmp<(int)(a).size() && isVowel(a, tmp)) tmp++;
    if (tmp<(int)(a).size()) {
      bool ok=true;
      for (int i=tmp; i<(int)(a).size(); ++i) if (isVowel(a, i)) { ok=false; break; }
      if (!ok) continue;
    }
    if (t1!=a && isVowel(a, p-1)) continue;
    if (t2!=b && isVowel(b, q-1)) continue;
    return true;
  }
  return false;
}
      

string Poetry :: rhymeScheme(vector <string> poem)
{
  string yy;
  for (int i=0; i<26; ++i) yy+=char('a'+i);
  for (int i=0; i<26; ++i) yy+=char('A'+i);
  for (int i=0; i<(int)(poem).size(); ++i)
    for (int j=0; j<(int)(poem).size(); ++j)
      poem[i][j]=tolower(poem[i][j]);
  // print(poem);
    cout<<"ff"<<endl;
  int n=(int)(poem).size();
  vector<vector<string> > a(n);
  for (int i=0; i<(int)(poem).size(); ++i) {
    cout<<poem[i]<<endl;
    vector<string>  s=split(poem[i]);
    // print(s);
    for (int j=0; j<(int)(s).size(); ++j){
      cout<<s[j]<<endl;
      if (isWord(s[j])){cout<<"uu"<<endl; a[i].push_back(s[j]);cout<<"pp"<<endl;}
    }
  }
  cout<<"ff"<<endl;
  int index=0;
  string res;
  for (int i=0; i<n; ++i) res+='*';
  for (int i=0; i<(int)(a).size(); ++i)
    if ((int)(a[i]).size()==0) res[i]=' '; else res[i]='*';
  for (int i=0; i<(int)(a).size(); ++i) {
    if (!(int)(a[i]).size() || res[i]!='*') continue;
    res[i]=yy[index++];
    for (int j=i+1; j<(int)(a).size(); ++j)
      if (res[j]=='*' && rhyme(a[i].back(), a[j].back())) res[j]=res[i];
  }
  cout<<"*************"<<endl;
  cout<<rhyme("height", "weight")<<endl;
  cout<<"*************"<<endl;
  return res;
}
