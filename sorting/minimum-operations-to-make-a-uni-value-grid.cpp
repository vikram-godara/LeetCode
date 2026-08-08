class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>linear;
        for(auto & q : grid){
            for(auto p : q) linear.push_back(p);
        }

        int a = linear[0];
        for(auto p : linear){
            if(abs(p-a)%x!=0)return -1;
        }
        sort(linear.begin(),linear.end());

        int avg = linear[linear.size()/2];
        int op =0;

        for(auto p : linear){
            op+=abs(p-avg)/x;
        }
        return op;
    }
};