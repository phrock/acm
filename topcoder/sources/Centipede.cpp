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

class Centipede
{ 
public: 
  vector <string> simulate(vector <string> screenLayout, int timeUnits);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"#                #",
 "# #      #       #",
 "#   #    #   #   #",
 "#           #    #",
 "#   ##         # #",
 "# #      ##      #",
 "#    #           #",
 "#                #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; string Arr2[] = { "#                #",  "# #      #       #",  "#   #    #xxx#   #",  "#         xx#    #",  "#   ##   xxx   # #",  "# #      ##      #",  "#    #           #",  "#                #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, simulate(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"#          #",
 "#          #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; string Arr2[] = { "#          #",  "#xxxx      #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, simulate(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"#            #",
 "#     #      #",
 "#            #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; string Arr2[] = { "#xxxxxxxxxx  #",  "#     #      #",  "#            #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, simulate(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#                        #",
 "#      #                 #",
 "#                 #      #",
 "#  ##    #               #",
 "#              #    #    #",
 "#     #                  #",
 "#       #          #     #",
 "#          #             #",
 "#              #         #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 74607; string Arr2[] = { "#                        #",  "#      #                 #",  "#                 #      #",  "#  ##    #               #",  "#              #    #    #",  "#     #xxxxxxx           #",  "#      x#          #     #",  "#     xx   #             #",  "#              #         #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, simulate(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#                            #",
 "#   #     # # #           # ##",
 "#   #       #                #",
 "#                          # #",
 "#                   #        #",
 "##    #           #        # #",
 "#    #    #   #              #",
 "#  #    #  #          #      #",
 "#     #   #       #          #",
 "#                            #",
 "#     #        #         #   #",
 "#   ###          #        #  #",
 "#           ##             # #",
 "#                     #      #",
 "##           #               #",
 "#     #     #   #     # #    #",
 "#          #  ##   #         #",
 "#                    #       #",
 "#                    #  #    #"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 598273167; string Arr2[] = { "#                            #",  "#   #     # # #           # ##",  "#   #       #                #",  "#                          # #",  "#                   #        #",  "##    #           #        # #",  "#    #    #   #              #",  "#  #    #  #          #      #",  "#     #   #       #          #",  "#                         xxx#",  "#     #        #         #xxx#",  "#   ###          #        # x#",  "#           ##             # #",  "#                     #      #",  "##           #               #",  "#     #     #   #     # #    #",  "#          #  ##   #         #",  "#                    #       #",  "#                    #  #    #" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, simulate(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Centipede ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

struct node {
  int x, y, dir;
  bool operator ==(const node &a)
  {
    return x==a.x && y==a.y && dir==a.dir;
  }
};

vector <string> Centipede :: simulate(vector <string> screenLayout, int timeUnits)
{
  deque<node> a(10);
  int n=(int)(screenLayout).size();
  for (int i=0; i<(int)(a).size(); ++i)
    a[i].x=i+1, a[i].y=0, a[i].dir=1;
  deque<node> orig=a;
  int cycle=0;
  vector<deque<node> > mm;
  while (true) {
    #ifdef DEBUG
    cout<<cycle<<" "<<(int)(a).size()<<endl;    
    #endif
    if (a.empty()) break;
    mm.push_back(a);
    cycle++;
    a.pop_front();
    node next=a.back();
    next.x+=next.dir;
    #ifdef DEBUG
    cout<<"ff"<<" "<<next.x<<" "<<next.y<<endl;
    cout<<screenLayout[next.y][next.x]<<"**"<<endl;
    #endif
    if (screenLayout[next.y][next.x]=='#') {
      next.dir*=-1;
      next.x+=next.dir;
      next.y=next.y+1;
      if (next.y<n && screenLayout[next.y][next.x]=='#') {
	next.y=next.y-1;
      }
    }
    if (next.y<n) a.push_back(next);
  }
  #ifdef DEBUG
  cout<<"cycle: "<<cycle<<endl;  
  #endif
  timeUnits%=cycle;
  deque<node> b=mm[timeUnits];
  for (int i=0; i<(int)(b).size(); ++i) screenLayout[b[i].y][b[i].x]='x';
  return screenLayout;
}
