#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

const long MAX = 1000000;
bitset<MAX> prime(0);
// if bit is 1, then this bit is prime.
void findPrime(bitset<MAX>& bs)
{
    bs.reset();
    bs.flip();
    bs[0] = 0;
    bs[1] = 0;

    for (int i=2; i<=sqrt(MAX-1); i++) {
     	if (bs[i] == 1) {
     	    for (int j=i*i; j<MAX; j+=i) {
     		bs[j] = 0;
     	    }
     	}
    }
}

int digit(int n)
{
    int result = 0;
    while (n != 0) {
	result++;
	n /= 10;
    }
    return result;
}

int calculate(const vector<int>& v, const vector<int>& same)
{
    int result = 0;
    int t = 1;
    for (int i=0; i<v.size(); i++) {
	if (same[i] == 1) {
	    result += v[i]*t;
	}
	t *= 10;
    }

    return result;
}

bool testCalculate(const vector<int>& v, const vector<int>& same)
{
    int digit = -1;
    for (int i=0; i<v.size(); i++) {
	if (same[i] == 0) {
	    if (digit == -1) {
		digit = v[i];
	    } else if (digit != v[i]) {
		return false;
	    }
	}
    }
    return true;
}
    

bool testMatrix(int d, int amount)
{
    int matrix = 1;
    for (int i=1; i<d; i++) {
	matrix *= 10;
    }
	
    vector< vector<int> > v;
    for (int i=matrix; i<matrix*10; i++) {
	if (prime[i] == 1) {
	    // cout << "************ i: "<<i << endl;
	    
	    vector<int> vd(d);
	    int m = i;
	    int base = 0;
	    while (m != 0) {
		int k = m%10;
		vd[base] = k;

		m /= 10;
		base++;
	    }
	    v.push_back(vd);
	    // ///////
	    // for (int i=0; i<vd.size(); i++) {
	    // 	cout << vd[i] ;
	    // }
	    // cout << endl;
	    // ///////
	}
    }

    bool flag = false;

    int n = 1;
    for (int i=0; i<d; i++) {
	n *= 2;
    }

    for (int i=1; i<n; i++) {
	vector<int> same(d, 0);
	int j = i;
	int s = 0;
	while (j != 0) {
	    same[s] = j%2;
	    s++;
	    j /= 2;
	}
	// //////////
	// for (int z=0; z<d; z++) {
	//     cout << same[z] << " ";
	// }
	// cout << endl;
	// /////////

	map<int,int> mp;
	for (j=0; j<v.size(); j++) {
	    int key = calculate(v[j], same);
	    // /////////
	    // cout <<"*************"<<endl;
	    // for (int z=0; z<d; z++) {
	    // 	cout << v[j][z] << " ";
	    // }
	    // cout << endl;
		    
	    // cout <<key<<endl;
	    // for (int z=0; z<d; z++) {
	    // 	cout << same[z] << " ";
	    // }
	    // cout << endl;
 
	    // /////////

	    if (testCalculate(v[j], same)) {
		mp[key]++;
	    }
	}

	for (map<int,int>::const_iterator mi=mp.begin(); mi!=mp.end(); mi++) {
	    // /////////
	    // if (mi->first == 57) {
	    // 	cout <<"mmmmmmmmmmmmiiiiiiiiiiiiiii: " <<mi->second<<endl;
	    // }
	    // //////////

	    if (mi->second == amount) {
		flag = true;

		////////
		cout << "mmmmmmmmmmmmiiiiiiiiiiiiiii: " <<mi->second<<endl;
		for (int z=0; z<d; z++) {
		    cout << same[z];
		}
		cout << endl;

		for (j=0; j<v.size(); j++) {
		    int key = calculate(v[j], same);
		    if (key == mi->first) {
			if (testCalculate(v[j], same)) {
			    cout << key << endl;
			    for (int z=v[j].size()-1; z>=0; z--) {
				cout << v[j][z];
			    }
			    cout << endl;
			}
		    }
		}
		/////////
		
	    }
	}
    }
	
    if (flag == true) {
	cout << "haha " << d << endl;
    }

    return flag;
}

int main()
{
    findPrime(prime);

    int amount = 8;

    int d = 2;

    while (testMatrix(d, amount) == false) {
	cout << d << endl;
 	d++;
    }

    // if (testMatrix(5, 8)) {
    // 	cout<< "??????????"<<endl;
    // }
}
