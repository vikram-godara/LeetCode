class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<int>landprefix(n);
        vector<int>waterprefix(m);
        int min1 = INT_MAX,min2 = INT_MAX;
        int idx1 = -1,idx2=-1;
        for(int i=0;i<n;i++){
            int a  = landStartTime[i] + landDuration[i];
            landprefix[i] = a;
            if(min1>a){
                min1 = a;
                idx1 = i;
            }
        }
        for(int i=0;i<m;i++){
            int a = waterStartTime[i]+ waterDuration[i];
            waterprefix[i] = a;
            if(min2>a){
                min2 = a;
                idx2 = i;
            }
        }
        int ans = INT_MAX;
        // for land first
        {   
            int ans1 = min1;
            int landdone = min1;
            // map<int,int>mp;
            // for(int i=0;i<m;i++){
            //     mp[waterDuration[i]] = waterStartTime[i];
            // }
            // for(auto &[key,value] : mp){
            //     if(landdone>=value){
            //         ans = min(ans, landdone + key);
            //     }
            //     else{
            //         int diff = value - landdone;
            //         ans = min(ans,landdone + key + diff);
            //     }
            // }
            for(int i=0;i<m;i++){
                if(landdone>waterStartTime[i]){
                    ans = min(ans,landdone + waterDuration[i]);
                }
                else{
                    int diff = waterStartTime[i] - landdone;
                    ans = min(ans,landdone + diff  + waterDuration[i]);
                }
            }
        }
        //for water first
        {
            int waterdone = min2;
            // map<int,int>mp;
            // for(int i=0;i<n;i++){
            //     mp[landDuration[i]] = landStartTime[i];
            // }
            // for(auto &[key,value] : mp){
            //     if(waterdone>=value){
            //         ans = min(ans, waterdone + key);
            //     }
            //     else {
            //         int diff = value - waterdone;
            //         ans = min(ans,waterdone + key + diff);
            //     }
            // }
            for(int i=0;i<n;i++){
                if(waterdone>landStartTime[i]){
                    ans = min(ans, waterdone + landDuration[i]);
                }
                else {
                    int diff = landStartTime[i] - waterdone;
                    ans = min(ans, waterdone +diff+ landDuration[i]);
                }
            }
        }
        return ans;

    }
};