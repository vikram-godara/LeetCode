class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        if(n==0) return 0;
        int mx = -1;
        int left =0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;

            while(mp[s[i]]>1){
                mp[s[left]]--;
                left++;

            }

            mx = max(mx,i-left+1);
            
        }
        return mx;
    }
};