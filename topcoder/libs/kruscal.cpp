int findRoot(int x, vector<int> &root)
{
    if (root[x] != x) root[x] = findRoot(root[x], root);
    return root[x];
}

void makeUnion(int x, int y, vector<int> &root)
{
    root[findRoot(x, root)] = findRoot(y, root);
}

pair<int, vector<pair<int, pair<int, int> > > > kruscal(const vector<vector<pair<int, int> > > &g)
{
    int n = (int)(g).size();
    vector<int> root(n);
    for (int i = 0; i < n; ++i) root[i] = i;
    vector<pair<int, pair<int, int> > > edge;
    for (int i = 0; i < (int)(g).size(); ++i)
	for (int j = 0; j < (int)(g[i]).size(); ++j)
	    if (i < g[i][j].first) edge.push_back(make_pair(g[i][j].second, make_pair(i, g[i][j].first)));
    sort((edge).begin(), (edge).end());
    vector<pair<int, pair<int, int> > > res_edge;
    int res_mst = 0;
    for (int i = 0; i < (int)(edge).size(); ++i) {
	int x = edge[i].second.first, y = edge[i].second.second;
	if (findRoot(x, root) != findRoot(y, root)) {
	    res_edge.push_back(edge[i]);
	    makeUnion(x, y, root);
	    res_mst += edge[i].first;
	}
    }

    return make_pair(res_mst, res_edge);
}
