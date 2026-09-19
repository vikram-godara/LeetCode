class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2,
                      int y2) {

        int closestX = xCenter;
        int closestY = yCenter;

        if (xCenter < x1)
            closestX = x1;
        else if (xCenter > x2)
            closestX = x2;

        if (yCenter < y1)
            closestY = y1;
        else if (yCenter > y2)
            closestY = y2;

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        int d = dx * dx + dy * dy;

        return d <= r * r;
    }
};