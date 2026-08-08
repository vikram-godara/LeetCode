class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int add = mx;
        for(auto x : gain ){
            add+= x;
            mx = max(mx,add);
        } 
        return mx;
    }
};