class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        // vector<string>v;
        int k = queryIndices.size();
        vector<int>ans;
        for(int i=0;i<k;i++){
            s[queryIndices[i]] = queryCharacters[i];
            // v.push_back(s);

            int mx = 1;
            int cnt =1;
            for(int i =1;i<s.size();i++){
                if(s[i]==s[i-1]) cnt++;
                else {
                    mx = max(mx,cnt);
                    cnt =1;
                }
            }
            mx = max(mx,cnt);
            ans.push_back(mx);

        }
       return ans;
    }
};