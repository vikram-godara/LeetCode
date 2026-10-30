class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        int d1 = abs(sr-tr);
        int d2 = abs(sc-tc);
        if(sr == tr && sc == tc) return  0;
        if(sr==tr || tc == sc || d1==d2) return 1;
        return 2;
    }
};