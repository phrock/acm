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

class OfficeParking
{ 
public: 
  int spacesUsed(vector <string> events);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Alice arrives","bob arrives","Alice departs",
 "Charles arrives","bob departs","Charles departs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, spacesUsed(Arg0)); }
	void test_case_1() { string Arr0[] = {"AdminBrett arrives","lbackstrom arrives","AdminBrett departs","mike arrives",
 "TheFaxman arrives","AdminBrett arrives","lbackstrom departs","dok arrives",
 "AdminBrett departs","gt arrives","AdminBrett arrives","lbackstrom arrives",
 "AdminBrett departs","jhughes arrives","jhughes departs","TheFaxman departs",
 "MaryJoe arrives","AdminBrett arrives","AdminBrett departs","AdminBrett arrives"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, spacesUsed(Arg0)); }
	void test_case_2() { string Arr0[] = {"SnapDragon arrives","tomek arrives","JohnDethridge arrives","ZorbaTHut arrives",
 "snewman arrives","reid arrives","NGBronson arrives","Yarin arrives",
 "bstanescu arrives","mathijs arrives","radeye arrives","bladerunner arrives",
 "dgarthur arrives","venco arrives","dmwright arrives","WishingBone arrives",
 "Eryx arrives","antimatter arrives","ChristopherH arrives","lars arrives",
 "biggnate arrives","JanKuipers arrives","dary arrives","haha arrives","grotmol arrives",
 "XuChuan arrives","Ryan arrives","LunaticFrindge arrives","Wasteland arrives",
 "RunningWild arrives","hampster arrives","RalphFurmaniak arrives",
 "kyky arrives","qubits arrives","Rustyoldman arrives","turuthok arrives",
 "Vulpecular arrives","Eeyore arrives","wackes arrives","Ishan arrives",
 "dimkadimon arrives","dplass arrives","Olorin arrives","TangentZ arrives",
 "NeverMore arrives","Pops arrives","srowan arrives","tjq arrives",
 "vorthys arrives","schveiguy arrives"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(2, Arg1, spacesUsed(Arg0)); }
	void test_case_3() { string Arr0[] = {"AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",
 "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, spacesUsed(Arg0)); }
	void test_case_4() { string Arr0[] = {"snapdragon arrives","SnapDragon arrives",
 "AdminBrett arrives","AdminBrett departs",
 "SnapDragon departs","snapdragon departs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, spacesUsed(Arg0)); }
	void test_case_5() { string Arr0[] = {"departs arrives","arrives arrives","arrives departs","departs departs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, spacesUsed(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }

int main()
{
  OfficeParking ___test; 
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

int OfficeParking :: spacesUsed(vector <string> events)
{
  int n=(int)(events).size();
  vector<int> v(n);
  set<int> st;
  map<string, int> mm;
  for (int i=0; i<(int)(events).size(); ++i) {
    vector<string> aux=split(events[i]);
    if (aux[1]=="arrives") {
      for (int j=0; j<n; ++j) if (!v[j]) { v[j]=1; st.insert(j); mm[aux[0]]=j; break; }
    } else {
      v[mm[aux[0]]]=0;
    }
  }
  return (int)(st).size();
      
}
