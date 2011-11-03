const int MAX=50;
int ncr[MAX][MAX];
memset(ncr, 0, sizeof(ncr));
for (int i = 0; i < MAX; ++i)
    for (int j = 0; j <= i; ++j)
        ncr[i][j] = !j ? 1 : ncr[i-1][j-1] + ncr[i-1][j];
