class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();

        int sum=0;
        for(auto x:apple) sum+=x;
        int msum=0;
        sort(capacity.rbegin(),capacity.rend());
        for(int i=0;i<m;i++){
            msum+=capacity[i];
            if(msum>=sum){
                return i+1;
            }
        }
       return m;
    }
};