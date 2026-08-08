class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        if(k>n || k==0) return 0;
        long long  maxsum=0;
        sort(happiness.rbegin(),happiness.rend());
        for(int i=0;i<k;i++){
             
            long long current=max(0,happiness[i]-i);
               
                // happiness.erase(happiness.begin());
                // //sort(happiness.rbegin(),happiness.rend());
                // for(int h :happiness){
                //     if(h>0)h--;
                // }
            maxsum+=current;
            if(current==0)break;

            
        }
        return maxsum;
    }
};