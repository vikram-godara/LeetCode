class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[] (const vector<int> a, const vector<int>b){
            return (a[1]-a[0] ) > (b[1]-b[0]);
        });
        int total=0,current=0;
        for(auto & task : tasks){
            int minreq = task[1];
            int spent = task[0];
            if(current<minreq){
                total += (minreq-current);
                current = minreq;
            }
            current-=spent;
        }
        return total;

    }
};