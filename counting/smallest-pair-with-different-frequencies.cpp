class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        for (auto i = freq.begin(); i != freq.end(); ++i) {
            for (auto j = next(i); j != freq.end(); ++j) {
                if (i->second != j->second)
                    return {i->first, j->first};
            }
        }

        return {-1, -1};
    }
};