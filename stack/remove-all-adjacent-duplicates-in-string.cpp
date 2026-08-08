class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string r = "";

        for(auto c: s) {
            if(!r.empty() && c==r.back()){
                r.pop_back();
            }
            else r+=c;
        }

        return r;
    }
};