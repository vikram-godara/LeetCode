class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        // string s="";
        // for(int i=0;i<n;i++){
        //     s+=to_string(digits[i]);
        // }
        // int ans=stoi(s);
        // ans=ans+1;
        // string p=to_string(ans);
        // int len = p.length();
        // vector<int>a;
        // for(int i=0;i<len;i++){
        //     int b=p[i]-'0';
        //     a.push_back(b);
        // }
        // return a;
        //The std::out_of_range error occurs because stoi can only handle  numbers up to approximately 2.1 billion (\(2^{31}-1\)). In the "Plus One" problem,
        // the input digits can have up to 100 elements, representing a number far larger than any standard C++ integer type (including long long).

        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};