#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

const long x = 1000000;
int countPrime(int n)
{
    bitset<x> bs(0);
    
    bs[0] = 1;
    bs[1] = 1;

    for (int i=2; i<=sqrt(x-1); i++) {
     	if (bs[i] == 0) {
     	    for (int j=i*i; j<x; j+=i) {
     		bs[j] = 1;
     	    }
     	}
    }
    cout <<bs.size()<< endl;

    int k = 0;
    while (n > 0) {
	if (bs[k++] == 0) {
	    n--;
	}
    }
    cout << k-1 << endl;

    return x - bs.count();
}

int main()
{
    int n = 10001;
    cout << countPrime(n) << endl;
}
