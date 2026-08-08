class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mi = INT_MAX;
        for(int i=0;i<n;i++){
            int a= nums[i];
            int sum= 0;
            while(a>0){
                sum+=a%10;
                a/=10;
            }
            mi = min(mi,sum);
        }
        return mi;
    }
};