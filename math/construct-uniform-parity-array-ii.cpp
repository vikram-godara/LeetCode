class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd=0,even=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2) odd++;
            else even++;
        }
        if(even==0)return true;
        if(odd==0)return true;

        bool checkeven = true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) continue;
            else{
                if(i==0) {
                    checkeven = false;
                    break;
                }
                int d = nums1[i]-nums1[i-1];
                if(d>=1){
                    if(d%2) checkeven = false;
                }
                else checkeven = false;
            }
        }

        bool checkodd = true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2)continue;
            else{
                if(i==0){
                    checkodd = false;
                    break;
                }
                int d = nums1[i]-nums1[i-1];
                if(d>=1){
                    if(d%2==0)checkodd = false;
                }
                else checkodd = false;
            }
        }

        return (checkodd || checkeven ? true:false);
    }
};