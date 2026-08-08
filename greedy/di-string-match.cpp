class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int>arr;
        int l=0,r = n;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                arr.push_back(l);
                l++;
            }else {
                arr.push_back(r);
                r--;
            }
        }
        arr.push_back(r);
        return arr;
    }
};