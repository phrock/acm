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


int main()
{
    int k, n, m, q;
    string s;
    getline(cin, s);
    stringstream is(s);
    is>>k>>n>>m>>q;
    vector<string> basic(n), composite(m);
    for (int i=0; i<n; ++i) {
	getline(cin, s);
	stringstream is(s);
	is>>basic[i];
    }
    vector< vector<pair<string, int> > > create(m);
    for (int i=0; i<m; ++i) {
	getline(cin, s);
	for (int j=0; j<(int)(s).size(); ++j)
	    if (s[j]==':' || s[j]==',') s[j]=' ';
	stringstream is(s);
	string x;
	is>>x;
	composite[i]=x;
	string y;
	int z;
	while (is>>y>>z) create[i].push_back(make_pair(y, z));
	// sort((create[x]).begin(), (create[x]).end());
    }
    map<int, map<string, int> > own;
    for (int i=1; i<=k; ++i) own[i].clear();
    for (int i=0; i<q; ++i) {
	getline(cin, s);
	stringstream is(s);
	int a;
	string x;
	is>>a>>x;
	own[a][x]++;
	for (int j=0; j<m; ++j) {
	    bool ok=true;
	    for (int t=0; t<(int)(create[j]).size(); ++t) {
		string u=create[j][t].first;
		int un=create[j][t].second;
		if (own[a][u]<un) { ok=false; break; }
	    }
	    if (ok) {
		for (int t=0; t<(int)(create[j]).size(); ++t) {
		    string u=create[j][t].first;
		    int un=create[j][t].second;
		    own[a][u]-=un;
		}
		own[a][composite[j]]++;
	    }
	}
    }

    for (__typeof((own).begin()) i=(own).begin(); i!=(own).end(); ++i) {
	int cnt=0;
	for (__typeof((i->second).begin()) j=(i->second).begin(); j!=(i->second).end(); ++j) {
	    if (j->second) cnt++;
	}
	cout<<cnt<<endl;
	for (__typeof((i->second).begin()) j=(i->second).begin(); j!=(i->second).end(); ++j) {
	    if (j->second) cout<<j->first<<" "<<j->second<<endl;
	}
    }
}
