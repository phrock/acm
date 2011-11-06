#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a[10];

    memset(a, 0, sizeof(a));

    for (int i=0; i<10; i++) {
	cout << a[i] << endl;
    }
    cout << sizeof(a) << endl;
}
