const int MAX = 1000;
int g[MAX][MAX], match[MAX], visited[MAX];
int n1, n2;

bool hungaryHelper(int idx)
{
    for (int i = 1; i <= n2; ++i)
	if (g[idx][i] && !visited[i]) {
	    visited[i] = 1;
	    if (match[i] == -1 || hungaryHelper(match[i])) {
		match[i] = idx;
		return true;
	    }
	}
    return false;
}

int hungary()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n1; ++i) {
	memset(visited, 0, sizeof(visited));
	if (hungaryHelper(i))
            ++res;
    }
    return res;
}
