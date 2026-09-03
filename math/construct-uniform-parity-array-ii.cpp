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

        int minodd = INT_MAX,mineven =INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2){
                minodd = min(minodd,nums1[i]);
            }
            else{
                mineven = min(mineven,nums1[i]);
            }
        }

        bool checkeven = true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0)continue;
            else{
                int d = nums1[i]-mineven;
                if(d>=1){
                    if(d%2) checkeven = false;
                }
                else checkeven = false;
            }
        }
        bool checkodd=true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2)continue;
            else{
                int d = nums1[i]-minodd;
                if(d>=1){
                    if(d%2==0) checkodd = false;
                }
                else checkodd = false;
            }
        }
        return (checkodd || checkeven ? true:false);
    }
};