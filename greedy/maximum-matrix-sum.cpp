class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long totalsum=0;
        int mina=INT_MAX;
        int negc=0;
        
        for(const auto & row:matrix){
            for(int val:row){
                totalsum+=abs(val);
                if(val<0)negc++;
                mina=min(mina,abs(val));
            }
        }
        if(negc%2!=0){
            totalsum-=2LL *mina;
        }
       
        return totalsum;
        
    }
};