class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int cnt=0;
        string s;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            s = digits[i]+'0';
            for(int j = 0;j<n;j++){
                if(j==i) continue;
                s += (digits[j]+'0');
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    s  += ( digits[k]+'0');
                    int num = stoi(s);
                    if(num%2==0 && to_string(num).size()==3) st.insert(num);
                    s.pop_back();
                }
                s.pop_back();
            }
        }
        return st.size();
    }
};