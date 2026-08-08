class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            map<int,int> mp1;
            map<int,int> mp2;
            int j = i;
            for(int k =0;k<=j;k++){
                mp1[A[k]]++;
                mp2[B[k]]++;
            }
            int count = 0;
            for(auto x : mp1){
                if(mp2.find(x.first)!= mp2.end()){
                    count++;
                }
            }
            ans.push_back(count);

        }
        return ans;
    }
};