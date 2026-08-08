class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set<int>s(nums1.begin(),nums1.end());
        vector<int> freq(1001, 0);
        vector<int> ans;

        // Count nums1
        for (int x : nums1) {
            freq[x]++;
        }

        // Match with nums2
        for (int x : nums2) {
            if (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        return ans;
    }
};