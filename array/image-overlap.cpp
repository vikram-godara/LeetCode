class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        // for(int dr = -(n-1) ; dr<n; dr++){
        //     for(int dc = -(n-1) ; dc<n ;dc++){


        //         int cnt =0 ;

        //         for(int i =0;i<n;i++){
        //             for(int j= 0;j<n;j++){
        //                 if(img1[i][j]==0) continue;

        //                 int r = i+dr;
        //                 int c = j+dc;
        //                 if(r>=0 && r<n && c>=0 && c<n){
        //                     if(img2[r][c]) cnt++;
        //                 }

        //             }
        //         }
                
        //         ans = max(ans,cnt);
        //     }
        // }
        // return ans;

        vector<pair<int,int>>a,b;
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
               if(img1[i][j]) a.push_back({i,j});
               if(img2[i][j]) b.push_back({i,j});
            }
        }
        map<pair<int,int>,int>mp;
        for(auto &[x1,y1]: a){
            for(auto &[x2,y2]:b){
                int x = x2-x1;
                int y = y2-y1;
                mp[{x,y}]++;
                ans = max(ans,mp[{x,y}]);
            }
        }
        return ans;
    }
};