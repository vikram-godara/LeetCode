class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        vector<int>fre(26,0);
        vector<int>fre1(26,0);
        for(int i=0;i<n;i++){
            // int a = s[i];
            if(islower(s[i])){
                fre[s[i]-'a']++;
            }
            else{
                fre1[s[i]-'A']++;
            } 
        }
        int even=0;
        int odd=0;
        for(int i=0;i<26;i++){
            if(fre[i]%2==0){
                even+=fre[i];
            }
            else{
                even+=(fre[i]);
                odd++;

            }
        }
        for(int i=0;i<26;i++){
            if(fre1[i]%2==0){
                even+=fre1[i];
            }
            else{
                even+=(fre1[i]);
                odd++;
            }
        }
        if(odd>0){
            return even-odd+1;

        }else{
            return even;
        }
        
        
        

    }
};