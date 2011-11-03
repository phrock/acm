// all the permutations are the same cube
vector< vector<int> > cube_same_permutation()
{
    int a[6][6] = {{0, 1, 2, 3, 4, 5}, {1, 0, 4, 5, 2, 3}, {2, 0, 1, 5, 3, 4},
                   {3, 0, 2, 5, 4, 1}, {4, 0, 3, 5, 1, 2}, {5, 1, 4, 3, 2, 0}};
    vector< vector<int> > res;
    for (int i = 0; i < 6; ++i) {
        vector<int> aux(a[i], a[i] + 6);
        for (int j = 0; j < 4; ++j) {
            rotate(aux.begin() + 1, aux.begin() + 2, aux.begin() + 5);
            res.push_back(aux);
        }
    }
    return res;
}
