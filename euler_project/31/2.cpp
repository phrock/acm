#include <vector>
#include <iostream>

using namespace std;

int methods(int n, const vector<int>& v)
{
    vector< vector<int> >result(n+1, vector<int>(v.size(), 1));

    for (int i=1; i<=n; i++) {
	for (int j=1; j<v.size(); j++) {
	    if ((i-v[j]) >= 0) {
		result[i][j] = result[i][j-1] + result[i-v[j]][j];
	    } else {
		result[i][j] = result[i][j-1];
	    }
	}
    }

    return result[n][v.size()-1];
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(100);
    v.push_back(200);

    // cout << methods(100, v) << endl;
    cout << methods(200, v) << endl;
}
