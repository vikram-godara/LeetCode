class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (int x : nums)
            mp[x]++;
        vector<int> arr;
        while (!mp.empty()) {
            for (auto it = mp.begin(); it != mp.end();) {
                int k = it->first;
                int& v = it->second;

                arr.push_back(k);
                v--;

                if (v == 0)
                    it = mp.erase(it);
                else
                    it++;
            }
        }
        return arr;
    }
};