class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.size();
        int cnt=0;
        int a =0, b =0;
        for(char c : moves){
            if(c == 'U') {
                b++;
            }
            else if(c=='D'){
                b--;
            }
            else if(c=='L') {
                a--;
            }
            else if(c=='R'){
                a++;
            }
            else{
                cnt++;
            }
        }
        if(cnt){
            if(a>=0) a+=cnt;
            else if(b>=0) b+=cnt;
            else a-=cnt;
        }
        return abs(0-a)+abs(0-b);

    }
};