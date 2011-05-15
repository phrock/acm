#include <iostream>

using namespace std;

int main()
{
    int n = 1000000;
    int result = 1;

    int m = 1;
    int len = -1;
    for (int i=1; i<=10; i++) {
	int d = 1;
	for (int j=0; j<i; j++) {
	    d *= 10;
	}

	// len += d;
	
	if (len+d >= m) {
	    for (int j=0; j<d; j++) {
