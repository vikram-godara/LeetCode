class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        int n = points.size();
        int f = points[0][0];
        int s = points[0][1];
        for(int i=1;i<n;i++){
            int a = points[i][0];
            int b = points[i][1];

            int diffa = abs(a-f);
            int diffb = abs(b-s);
            int coomen = min(diffa,diffb);
            time+=(coomen + abs(diffa-diffb));
            f = a;
            s = b;
           
        }
        return time;
    }
};