class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        vector<int>arr1(26);
        for(int i=0;i<n;i++) arr1[s1[i]-'a']++;

        vector<int>arr2(26);
        int l=0,r=0;

        while(r<m){
            arr2[s2[r]-'a']++;

            if(r-l+1>n){
                arr2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1 == n){
                if(arr1 == arr2) return true;
            }
            r++;
            
        }
        return false;
    }
};