class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // int n = s.size();
        // int p2=n-1;
        // for(int i=0;i<s.size()/2;i++){
        //     swap(s[i],s[p2]);
        //     p2--;
        // }

        //this is better sol
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};