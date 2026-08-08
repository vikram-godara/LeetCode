class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int lst  = landStartTime.size();
        int wst = waterStartTime.size();
        int ans = INT_MAX;
        for(int i=0;i<lst;i++){
            for(int j=0;j<wst;j++){
                //land first;
                int landfinish = landStartTime[i] + landDuration[i];
                int waterstart = max(landfinish,waterStartTime[j]);
                ans = min(ans,waterstart + waterDuration[j]);


                //water>land
                int waterfinish = waterStartTime[j] + waterDuration[j];
                int landstart  = max(waterfinish,landStartTime[i]);
                ans = min(ans,landstart + landDuration[i]);
            }

        }
        return ans;
    }
};