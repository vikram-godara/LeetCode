class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>>mi = matrix;
        int m = mi.size();
        int n = mi[0].size();
        vector<int>ans;
        int circle = (min(m,n)+1)/2;
        int curr=0;
        while(curr<circle){
            for(int i = curr;i<n-curr;i++){
                ans.push_back(mi[curr][i]);
            }
            for(int j = curr+1;j<m-curr;j++){
                ans.push_back(mi[j][n-curr-1]);
            }
             if(m-curr-1>curr) for(int i=n-curr-2;i>=curr;i--){
                ans.push_back(mi[m-curr-1][i]);
            }
            
            if(n-curr-1>curr) for(int j = m-curr-2;j>curr;j--){
                ans.push_back(mi[j][curr]);
            }
            curr++;
        }
        return ans;
        
    }
};