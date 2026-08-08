class Solution {
public:
    bool prime(int x){
        if(x<=1)return false;
        int i=2;
        while(i*i<=x){
            if(x%i==0)return  false;
            i++;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
             // bool p = prime(nums[i]);
            int a = nums[i];
            int c=0;
            if(i%2==0){
                while(!prime(a)){
                    a++;
                    c++;
                }
            }else{
                while(prime(a)){
                    a++;
                    c++;
                }
            }
            cnt+=c;
        }
        return cnt;
    }
};