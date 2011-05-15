#include <map>
#include <vector>
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

bool check(int i, int j, int k, int a, int b, int c,
	   const vector<int>& v3, const vector<int>& v4, 
	   const vector<int>& v5, const vector<int>& v6,
	   const vector<int>& v7, const vector<int>& v8)
{
    vector<int> v(6);
    v[0] = i;
    v[1] = j;
    v[2] = k;
    v[3] = a;
    v[4] = b;
    v[5] = c;

    for (int x1=0; x1<v.size(); x1++) {
	if (v3[v[x1]] == 0) {
	    continue;
	}
	for (int x2=0; x2<v.size(); x2++) {
	    if (v4[v[x2]] == 0) {
		continue;
	    }
	    if (x2 == x1) {
		continue;
	    }
	    for (int x3=0; x3<v.size(); x3++) {
		if (v5[v[x3]] == 0) {
		    continue;
		}
		if ((x3 == x1) || (x3 == x2)) {
		    continue;
		}
		for (int x4=0; x4<v.size(); x4++) {
		    if (v6[v[x4]] == 0) {
			continue;
		    }
		    if (x4==x1 || x4==x2 || x4== x3) {
			continue;
		    }
		    for (int x5=0; x5<v.size(); x5++) {
			if (v7[v[x5]] == 0) {
			    continue;
			}
			if (x5==x1 || x5==x2 || x5==x3 || x5==x4) {
			    continue;
			}
			for (int x6=0; x6<v.size(); x6++) {
			    if (v8[v[x6]] == 0) {
				continue;
			    }
			    if (x6==x1 || x6==x2 || x6==x3 || x6==x4 || x6==x5) {
				continue;
			    }
			    return true;
			}
		    }
		}
	    }
	}
    }
    return false;

}

void findNumber()
{
    map< set<int>, int> mp;

    vector<int> v3(10000);
    vector<int> v4(10000);
    vector<int> v5(10000);
    vector<int> v6(10000);
    vector<int> v7(10000);
    vector<int> v8(10000);

    for (int i=1000; i<10000; i++) {
	v3[i] = test3(i);
	v4[i] = test4(i);
	v5[i] = test5(i);
	v6[i] = test6(i);
	v7[i] = test7(i);
	v8[i] = test8(i);
    }
    cout <<"*((*"<<endl;
    for (int i=1000; i<10000; i++) {
	// if (v3[i] == 0) {
	//     continue;
	// }
	for (int j=(i%100)*100; j>=1000 && j<(i%100+1)*100; j++) {
	    // if (v4[j] == 0) {
	    // 	continue;
	    // }
	    for (int k=(j%100)*100; k>=1000 && k<(j%100+1)*100; k++) {
		// if (v5[k] == 0) {
		//     continue;
		// }
		for (int a=(k%100)*100; a>=1000 && a<(k%100+1)*100; a++) {
		    // if (v6[a] == 0) {
		    // 	continue;
		    // }
		    for (int b=(a%100)*100; b>=1000 && b<(a%100+1)*100; b++) {
			// if (v7[b] == 0) {
			//     continue;
			// }
			for (int c=(b%100)*100; c>=1000 && c<(b%100+1)*100; c++) {
			    // if (v8[c] == 0) {
			    // 	continue;
			    // }
			    if (c%100 != i/100) continue;

			    set<int> s;
			    s.insert(i);
			    s.insert(j);
			    s.insert(k);
			    s.insert(a);
			    s.insert(b);
			    s.insert(c);

			    if (mp[s] > 0) {
				cout <<"///////////"<<endl;
				continue;
			    } else {
				mp[s]++;
			    }

			    cout <<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<endl;			    
			    if (check(i,j,k,a,b,c,v3,v4,v5,v6,v7,v8)) {
			    cout <<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<endl;
				cout << i+j+k+a+b+c << endl;

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
    cout << test3(4465) << endl;
    cout << test3(5565) << endl;
    cout << test3(8128) << endl;
    cout << test4(8281) << endl;
    cout << test5(2882) << endl;

    findNumber();

}
