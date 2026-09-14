class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int n = 4;
        int x1 = rec1[2],y2 = rec1[3];
        int a = rec2[0],b = rec2[1],c = rec2[2],d = rec2[3];

        if(x1>a && y2>b) return true;
        return  false;
    }
};