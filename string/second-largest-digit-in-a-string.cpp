class Solution {
public:
    int secondHighest(string s) {
        int n = s.size();
        int ans = INT_MIN;
        vector<int>arr;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                arr.push_back(s[i]-'0');
            }
        }
        if(arr.empty()) return -1;
        int mx = *max_element(arr.begin(),arr.end());

        for(int i =0;i<arr.size();i++){
            if(arr[i]<mx)ans = max(ans,arr[i]);
        }
        return ans==INT_MIN ? -1 : ans;
    }
};