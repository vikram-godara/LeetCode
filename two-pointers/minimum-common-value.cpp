class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;
        for(auto &x : nums1) mp1[x]++;
        for(auto &x : nums2) mp2[x]++;

        for(auto m : mp1){
            if(mp2.find(m.first) != mp2.end()){
                return m.first;
            }
        }
        return -1;


    }
};