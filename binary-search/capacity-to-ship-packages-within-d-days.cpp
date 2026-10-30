class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = accumulate(weights.begin(),weights.end(),0);
        int max = *max_element(weights.begin(),weights.end());

        int low = max, high = sum;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            int dayreq = findday(weights,mid);
            if(dayreq<=days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;

    }
    int findday(vector<int>&arr,int cap){
        int days = 1;
        int load =0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(load+arr[i]>cap){
                days = days+1;
                load = arr[i];
            }
            else load+=arr[i];
        }
        return days;
    }
};