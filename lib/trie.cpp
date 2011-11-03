struct trie {
    trie *next[10];
    char data;
    bool is_leaf;
};

trie * init_trie()
{
    trie *node = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 10; ++i)
        node->next[i] = NULL;
    node->data = '\0';
    node->is_leaf = false;

    return node;
}

void add_trie(trie *root, const string &s, bool &ok)
{
    trie *cur = root;
    for (int i = 0; i < (int)(s).size(); ++i) {
        int idx = s[i] - '0';
        if (cur->next[idx] == NULL) {
            trie *node = init_trie();
            node->data = s[i];
            if (i == (int)(s).size() - 1)
                node->is_leaf = true;
            cur->next[idx] = node;
        } else {
            if (cur->next[idx]->is_leaf == true || i == (int)(s).size() - 1)
                ok = false;
        }
        cur = cur->next[idx];
    }
}
