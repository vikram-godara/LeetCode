class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int row = rowIndex;
        int start = 1;
        vector<int> prev = {1};
        int level = 1;
        while (level <= row) {
            vector<int> curr;
            curr.push_back(1);
            int n = prev.size();
            if (n > 1) {
                for (int i = 1; i < prev.size(); i++) {
                    curr.push_back(prev[i]+prev[i-1]);
                }
            }
            curr.push_back(1);
            prev = curr;
            level++;
        }
        return prev;
    }
};