class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        double p =M_PI;
        vector<double>ans;
        if((a+b>c) && (b+c>a) && (c+a>b)){
            double x = acos((b*b + c*c  - a*a)/(2*b*c));
            double y = acos((a*a+b*b-c*c)/(2*a*b));
            double z = acos((a*a + c*c - b*b)/(2*a*c));

            x = x*180/p;
            y = y*180/p;
            z = z*180/p;
            ans.push_back(x);
            ans.push_back(y);
            ans.push_back(z);
            sort(ans.begin(),ans.end());
        }
        return ans;
    }
};