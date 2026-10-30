class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int> arr(26, 0);
            for (int j = i; j < n; j++) {
                arr[s[j]-'a']++;
                int mx = INT_MIN,mn = INT_MAX;
                for(int k=0;k<26;k++){
                    if(arr[k]>0){
                        mx = max(mx,arr[k]);
                        mn = min(mn,arr[k]);
                    }
                }
                cnt+=(mx-mn);
            }
        }
        return cnt;
    }
};