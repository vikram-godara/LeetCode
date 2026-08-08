class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleperminute = 6;
        double hourcal= hour+1;
        if(hour==12) hourcal = 1;

        double totalmin = minutes - hourcal*5;
        double insidemin  = minutes/12;
        double remainmint = 5 - insidemin-1;
        double mintuesfration = minutes%12;
        double frationm = 12-mintuesfration;
        double ans = totalmin *6 + 6*remainmint + 0.5 * frationm;
        if(ans<0) ans*=-1;
        return ans>180 ? 360-ans : ans;
    }
};