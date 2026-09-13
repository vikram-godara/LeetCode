class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        bool ans = true;
        
       
        for(int i=0;i<n;i++){
            vector<int>fre(n+1,0);
            for(int j = 0;j<n;j++){
                if(board[i][j] != '.'){
                    fre[board[i][j]-'0']++;
                    if(fre[board[i][j]-'0']>1){
                        ans = false;
                        break;
                    }
                }
            }
            if(!ans) break;
        }
        int r = 0;
        while(r<n){
            vector<int>v(n+1,0);
            for(int i =0;i<n;i++){
                if(board[i][r] != '.'){
                    v[board[i][r]-'0']++;
                    if(v[board[i][r]-'0']>1){
                        ans = false;
                        break;
                    }
                }
            }
            if(!ans) break;
            r++;

        }
        return ans;
    }
};