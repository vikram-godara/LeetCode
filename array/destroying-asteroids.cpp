class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long  sum = (long long)mass;
        for(auto x : asteroids){
            if(sum<x) return false;
            else sum+=x;
        }
        return true;
    }
};