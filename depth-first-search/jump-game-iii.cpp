class Solution {
public:
    bool dfs(vector<int>&arr,int i){
        if(i<0 || i>=arr.size() || arr[i]<0) return false;
        if(arr[i]==0){
            return true;
        }
        arr[i]*=-1;
        bool a = dfs(arr,i-arr[i]);
        bool b = dfs(arr,i+arr[i]);
        return a||b;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return dfs(arr,start);
        // int idxofzero ;
        // for(int i=0;i<n;i++){
        //     if(arr[i]==0){
        //         idxofzero = i;
        //         break;
        //     }
        // }

    }
};