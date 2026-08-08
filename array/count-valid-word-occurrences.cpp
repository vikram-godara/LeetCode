class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        string s = "";
        for (auto c : chunks)
            s += c;
        vector<string> newa;
        unordered_map<string, int> mp;
        int n = s.size();
        string p = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z') {
                p += ch;
            } else if (ch == '-' && i > 0 && i < n - 1 && s[i - 1] >= 'a' &&
                       s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') {
                p += ch;
            }

            else if (!p.empty()) {
                // newa.push_back(p);
                mp[p]++;
                p = "";
            }
        }
        if (!p.empty()) {
            // newa.push_back(p);
            mp[p]++;
        }
        // vector<int>fre;
        // int m = queries.size();
        // int z=newa.size();
        // for(int i=0;i<m;i++){
        //     string x = queries[i];
        //     int count=0;
        //     for(int j=0;j<z;j++){
        //         if(x==newa[j]){
        //             count++;
        //         }
        //     }
        //     fre.push_back(count);
        // }
        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(mp[q]);
        }
        return ans;
    }
};