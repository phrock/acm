#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> combine(const vector<int>& v)
{
    vector<int> a = v;
    sort(a.begin(), a.end());

    vector<int> result;

    while (true) {
	// for (int i=0; i<a.size(); i++) {
	//     cout << a[i] << " ";
	// }
	// cout << "********" << endl;

	int element = 0;
	for (int i=0; i<a.size(); i++) {
	    element = element*10 + a[i];
	}

	result.push_back(element);

	int k = a.size() - 1;
	while ((k > 0) && (a[k] <= a[k-1])) {
	    k--;
	}
	if (k == 0) {
	    break;
	}

	int lessBig = k;
	for (int i=k; i<a.size(); i++) {
	    if ((a[i] > a[k-1]) && (a[i] < a[lessBig])) {
		lessBig = i;
	    }
	}
	swap(a[k-1], a[lessBig]);
	sort(a.begin()+k, a.end());
    }

    return result;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);

    vector<int> r = combine(v);

     for (int i=0; i<r.size(); i++) {
     	cout <<r[i] << endl;
     }
}
