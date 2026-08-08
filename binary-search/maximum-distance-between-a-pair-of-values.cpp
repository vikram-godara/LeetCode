class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // map<int,int>mp1;
        // map<int,int>mp2;
        // for(int i=0;i<nums1.size();i++){
        //     mp1[nums1[i]] = i;
        // }
        // for(int i=0;i<nums2.size();i++){
        //     mp2[nums2[i]] = i;
        // }
        // int ans = INT_MIN;
        // for(auto q : mp2){
        //     for(auto p : mp1){
        //         if(q.second>=p.second && q.first>=p.first){
        //             int d = q.second -p.second;
        //             ans = max(ans,d);
        //         }
        //     }
        // }

        int i=0,j=0;
        int n = nums1.size();
        int m = nums2.size();
        int ans=0;
        while(i<n && j<m){
            if(nums2[j]>=nums1[i]){
                ans = max(ans,j-i);
                j++;

            }else i++;
        }
        return ans;

    }
};