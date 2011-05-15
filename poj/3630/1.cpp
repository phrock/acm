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


int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
	int n;
	cin >> n;
	bool f = true;
	set<string> st;
	string s;
	for (int j = 0; j < n; ++j) {
	    cin >> s;
	    if (!f) continue;
	    for (int p = 0; p < s.size(); ++p) {
		if (((st).find(s.substr(0, p+1)) != (st).end())) { f = false; break; }
	    }
	    st.insert(s);
	}
	if (f) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
}
