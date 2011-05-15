long long graph_cycles(const vector< vector<int> > &g)
{
    int n = g.size();
    vector< vector<long long> > d(1 << n, vector<long long> (n));
    long long res = 0;
    for (int msk = 0; msk < (1 << n); ++msk) {
	int fs = -1;
	for (int i = 0; i < n; ++i) {
	    if (msk & (1 << i)) { fs = i; break; }
	}
	for (int i = 0; i < n; ++i) {
	    if (msk == (1 << i)) d[msk][i] = 1;
	    long long k = d[msk][i];
	    if (k) {
		if (g[i][fs] && i != fs && msk != (1 << i) + (1 << fs)) res += k;
		for (int j = fs + 1; j < n; ++j) {
		    if (g[i][j] && !(msk & (1 << j))) d[msk + (1 << j)][j] += k;
		}
	    }
	}
    }
    return res / 2;
}
