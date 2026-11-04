class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a(nums1.begin(), nums1.end());
        unordered_set<int> b(nums2.begin(), nums2.end());
        vector<int> r1, r2;
        for (int x : a) if (!b.count(x)) r1.push_back(x);
        for (int x : b) if (!a.count(x)) r2.push_back(x);
        return {r1, r2};
    }
};