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
#define pb push_back
////////////////////////////////////////////////////////////////////////////////


int main()
{
    string cur = "http://www.acm.org/";
    stack<string> back;
    stack<string> forward;
    string s;
    while (cin >> s) {
	if (s == "QUIT") break;
	if (s.substr(0, 5) == "VISIT") {
	    cin >> s;
	    back.push(cur);
	    while (!forward.empty()) forward.pop();
	    cur = s;
	    cout << cur << endl;
	}
	if (s == "BACK") {
	    if (back.empty()) {
		cout << "Ignored" << endl;
	    } else {
		forward.push(cur);
		cur = back.top();
		back.pop();
		cout << cur << endl;
	    }
	}
	if (s == "FORWARD") {
	    if (forward.empty()) {
		cout << "Ignored" << endl;
	    } else {
		back.push(cur);
		cur = forward.top();
		forward.pop();
		cout << cur << endl;
	    }
	}
    }
}
