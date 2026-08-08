class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int>newa = nums;
        sort(newa.begin(),newa.end(),greater<int>());

        vector<int>res;

        for(int x:newa){
            if(res.empty() || res.back()!=x){
                res.push_back(x);
                if(res.size()==k){
                    break;
                }
            }
        }
        return res;
    }
};