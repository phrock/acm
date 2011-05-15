#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int count(int a, int b)
{
    vector< vector<int> > v(a+1, vector<int>(b+1, 0));
    for (int i=2; i<=a; i++) {
	for (int j=2; j<=b; j++) {
	    v[i][j] = 1;
	}
    }

    int result = 0;
    for (int i=2; i<=a; i++) {
	for (int j=2; j<=b; j++) {
	    //	    if (v[i][j] == 1) {
		 cout << i << " ////////////// " << j << endl;
		//		result++;
		for (int k=2; k<j; k++) {
		    if ((j%k == 0) && (pow(i,j/k) <= a)) {
			v[pow(i, j/k)][k] = 0;
			cout << i << "  " << j << endl;
			cout << pow(i, j/k) << "  ***  "<< k << endl;
		    }
		}
		// }
	}
    }

    for (int i=2; i<=a; i++) {
	for (int j=2; j<=b; j++) {
	    if (v[i][j] == 1) {
		result++;
	    }
	}
    }

    return result;
}

int main()
{
    int ta = 25;
    int tb = 25;
    cout << count(ta, tb) << endl;

    int a = 100;
    int b = 100;
            cout << count(a, b) << endl;

}
