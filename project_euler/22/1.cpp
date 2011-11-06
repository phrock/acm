#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> vs;
    string s;
    char c;
    while ((c=getchar()) != EOF) {
	if ((c<='Z') && (c>='A')) {
	    s += c;
	}
	if (c == ',') {
	    vs.push_back(s);
	    s = "";
	}
    }

    // for (int i=0; i<vs.size(); i++) {
    // 	cout << vs[i] << endl;
    // }
    sort(vs.begin(), vs.end());

    long long sum = 0;
    for (int i=0; i<vs.size(); i++) {
	long long worth = 0;
	for (int j=0; j<vs[i].size(); j++) {
	    worth += vs[i][j] - 'A' + 1;
	}
	sum += worth * (i+1);
	// if (vs[i] == "COLIN") {
	//     cout << worth << endl;
	//     cout << i + 1 << endl;
	// }
    }

    cout << sum << endl;
}
