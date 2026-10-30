class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(nums1.begin(),nums1.end());
        unordered_set<int>st1;
        for(int x : nums2){
            if(st.count(x)) st1.insert(x);
        }
        vector<int>ans(st1.begin(),st1.end());
        return ans;
    }
};