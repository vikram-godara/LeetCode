class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int a = int('z')-int(s[i]) +1;
            sum+=(a)*(i+1);
        }
        return sum;
    }
};