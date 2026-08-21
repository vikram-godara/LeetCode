class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        vector<int>arr;
        for(int i=0;i<coins.size();i++){
            int a = coins[i];
            int sum = a;
            arr.push_back(a);
            for(int j=1;j<=k;j++){
                sum+=a ;
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        return arr[k];
    }
};