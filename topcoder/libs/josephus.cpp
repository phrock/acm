// there're n circle size, m is the gap size, which means every turn delete the mth element,
// return the last element, 0-indexed.
int josephus(int n, int m)
{
    int res = 0;
    for (int i = 2; i <= n; ++i) res = (res + m) % i;
    return res;
}
