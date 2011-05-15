#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 1000;
    vector<int> v(n+1, 0);

    for (int i=1; i<=n; i++) {
	for (int j=i; j<=n; j++) {
	    if (i+j > n) {
		break;
	    }
	    for (int k=j; k<=n-i-j; k++) {
		if (i+j <= k) {
		    break;
		}

		if (i*i+j*j == k*k) {
		    v[i+j+k]++;
		}
	    }
	}
    }

    int max = 0;
    int result = 0;
    
    for (int i=0; i<v.size(); i++) {
	if (v[i] > max) {
	    max = v[i];
	    result = i;
	}
    }
    cout << result << endl;
}
