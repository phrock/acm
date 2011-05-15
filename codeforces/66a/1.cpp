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

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif
////////////////////////////////////////////////////////////////////////////////

string sb="127", ss="32767", si="2147483647", sl="9223372036854775807";

bool is_byte(string s) { return (int)(s).size()<(int)(sb).size() || (int)(s).size()==(int)(sb).size() && s<=sb?true:false; }
bool is_short(string s) { return (int)(s).size()<(int)(ss).size() || (int)(s).size()==(int)(ss).size() && s<=ss?true:false; }
bool is_int(string s) { return (int)(s).size()<(int)(si).size() || (int)(s).size()==(int)(si).size() && s<=si?true:false; }
bool is_long(string s) { return (int)(s).size()<(int)(sl).size() || (int)(s).size()==(int)(sl).size() && s<=sl?true:false; }

int main()
{
    string s;
    cin>>s;
    if (is_byte(s)) cout<<"byte"<<endl;
    else if (is_short(s)) cout<<"short"<<endl;
    else if (is_int(s)) cout<<"int"<<endl;
    else if (is_long(s)) cout<<"long"<<endl;
    else cout<<"BigInteger"<<endl;
}
