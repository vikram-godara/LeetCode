class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int n = columnTitle.size();
        for(int i = 0;i<n;i++){
            int f = columnTitle[i]-'A' +1;
            ans = f + 26 * ans;
        }
        return ans;
    }
};