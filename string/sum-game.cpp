class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n/2;
        int leftsum =0,rightsum =0;
        int leftqu=0,rightqu=0;
        for(int i=0;i<n;i++){
            if(i<mid){
               if(num[i]!='?') leftsum+=(num[i]-'0');
               else leftqu++;
            }
            else{
                if(num[i]!='?') rightsum+=(num[i]-'0');
                else rightqu++;
            }
        }
        if(leftqu == rightqu) return leftsum!=rightsum;

        int qu = abs(leftqu-rightqu);
        int d = abs(leftsum-rightsum);
        return d!=(qu/2)*9;

    }
};