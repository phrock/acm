#include <iostream>
#include <string>

using namespace std;

void PythagoreanTriplet(int n)
{
    for (int i=1; i<n; i++) {
	for (int j=i; j<n; j++) {
	    for (int k=j; k<n; k++) {
		if ((i+j+k == 1000) && (i+j > k) && (i+k > j) && (j+k > i) && (i*i+j*j == k*k)) {
		    cout << i << " --- " << j << " --- " << k << endl;
		    cout << i*j*k << endl;
		}
	    }
	}
    }

}

int main()
{
    PythagoreanTriplet(1000);
}
