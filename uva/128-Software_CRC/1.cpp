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

#define EPS 1e-11
#define SZ(x) (int)(x).size()
#define MP(a, b) make_pair(a, b)
#define X first
#define Y second


int main()
{
    string s;
    int g = 34943;
    while (getline(cin, s)) {
	if (SZ(s) > 0 && s[0] == '#') break;
	int x = 0;
	for (int i = 0; i < s.size(); ++i) {
	    x *= 256;
	    x += s[i];
	    x %= g;
	}
	x *= (256*256)%g;
	x %= g;
	int y = (g-x)%g;
	// cout << hex << y/256 << " " << y%256<<endl;
	// printf("%0X %0X\n", y/256, y%256);
	ostringstream o1, o2;
	o1 << hex << y/256;
	o2 << hex << y%256;
	string s1 = o1.str();
	string s2 = o2.str();
	if (SZ(s1) == 1) s1 = "0"+s1;
	if (SZ(s2) == 1) s2 = "0"+s2;
	for (int i = 0; i < s1.size(); ++i) {
	    s1[i] = toupper(s1[i]);
	}
	for (int i = 0; i < s2.size(); ++i) {
	    s2[i] = toupper(s2[i]);
	}
	cout << s1 << " " << s2 << endl;
    }
}
