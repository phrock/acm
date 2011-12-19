pair<int, vector<pair<int, int> > > prim(const vector<vector<pair<int, int> > > &g)
{
    const int MAX = INT_MAX / 2;
    int n = (int)(g).size();
    vector<int> dist(n, MAX);
    dist[0] = 0;
    vector<int> back(n);
    back[0] = -1;
    set<pair<int, int> > st;
    st.insert(make_pair(0, 0));
    while (!st.empty()) {
	pair<int, int> top = *st.begin();
	st.erase(st.begin());
	int v = top.second;
	for (int i = 0; i < (int)(g[v]).size(); ++i) {
	    int v2 = g[v][i].first, cost = g[v][i].second;
	    if (cost < dist[v2]) {
		if (dist[v2] != MAX)
                    st.erase(make_pair(dist[v2], v2));
		st.insert(make_pair(cost, v2));
		dist[v2] = cost;
		back[v2] = v;
	    }
	}
    }
    vector<pair<int, int> > edge;
    int mst = 0;
    for (int i = 0; i < n; ++i)
	if (back[i] != -1) {
            edge.push_back(make_pair(i, back[i]));
            mst += dist[i];
        }
    return make_pair(mst, edge);
}
