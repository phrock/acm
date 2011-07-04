const int MAX = 50005;
int a[MAX], c[MAX];
int n;

int lowbit(int x)
{
    // return x & (x ^ (x - 1));
    return 1 << __builtin_ctz(x);
}

// update value of a[idx] to val, total number is n, base idx = 1;
void update(int idx, int val, int n)
{
    int orig_idx = idx;
    while (idx <= n) {
        c[idx] = c[idx] - a[idx] + val;
        idx += lowbit(idx);
    }
    a[orig_idx] = val;
}

// the sum of a[1...k]
long long query_sum(int k)
{
    long long res = 0;
    while (k) {
        res += c[k];
        k -= lowbit(k);
    }
    return res;
}
