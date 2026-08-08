class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        if (nums.empty()) return false;
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        int len = copy.back();
        int ans=false;
        vector<int>fre(len+1);
        for(int i=0;i<nums.size();i++)fre[nums[i]]++;
        
        for(int i=0;i<len+1;i++){
           
            int a=fre[i];
            if(a<=1)continue;
            bool isprime=true;
            
            for(int j=2;j*j<=a;j++){
                if(a%j==0){ 
                    isprime=false;
                     break;
                    }
            }
            if(isprime) return true;
            
        }
        return false;
    }

};