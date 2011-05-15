const int MAX = 100000;
int root[MAX + 5];
int rank[MAX + 5];

void initSet()
{
    for (int i = 1; i <= MAX; ++i) root[i] = i, rank[i] = 1;
}

int findRoot(int x)
{
    if (root[x] != x) root[x] = findRoot(root[x]);
    return root[x];
}

void mergeDisjointSet(int a, int b)
{
    int ra = findRoot(a), rb = findRoot(b);
    if (rank[ra] > rank[rb]) root[rb] = ra, rank[ra]++;
    else root[ra] = rb, rank[rb]++;
}
