class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long  total = 1LL * m*k;
        if(total>n) return -1;

        int low = 1, high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1; 
        while(low<=high){
            int mid = low + (high - low) / 2;

            int flower = findsum(bloomDay , mid ,m ,k);
            if(flower>=m) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int findsum (vector<int>bloom,int mid,int m,int k){
        int flower=0;
        int n = bloom.size();
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            if(bloom[i]<=mid) arr[i] = 1;
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i] ==1) cnt++;
            if(cnt==k){
                flower++;
                cnt=0;
            }
            if(arr[i] ==0) cnt=0;
        }
        return flower;
    }
};