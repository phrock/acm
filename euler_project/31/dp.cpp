#include <vector>
#include <iostream>

using namespace std;

int dp(int n, const vector<int>& v)
{
    vector< vector<int> > s(n+1, vector<int>(v.size()+1, 0));

    for (int i=1; i<=v.size(); i++) {
	s[0][i] = 1;
    }

    for (int i=1; i<=n; i++) {
	for (int j=1; j<=v.size(); j++) {
	    if ((i-v[j-1]) >= 0) {
		s[i][j] = s[i-v[j-1]][j] + s[i][j-1];
	    } else {
		s[i][j] = s[i][j-1];
	    }
	    // cout <<"i: "<<i<<" j: "<<j<<" vj: "<<v[j-1]<<"  s: "<<s[i][j]<<endl;
	}
    }

    return s[n][v.size()];
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(50);
    // v.push_back(100);
    // v.push_back(200);

    cout << dp(5, v) << endl;
    cout << dp(200, v) << endl;
    cout << dp(800, v) << endl;
    cout << dp(10, v) << endl;
    cout << dp(100, v) << endl;
}
