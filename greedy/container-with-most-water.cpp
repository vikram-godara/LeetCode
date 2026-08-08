class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = INT_MIN;
        //brute force --> TLE  58/65
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int h =min(height[i],height[j]);
        //         int area = j-i;
        //         ans = max(ans,h*area);
        //     }
        // }
                
        int l=0;
        int r=n-1;
        while(l<r){
            int area = (r-l) * min(height[l],height[r]);
            if(height[l]>height[r]) r--;
            else l++;
            ans = max(ans,area);
        }
        return ans;
    }
};