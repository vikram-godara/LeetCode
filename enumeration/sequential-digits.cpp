class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        vector<int> predata = {1,2,3,4,5,6,7,8};

        for (auto x : predata) {
            int a = x;

            // Generate until it reaches at least low
            while (a < low) {
                string s = to_string(a);
                char p = s.back();

                if (p == '9') break;

                s += char(p + 1);
                a = stoi(s);
            }

            // Collect all valid numbers
            while (a <= high) {
                if (a >= low)
                    ans.push_back(a);

                string s = to_string(a);
                char p = s.back();

                if (p == '9') break;

                s += char(p + 1);
                a = stoi(s);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};