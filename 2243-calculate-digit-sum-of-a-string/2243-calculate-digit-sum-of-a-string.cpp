class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        string ans = s;
        while(ans.size()>k){
            vector<string>arr;
            string p = "";
            int cnt=0;
            for(int i=0;i<ans.size();i++){
                p+=ans[i];
                cnt++;
                if(cnt==k){
                    arr.push_back(p);
                    p = "";
                    cnt=0;
                }
            }
            if(!p.empty())arr.push_back(p);
            for(int j=0;j<arr.size();j++){
                int sum =0;
                for(int i=0;i<arr[j].size();i++){
                    sum+=(arr[j][i]-'0');
                }
                arr[j] = to_string(sum);
            }
            string news = "";
            for(string c : arr) news+=c;

            ans = news;
        }
        return ans;
    }
};