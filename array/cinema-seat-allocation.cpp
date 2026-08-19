class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int p = reservedSeats.size();

        unordered_map<int,vector<int>>mp;

        for(auto &q : reservedSeats){
            mp[q[0]].push_back(q[1]);
        }

        int ans = (n -mp.size())*2;
        for(auto &[k,x] : mp){
           bool l = true, m = true,r = true;
            for(int s : x){
               if(s>=2 && s<=5) l = false;
               if(s>=4 && s<=7) m = false;
               if(s>=6 && s<=9) r = false;
            }
            if(l&&r) ans+=2;
            else if(l || r || m) ans+=1;
        }
        return ans;
    }
};