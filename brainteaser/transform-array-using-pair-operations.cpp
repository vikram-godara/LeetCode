class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum1 = accumulate(source.begin(),source.end() ,0*1LL);
        long long sum12 = accumulate(target.begin(),target.end(),0*1LL);

        return sum1==sum12;
    }
};