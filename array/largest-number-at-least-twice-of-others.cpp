class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums. size();
        int max1=-1, max2=-1;
        int id=0 ;
        for(int i=0;i<n;i++){ if(nums[i]>max1){max2=max1;
        max1=nums[i]; 
        id=i;
        }
        else if(nums[i]>max2) max2=nums[i];
        }
       // max = max/2;//
        
        if(max1>=max2*2) return id;
        else return -1;
        
    }
};