class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int c=0;
        char z = digit+'0';
        for(int x : nums){
            string s = to_string(x);
            int n = s.size();
            for(char p : s) if(p==z)c++;
        }
        return c;
    }
};