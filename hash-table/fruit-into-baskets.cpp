class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>mp;
        int l=0;
        int ans = INT_MIN;
        for(int r=0;r<n;r++){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;

            }
            ans = max(ans,r-l+1);
        }
        
        return ans;

        //TLE 91/92 not possible to optimise 
        // int l=0,r=0;
        // set<int>st;
        // int ans = INT_MIN;
        // while(l<n && r<n){
        //     st.insert(fruits[r]);
        //     if(st.size()>2){
        //         ans = max(ans,r-l+1);
        //         l++;
        //         st = {};
        //         r=l;
        //         r--;
        //     }
        //     r++;
        // }
        // ans = max(ans,r-l+1);
        // return ans-1;
    }
};