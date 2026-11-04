class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());

        vector<int> ans;

        for (int spell : spells) {

            int l = 0;
            int r = potions.size() - 1;
            int index = potions.size();

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if ((long long)spell * potions[mid] >= success) {
                    index = mid;
                    r = mid - 1;
                }
                else {
                    l = mid+1;
                }
            }

            ans.push_back(potions.size() - index);
        }

        return ans;
    }
};