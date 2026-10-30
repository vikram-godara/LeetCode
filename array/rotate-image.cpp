class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>v;
        int n = matrix.size();
        int m = matrix[0].size();
        int col=0;
        while(col<m){
            vector<int>arr;
            for(int i=n-1;i>=0;i--){
                arr.push_back(matrix[i][col]);
            }
            v.push_back(arr);
            col++;
        }
        matrix = v;
    }
};