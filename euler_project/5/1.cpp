#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getMinMulti(int n)
{
    vector<int> v(n+1, 1);

    v[0] = 0;
    v[1] = 0;

    for (int i=2; i<=sqrt(n); i++) {
	for (int j=i*i; j<=n; j+=i) {
	    v[j] = 0;
	}
    }

    vector<int> count(n+1, 0);
    for (int i=1; i<=n; i++) {
	vector<int> tmp(n+1, 0);
	int j = i;
	while (j != 1) {
	    int k = 1;
	    bool ok = false;
	    for (; k<v.size(); k++) {
		if ((v[k] == 1) && (j%k == 0)) {
		    tmp[k]++;
		    j /= k;
		    ok = true;
		}
	    }
	    if (!ok) {
		break;
	    }
	}

	for (int i=0; i<tmp.size(); i++) {
	    if (tmp[i] > count[i]) {
		count[i] = tmp[i];
	    }
	}
    }

    // cout <<"88888888"<<endl;
    // for (int i=0; i<count.size(); i++) {
    // 	cout << count[i] << endl;
    // }

    int result = 1;
    for (int i=0; i<count.size(); i++) {
	while (count[i] != 0) {
	    result *= i;
	    count[i]--;
	}
    }

    return result;
}

int main()
{
    int test = 10;
    cout << getMinMulti(test) << endl;
    int x = 20;
    cout << getMinMulti(x) << endl;
}
