class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //boye-moore algo
        int n = nums.size();
        int c1=0,c2=0;
        int el1=INT_MIN,el2=INT_MIN;
        for(int i=0;i<n;i++){

            if(c1==0 && nums[i]!=el2){
                c1=1;
                el1=nums[i];
            }
            else if(c2==0 && nums[i]!=el1){
                c2=1;
                el2=nums[i];
            }
            else if(el1==nums[i]) c1++;
            else if(el2==nums[i]) c2++;
            else {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(el1==nums[i]) c1++;
            if(el2==nums[i]) c2++;
        }
        int len = (n/3)+1;
        if(c1>=len) ans.push_back(el1);
        if(c2>=len) ans.push_back(el2);

        return ans;
    }
};