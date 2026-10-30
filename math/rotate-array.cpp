class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        vector<int>temp = nums;
        for(int i=0;i<n;i++){
            int newindex = (i+k)%n;
            temp[newindex] = nums[i];
        }
        nums = temp;
    }
};