#include <iostream>
#include <vector>

using namespace std;

void fillTringle(vector< vector<int> >& v)
{
    int ceiling = 1000000;
    int n = v.size();

    for (int i=1; i<n; i++) {
	for (int j=1; j<i; j++) {
	    int a = v[i-1][j];
	    int b = v[i-1][j-1];
	    if ((a == -1) || (b == -1) || (a+b > ceiling)) {
		v[i][j] = -1;
	    } else {
		v[i][j] = a+b;
	    }
	}
    }
}
	    

int main()
{
    int n = 101;

    vector< vector<int> > v(n, vector<int>(n, 1));

    fillTringle(v);

    int count = 0;
    for (int i=0; i<n; i++) {
	for (int j=0; j<v[i].size(); j++) {
	    if (v[i][j] == -1) {
		count++;
	    }
	}
    }

    cout << count << endl;
}
