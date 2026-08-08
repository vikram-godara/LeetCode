class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        //sort(capacity.begin(),capacity.end());
        int n = capacity.size();
        int ans = -1;
        int capacit = INT_MAX;
        int doublet = 0;
        // for(int x =0;x<capacity.size();x++){

        //     if(capacity[x]>=itemSize){
        //         int c = x-itemSize;

        //         if(c<capacit){
        //             ans = x;
        //             capacit = c;
        //         }
        //         else if(c == capacit){
            //         }
            //     }
            // }

        vector<int>cap(n);
        for(int x = 0 ; x<n ; x++){
            
            cap[x] = capacity[x]-itemSize;
        }
        int x1 = INT_MAX;
        for(int x = 0 ; x<n ; x++){
           if(cap[x]>=0){
            if(x1>cap[x]){
                x1 = cap[x];
                ans = x;
            }
           }
        }
        return  ans;
    }
};