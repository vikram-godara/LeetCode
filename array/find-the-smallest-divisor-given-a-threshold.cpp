class Solution {
public:
    long long  Sum(vector<int>&arr,int mid){
        long long  sum =0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil(arr[i]+mid -1)/mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

       int low = 1,high = *max_element(nums.begin(),nums.end());

        int ans ;
        while(low<=high){
            int mid = low + ( high- low ) / 2;

            long long  sum = Sum(nums,mid);

            if(sum<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};