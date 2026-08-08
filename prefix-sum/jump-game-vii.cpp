class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // int n = s.length();
        // vector<int>arr;
        // for(int i = 0 ;i<n ;i++){
        //     if(s[i]=='0'){
        //         arr.push_back(i);
        //     }
        // } 
        // bool ans = false;
        // int checklast = 0;
        // for(int i=0;i<arr.size()-1;i++){
        //     int diff = arr[i+1] - arr[i];
        //     if(diff == minJump || diff == maxJump ){
        //         ans = true;
        //         checklast += diff;
        //     } 
        //     else ans  = false;
        // }
        // bool finals = false;

        // if(ans && checklast == n-1) finals = true;
        // return finals;
                int n = s.size();

        queue<int> q;
        q.push(0);

        int far = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            int start = max(curr + minJump, far + 1);
            int end = min(curr + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    if (j == n - 1)
                        return true;
                    q.push(j);
                }
            }

            far = end;
        }

        return n == 1;
    }
};