int findAugmentingPath(vector<vector<int> > &g, int source, int dest)
{
    int n = (int)(g).size();
    vector<int> from(n, -1);
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
	int cur = q.front();
	q.pop();
	if (cur == dest) break;
	for (int next = 0; next < n; ++next)
	    if (next != source && from[next] == -1 && g[cur][next] > 0) {
                from[next] = cur;
                q.push(next);
            }
    }
    int cur = dest;
    int res = INT_MAX;
    while (from[cur] != -1) {
        res = min(res, g[from[cur]][cur]);
        cur = from[cur];
    }
    cur = dest;
    while (from[cur] != -1) {
        g[from[cur]][cur] -= res;
        g[cur][from[cur]] += res;
        cur = from[cur];
    }
    return res == INT_MAX ? 0 : res;
}

// Ford-Fulkerson algorithm
int maxFlow(const vector<vector<int> > &g, int source, int dest)
{
    vector<vector<int> > residual = g; // residual graph for original graph
    int res = 0, cap = 0;
    while ((cap = findAugmentingPath(residual, source, dest)) > 0)
        res += cap;
    return res;
}
