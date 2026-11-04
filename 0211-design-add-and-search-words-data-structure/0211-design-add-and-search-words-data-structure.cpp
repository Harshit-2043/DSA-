class WordDictionary {
    struct Node {
        Node* next[26] = {};
        bool end = false;
    };
    Node* root;
    bool dfs(const string& w, int i, Node* node) {
        if (!node) return false;
        if (i == w.size()) return node->end;
        if (w[i] == '.') {
            for (int k = 0; k < 26; k++) {
                if (dfs(w, i + 1, node->next[k])) return true;
            }
            return false;
        }
        return dfs(w, i + 1, node->next[w[i] - 'a']);
    }
public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->next[i]) cur->next[i] = new Node();
            cur = cur->next[i];
        }
        cur->end = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};