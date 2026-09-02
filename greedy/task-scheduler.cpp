class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int len = tasks.size();

        for(auto c : tasks) mp[c]++;
        int ans = 0;
        while(!mp.empty()){
            int l = mp.size();
            int cnt =0;
            for(auto it = mp.begin();it!=mp.end();){
                
                if(it->second>0) cnt++;
                it->second--;
                if(it->second==0) it = mp.erase(it);
                else it++;
            }
            int d = l-n;
            ans+=cnt;
            if(d<=0 && !mp.empty()){
                while(d!=1) {
                    ans++;
                    d++;
                }
            }
        }
        return ans;
    }
};