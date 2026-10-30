class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m>n) return {};
        vector<int>arr;
        vector<int>sa(26,0),pa(26,0);
        for(int i=0;i<m;i++){
            pa[p[i]-'a']++;
        }
        for(int i =0;i<n;i++){
            sa[s[i]-'a']++;
            if(i>=m){
                sa[s[i-m]-'a']--;
            }
            if(i>=m-1){
                if(sa==pa) arr.push_back(i-m+1);
            }
        }
        return arr;


        //* TLE 64/65 passed ->>faaaaaaaa......

        
        // sort(p.begin(),p.end());
        // if(m>n) return {};
        // if(m==n){
        //     string t = s;
        //     sort(s.begin(),s.end());
        //     if(t==p) return {0};
        //     else return {};
        // }
        // string sub;
        
        // vector<int>arr;
        // int i =0;
        // for(int j=0;j<n;j++){
        //     sub+=s[j];
        //     if(sub.size() == m){
        //         string t = sub;
        //         sort(t.begin(),t.end());
        //         if(t==p) arr.push_back(i);
        //         sub.erase(0,1);
        //         i++;
        //     }
        // }
        // return arr;
    }
};