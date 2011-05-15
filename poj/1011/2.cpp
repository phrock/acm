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

template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i) { cout<<*i<<", "; } cout<<"}"<<endl; }

typedef multiset<int>::iterator type;
set< multiset<int> > st;

bool check(multiset<int> &a, int k)
{
    // cout <<k<<endl;
    // print(a);
    type i, j;
    for (i = a.begin(); i != a.end(); ++i) {
	for (j = i, j++; j != a.end(); ++j) {
	    if (*i+*j <= k) {
		multiset<int> b = a;
		b.erase(b.find(*i));
		b.erase(b.find(*j));
		b.insert(*i+*j);
		// print(b);
		if ((!((st).find(b) != (st).end())) && check(b, k)) return true;
	    }
	}
    }
    st.insert(a);

    if (*(a.begin()) == k) return true;
    else return false;
}

int main()
{
    int m;
	while (cin >> m) {
	if (!m) break;
	int x;
	multiset<int> st;
	int sum = 0;
	int k = 0;
	for (int j = 0; j < m; ++j) {
	    cin >> x;
	    sum += x;
	    k = max(k, x);
	    st.insert(x);
	}
	// print(st);
	for (int j = k; j <= sum; ++j) {
	    if (sum%j == 0 && check(st, j)) { cout << j << endl; break; }
	}
    }
}
