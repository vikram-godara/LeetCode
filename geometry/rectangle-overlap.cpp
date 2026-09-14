class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int n = 4;
        auto temp1 = min(rec1,rec2);
        auto temp2 = max(rec1,rec2);
        rec1 =temp1;
        rec2 =temp2;
        int x1 = rec1[2],y2 = rec1[3];
        int a = rec2[0],b = rec2[1],c = rec2[2],d = rec2[3];

        if((a>=x1 || b>=y2)) return false;
        return  true;
    }
};