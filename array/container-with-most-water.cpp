class Solution {
public:
    int maxArea(vector<int>& height) {
        //two pointer
        int n = height.size();
        int l=0,r=n-1;
        int mx = -1;
        while(l<r){
            int ans = (r-l) * min(height[l],height[r]);
           
            if(height[l]>height[r]) r--;
            else l++;
            mx = max(ans,mx);
        }
        return mx;
    }
};