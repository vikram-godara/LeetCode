class Solution {
public:

    bool isprime(int x){
        if(x<2)return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0)return false;
        }
        return true;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int count;
        long long  sum=0;
        for(int x:nums){
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    int a=i;
                    int b=x/i;
                    if(a!=b && isprime(a) && isprime(b)){
                        sum+=1+a+b+x;
                    }
                    break;
                }
            }
            int r=round(cbrt(x));
            if((long long)r*r*r==x && isprime(r)){
                sum+=1+r+r*r+x;
            }
        }

        // for(int i=0;i<n;i++){
        //     long long  curr=0;
        //     count=0;
        //     for(int j=1;j<=nums[i];j++){
        //         if(nums[i]%j==0){
        //             count++;
        //             curr+=j;
        //         }
        //     }
        //     if(count==4){
        //         sum+=curr;
        //     }
        // }
        return sum;
    }
};