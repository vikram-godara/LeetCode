class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        using ll = long long;
        for(ll i = 0;i<n;i++){
        //     stack<char>st;
        //     int x = nums[i];
        //     string s = "";
        //     for(int i =1;i<=x;i++){
        //          char c = 'a';
        //         while(!st.empty() && st.top() == c){
        //             st.pop();
        //             c++;
        //         }
        //         st.push(c);
        //     }
        //     string ans ="";
        //     while(!st.empty()){
        //         ans+=st.top();
        //         st.pop();
        //     }
        //     reverse(ans.begin(),ans.end());
        //     ans1.push_back(ans);

            string s ;
            ll z = nums[i] /(1LL<<25);
            nums[i]%=(1LL<<25);
            s.append(z,'z');
            for(int j =24;j>=0;j--){
                if(nums[i]&(1LL<<j)) s+=('a'+j);
            }
            ans.push_back(s);
        }
        return ans;
    }
};