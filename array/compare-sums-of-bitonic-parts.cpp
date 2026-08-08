class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        vector<int>a1;
        vector<int>a2;
        int maxx = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxx){
                 idx = i;
                break;
            }
        }
       for(int i = 0;i<=idx;i++){
            a1.push_back(nums[i]);
        }
        for(int i = idx;i<n;i++){
            a2.push_back(nums[i]);
        }
        long long  sum1=0,sum2=0;
        for(auto x : a1)sum1+=x;
        for(auto x : a2)sum2+=x;

        if(sum1>sum2)return 0;
        else if(sum2>sum1)return 1;
        else return -1;
    }
};