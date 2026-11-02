class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    unordered_set<int> st;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      /* code */
      if (!st.count(nums[i]))
        st.insert(nums[i]);
      else
        ans.push_back(nums[i]);
    }
    return ans;
  }
};