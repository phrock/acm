#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

//const long MAX = 1000000;
const long MAX = 100;
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

    bitset<MAX> longest = prime;
    cout <<"haha"<<endl;
    int result = MAX;
    while (longest.count() > 1) {
	cout << longest.count() << endl;
    	result++;
	for (int i=0; i<MAX; i++) {
	    if (longest[i] == 1) {
		long long tmp = 0LL;
		int j = result;
		long long index = i;
		while (j > 0) {
		    if ((index < MAX) && (prime[index] == 1)) {
			tmp += index;
			index++;
			j--;
		    } else if (index >= MAX) {
			break;
		    } else {
			index++;
		    }
		}

		if ((j != 0) || (tmp >= MAX) || (prime[tmp] == 0)) {
		    cout <<"jjjjjjj: "<<j<<endl;
		    cout <<"tmp: "<< tmp <<endl;
		    cout <<"prime[tmp]: "<<prime[tmp]<<endl;
		    longest[i] = 0;
		}
	    }
	}
	cout << longest.count() << endl;
    }
}
