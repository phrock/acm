#include <set>
#include <cmath>
#include <iostream>
using namespace std;

int test3(int n)
{
    n *= 8;

    n++;

    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq--;

    if (sq%2 != 0) {
	return 0;
    }

    int result = sq/2;
    return result;
}

int test4(int n)
{
    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    } else {
	return sq;
    }
}

int test5(int n)
{
    n *= 24;
    n++;

    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq++;

    if (sq%6 != 0) {
	return 0;
    }

    int result = sq / 6;
    return result;
}

int test6(int n)
{
    n *= 8;
    n++;

    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq++;

    if (sq%4 != 0) {
	return 0;
    }
    
    int result = sq / 4;
    return result;
}

int test7(int n)
{
    n *= 40;
    n += 9;
    
    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq += 3;

    if (sq%10 != 0) {
	return 0;
    }

    int result = sq / 10;
    return result;
}

int test8(int n)
{
    n *= 12;
    n += 4;

    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq += 2;

    if (sq%6 != 0) {
	return 0;
    }

    int result = sq / 6;
    return result;
}

bool check(int i, int j, int k, int a, int b, int c)
{
    int ix = test3(i);
    int jx = test4(j);
    int kx = test5(k);
    int ax = test6(a);
    int bx = test7(b);
    int cx = test8(c);

    if (ix==0 || jx==0 || kx==0 ||
	ax==0 || bx==0 || cx==0) {
	return false;
    }

    set<int> s;
    s.insert(ix);
    s.insert(jx);
    s.insert(kx);
    s.insert(ax);
    s.insert(bx);
    s.insert(cx);

    if (s.size() == 6) {
	return true;
    } else {
	return false;
    }
}

void findNumber()
{
    for (int i=1000; i<10000; i++) {
	cout <<"****** "<<i<<endl;
	for (int j=(i%100)*100; j>=1000 && j<(i%100+1)*100; j++) {
	    for (int k=(j%100)*100; k>=1000 && k<(j%100+1)*100; k++) {
		for (int a=(k%100)*100; a>=1000 && a<(k%100+1)*100; a++) {
		    for (int b=(a%100)*100; b>=1000 && b<(a%100+1)*100; b++) {
			for (int c=(b%100)*100; c>=1000 && c<(b%100+1)*100; c++) {
			    cout <<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<endl;
			    if (check(i, j, k, a, b, c) == true) {
				cout <<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<endl;
				cout << i+j+k+a+b+c << endl;
				break;
			    }
			}
		    }
		}
	    }
	}
    }
}
	    

int main()
{
    cout << test3(8128) << endl;
    cout << test4(8281) << endl;
    cout << test5(2882) << endl;

    findNumber();

}
