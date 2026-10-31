class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int>mp;
        while(n>0){
            int d = n%10;
            mp[d]++;
            n/=10;
        }

        int mx = INT_MAX;
        for(auto &[k,v] : mp){
            mx = min(mx,v);
        }
        int num =INT_MAX;
        for(auto &[k,v] : mp){
           if(v==mx){
            num = min(num,k);
           }
        }
        return num;
    }
};