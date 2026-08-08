class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        vector<int>arr=nums;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>even;
            unordered_set<int>odd;
            for (int j=i;j<n;j++){
                if(arr[j]%2==0)
                    even.insert(arr[j]);
                else
                    odd.insert(arr[j]);
                if( even.size()==odd.size())
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};