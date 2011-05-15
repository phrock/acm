#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> permutation(int num, long long n)
{
    vector<int> v(num+1);

    long long mmm = 1;
    for (int i=1; i<=num+1; i++) {
	mmm *= i;
    }

    if (n > mmm) {
	cout << "error: too big n" << endl;
	return v;
    }

    for (int i=0; i<v.size(); i++) {
	v[i] = i;
    }

    while (n > 1) {
	// for (int i=0; i<v.size(); i++) {
	//     cout << v[i] << " ";
	// }
	// cout << "********" << endl;

	int k = v.size() - 1;
	while (v[k] <= v[k-1]) {
	    k--;
	}
	int lessBig = k;
	for (int i=k; i<v.size(); i++) {
	    if ((v[i] > v[k-1]) && (v[i] < v[lessBig])) {
		lessBig = i;
	    }
	}
	swap(v[k-1], v[lessBig]);
	sort(v.begin()+k, v.end());

	n--;
    }

    return v;
}

int main()
{
    int n = 1000000;
    vector<int> v = permutation(9, n);
    for (int i=0; i<v.size(); i++) {
	cout << v[i];
    }
    cout << " //////////" << endl;

}
