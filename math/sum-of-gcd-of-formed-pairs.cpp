class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxelement(n);
        int a = nums[0];
        maxelement[0] = a;
        for(int i=1;i<n;i++){
            if(nums[i]>a){
                a = nums[i];
                maxelement[i] = a;
            }
            maxelement[i] = a;
        }

        vector<int>prefixgcd(n);
        for(int i=0;i<n;i++){
            prefixgcd[i] = __gcd(nums[i],maxelement[i]);
        }

        sort(prefixgcd.begin(),prefixgcd.end());

        long long sum = 0;
        for(int i=0;i<(n/2);i++){
            sum+=1LL *(__gcd(prefixgcd[i],prefixgcd[n-i-1]));
        }

        return sum;
        
    }
};