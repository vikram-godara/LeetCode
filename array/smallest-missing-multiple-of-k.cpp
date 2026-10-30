class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int x : nums)st.insert(x);
        int a =k;
        while(st.count(a)) a+=k;
        return a;
    }
};