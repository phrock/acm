template<class T> set< vector<T> > getAllSubSet(const vector<T> &v)
{
    set< vector<T> > res;
    vector<T> empty;
    res.insert(empty);
    if (v.empty()) return res;
    T x = *v.begin();
    set< vector<T> > aux = getAllSubSet(vector<T> (v.begin()+1, v.end()));
    for (__typeof((aux).begin()) i = (aux).begin(); i != (aux).end(); ++i) {
	vector<T> tmp = *i;
	res.insert(tmp);
	tmp.push_back(x);
	sort((tmp).begin(), (tmp).end());
	res.insert(tmp);
    }
    return res;
}
