const int MAX=1000000;
int a[MAX];
int b[MAX];
int n;

int mergeSort(int a[], int p, int q)
{
    if (q-p <= 1) return 0;
    int d=(p + q) / 2;
    int res = 0;
    res += mergeSort(a, p, d);
    res += mergeSort(a, d, q);
    int i1 = p, i2 = d, j = 0;
    while (i1 < d || i2 < q) {
	if (i1 < d && i2 < q) {
	    if (a[i1] <= a[i2]) b[j++] = a[i1++], res += i2-d;
	    else b[j++] = a[i2++];
	} else if (i1 < d) while (i1<d) b[j++] = a[i1++], res += q-d;
	else while (i2 < q) b[j++] = a[i2++];
    }
    memcpy(a + p, b, j*sizeof(int));
    return res;
}
