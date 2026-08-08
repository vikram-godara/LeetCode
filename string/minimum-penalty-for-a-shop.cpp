class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        int current=0;
        for(char c:customers)if(c=='Y')current++;
        int min=current;
        int mhour=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')current--;
            else current++;
            if(min>current){
               min=current;
               mhour=i+1;
            }
        }
        
        //TLE COMES-->
        // vector<int>counts(n+1,0);
        // for(int i=0;i<n+1;i++){
        //     int count=0;
        //     for(int j=i;j<n;j++){
        //         if(customers[j]=='Y')count++; 
        //     }
        //     for(int j=0;j<i;j++){
        //         if(customers[j]=='N')count++; 
        //     }
        //     counts[i] = count; 

        // }
        // int ans=0;
        // int min=counts[0];
        // for(int i=0;i<n+1;i++){
        //     if(min>counts[i])min=counts[i];
        // }
        // for(int i=0;i<n+1;i++){
        //     if(min==counts[i]){
        //         ans=i;
        //         break;
        //     }
        // }
        return mhour;
    }
};