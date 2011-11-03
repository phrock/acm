// g is adjacency matrix, return mininum circle.
int min_circle(const vector< vector<int> > &g)
{
    vector< vector<int> > dist = g;
    int res = INT_MAX;
    int n = (int)(g).size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < i; ++j)
                if (dist[i][j] != INT_MAX && g[i][k] != INT_MAX && g[k][j] != INT_MAX)
                    res = min(res, dist[i][j] + g[i][k] + g[k][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    return res;
}
