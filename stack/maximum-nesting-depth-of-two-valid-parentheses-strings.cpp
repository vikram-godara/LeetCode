class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int>arr;
        int open =0;
        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                open++;
                if(open%2 ==0 ) arr.push_back(1);
                else arr.push_back(0);
            }
            else if(seq[i] == ')') {
                if(open%2 == 0) arr.push_back(1);
                else arr.push_back(0);
                open--;
            }
        }
        return arr;
    }
};