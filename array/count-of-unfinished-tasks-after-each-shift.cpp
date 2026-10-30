class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> prefix(n);
        prefix[0] = tasks[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + tasks[i];
        }
        long long mx = prefix[n-1];
        long long cnt =0;

        vector<int>ans;
        for(int x : shifts){
            cnt+=x;

            if(cnt>=mx){
                ans.push_back(0);
                cnt=0;
                
            }
            else{
                int id = upper_bound(prefix.begin(),prefix.end(),cnt) - prefix.begin();
                ans.push_back(n-id);
                
            }
        }
        return ans;
    }
};