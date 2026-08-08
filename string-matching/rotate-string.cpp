class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(m!=n)return false;
        for (int i = 0; i < n; i++) {
            s = s + s[0];
            s.erase(s.begin());
            if (s == goal)
                return true;
        }

         return false;
    }
};