class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), write = 0, i = 0;
        while (i < n) {
            char c = chars[i];
            int j = i;
            while (j < n && chars[j] == c) j++;
            int count = j - i;
            chars[write++] = c;
            if (count > 1) {
                for (char d : to_string(count)) chars[write++] = d;
            }
            i = j;
        }
        return write;
    }
};