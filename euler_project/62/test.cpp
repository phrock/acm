#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int cubeRoot(int n)
{
    return pow(n, 1/3.0);
}

bool testCube(int n)
{
    int x = cubeRoot(n);

    if (x*x*x == n) {
	return true;
    } else {
	return false;
    }
}

int main()
{
    vector<int> v;
    vector<int> vv;

    v.push_back(1);
    v.push_back(2);
    vv.push_back(1);

    if (v == vv){
	cout <<"haha"<<endl;
    }


    cout <<4187LL*4187*4187<<endl;
}
