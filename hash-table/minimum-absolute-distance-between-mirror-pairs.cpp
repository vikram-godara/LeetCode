class Solution {
public:
    int reversenum(int num){
        int res = 0;
        while(num>0){
            res = res*10 + num%10;
            num/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int ans = INT_MAX;
        // for(int i=0;i<n;i++){
        //     string s  = to_string(nums[i]);
        //     reverse(s.begin(),s.end());
        //     int num = stoi(s);
        //     newa.push_back(num);
        //     for(int j= i+1;j<n;j++){
        //         if(num==nums[j]){
        //             int d = abs(j-i);
        //             ans = min(ans,d);
        //         }
        //     }
        // }
        for(int i=n-1;i>=0;i--){
            int p = reversenum(nums[i]);
            if(mp.count(p)) ans = min(ans , abs(mp[p]-i));
            mp[nums[i]] = i;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};