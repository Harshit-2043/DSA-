class Trie {
    struct Node {
        Node* next[26] = {};
        bool end = false;
    };
    Node* root;
    Node* find(const string& s) {
        Node* cur = root;
        for (char c : s) {
            cur = cur->next[c - 'a'];
            if (!cur) return nullptr;
        }
        return cur;
    }
public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->next[i]) cur->next[i] = new Node();
            cur = cur->next[i];
        }
        cur->end = true;
    }

    bool search(string word) {
        Node* n = find(word);
        return n && n->end;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};