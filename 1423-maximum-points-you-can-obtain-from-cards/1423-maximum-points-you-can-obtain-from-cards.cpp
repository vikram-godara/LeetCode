class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>prefix(n+1,0),suffix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i]+cardPoints[i];
        }
        for(int i = n-1;i>=0;i--){
            suffix[i] = suffix[i+1]+cardPoints[i];
        }

        int ans = INT_MIN;
        for(int i=0;i<=k;i++){
            ans = max(ans,prefix[i] + suffix[n-k+i]);
        }
        return ans;
    }
};