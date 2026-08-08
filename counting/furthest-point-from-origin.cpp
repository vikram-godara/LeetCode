class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int i=0;
        int cl=0,cr=0;
        while(i<n){
            if(moves[i]=='L') cl++;
            if(moves[i]=='R') cr++;
            i++;
        }
        int r = n-cl-cr;
        int ans;
        if(cl>cr) {
           ans =  r+cl-cr;
        }else ans = r+cr-cl;
        return ans ;
    }
};