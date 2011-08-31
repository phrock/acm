/*
  ID:   aphrodi1
  LANG: C
  PROG: humble
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define MAXPRIME 100
#define MAXN 100000

long long hum[MAXN+1];
int nhum;

int prime[MAXPRIME];
int pindex[MAXPRIME];
int nprime;

int main()
{
    FILE *fin, *fout;
    int i, minp;
    long long min;
    int n;

    fin = fopen("humble.in", "r");
    fout = fopen("humble.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &nprime, &n);
    for(i=0; i<nprime; i++)
	fscanf(fin, "%d", &prime[i]);

    hum[nhum++] = 1;
    for(i=0; i<nprime; i++)
	pindex[i] = 0;

    while(nhum < n+1) {
	min = 0x7FFFFFFF;
	minp = -1;
	for(i=0; i<nprime; i++) {
	    while((double)prime[i] * hum[pindex[i]] <= hum[nhum-1]) 
		pindex[i]++;

	    /* double to avoid overflow problems */
	    if((double)prime[i] * hum[pindex[i]] < min) {
		min = prime[i] * hum[pindex[i]];
		minp = i;
	    }
	}

	hum[nhum++] = min;
	pindex[minp]++;
    }

    fprintf(fout, "%lld\n", hum[n]);

    return 0;
}
