class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string w;
        vector<string> words;
        while (ss >> w) words.push_back(w);
        reverse(words.begin(), words.end());
        string res;
        for (int i = 0; i < words.size(); i++) {
            if (i) res += ' ';
            res += words[i];
        }
        return res;
    }
};