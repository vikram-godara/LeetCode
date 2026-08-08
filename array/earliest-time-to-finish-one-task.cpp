class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int totaltime = INT_MAX;
        for (auto t : tasks) {
            int finsihed = t[0] + t[1];
            totaltime = min(totaltime, finsihed);
        }
        return totaltime;
    }
};