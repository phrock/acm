const int MAX = 12;
int found[1 << MAX];
long long determinant[1 << MAX];

// init: bitmap = (1 << A.size()) - 1
long long find_determinant(const vector< vector<long long> > &A, int bitmap)
{
    if (found[bitmap])
        return determinant[bitmap];
    if (!bitmap) {
        found[bitmap] = 1;
        return determinant[bitmap] = 1;
    }

    int col = (int)(A).size(), aux = bitmap;
    while (aux) {
        col -= aux % 2;
        aux >>= 1;
    }
    long long res = 0, sign = 1;
    for (int row = 0, b = 1; row < (int)(A).size(); ++row, b <<= 1)
        if (bitmap & b) {
            res += sign * A[row][col] * find_determinant(A, bitmap ^ b);
            sign = -sign;
        }
    found[bitmap] = 1;
    return determinant[bitmap] = res;
}
