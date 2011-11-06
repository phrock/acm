#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int gridProduct(vector< vector<int> > grid, int m)
{
    int result = 0;

    int n = grid.size();
    for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {

	    int tmp1 = 1;
	    int tmp2 = 1;
	    int tmp3 = 1;
	    int tmp4 = 1;
	    for (int k=0; k<m; k++) {
		if (i+k < n) {
		    tmp1 *= grid[i+k][j];
		}
		if (j+k < n) {
		    tmp2 *= grid[i][j+k];
		}
		if ((i+k < n) && (j+k < n)) {
		    tmp3 *= grid[i+k][j+k];
		}
		if ((i+k < n) && (j-k >= 0)) {
		    tmp4 *= grid[i+k][j-k];
		}
	    }
	    
	    result = tmp1 > result ? tmp1 : result;
	    result = tmp2 > result ? tmp2 : result;
	    result = tmp3 > result ? tmp3 : result;
	    result = tmp4 > result ? tmp4 : result;
	}
    }

    return result;
}

int main()
{

    int n = 20;
    int m = 4;
    vector< vector<int> > grid(n, vector<int>(n));
    for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {
	    cin >> grid[i][j];
	}
    }

    cout << gridProduct(grid, 4) << endl;
}
