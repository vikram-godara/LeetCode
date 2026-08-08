class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m= nums1.size();
        int n = nums2.size();
        int l= m+n;
        vector<int> arr(l);
        for(int i=0;i<m;i++ ){
            arr[i] = nums1[i];
        }
        for(int i=0;i<n;i++ ){
            arr[i+m] = nums2[i];
        }
        sort(arr.begin(),arr.end());
        
        
        if((l)%2==0){
            double  p= (arr[(l/2)-1]+arr[l/2])/2.0;
            return p;
        }
        else {
            double  q = arr[l/2];
            return q;
        }
        
    }
};