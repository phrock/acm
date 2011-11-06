#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

const long MAX = 1000000;
//const long MAX = 1000;
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

int main()
{
    findPrime(prime);

    vector<int> v;
    for (int i=0; i<prime.size(); i++) {
	if (prime[i] == 1) {
	    v.push_back(i);
	}
    }

    int longest = 0;
    int bigEnough = 0;
    for (longest=0; longest<v.size(); longest++) {
	bigEnough += v[longest];
	if (bigEnough > MAX) {
	    break;
	}
    }

    for (int i=longest; i>=1; i--) {
	cout << i << endl;
	int result = 0;
	for (int j=0; j<v.size()-i; j++) {
	    long long tmp = 0LL;
	    for (int k=0; k<i && tmp<MAX; k++) {
		tmp += (long long)v[j+k];
	    }
	    if ((tmp < MAX) && (prime[tmp] == 1)) {
		result = tmp;;
	    }
	}

	if (result != 0) {
	    cout << "********** " << i<<endl;
	    cout << result << endl;
	    break;
	}
    }
	
}
