#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <cmath>
#include <climits>

using namespace std;

const long MAX = 100000000;

int main()
{
    int d = 3;
    vector<int> v;
    for (int i=1; i<=d; i++) {
	v.push_back(i);
    }

    while (next_permutation(v.begin(), v.end())) {
	for (int i=0; i<v.size(); i++) {
	    cout << v[i] << " ";
	}
	cout << endl;
    }

}
