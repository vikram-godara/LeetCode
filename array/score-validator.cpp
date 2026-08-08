class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int n = events.size();
        int score=0,counter=0;
        for(auto &x : events){
            if (counter == 10) break;
            if(x=="0" || x=="1"|| x=="2"|| x=="3" || x=="4" || x=="5" || x=="6"){
                int y = stoi(x);
                score+=y;
            }
            if (x=="W" && counter<10)counter++;
            if(x=="WD" || x=="NB" )score++;
        }
        return {score,counter};
    }
};