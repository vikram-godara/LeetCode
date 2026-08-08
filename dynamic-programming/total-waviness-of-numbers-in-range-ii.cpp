class Solution {
public:
    long long getWaviness(long long num) {
        if (num <= 0) return 0;
        string limitStr = to_string(num);
        int n = limitStr.length();
        long long count[2][11][11] = {0};
        long long wave[2][11][11] = {0};
        count[1][10][10] = 1;

        for(int i = 0; i < n; i++){
            long long next_cnt[2][11][11] = {0};
            long long next_wve[2][11][11] = {0};
            for(int j = 0; j < 2; j++){
                for(int k = 0; k <= 10; k++){
                    for(int l = 0; l<= 10; l++){
                        long long curCount = count[j][k][l];
                        long long curWave = wave[j][k][l];
                        if(curCount==0) continue;
                        int limit = j?(limitStr[i]-'0'):9;
                        for(int d = 0; d <= limit; d++){
                            int newTight = j && (d==limit);
                            int newLast = k;
                            int newSecond = l;
                            long long waveAdd = 0;

                            if(k==10){
                                if(d!=0){
                                    newLast = d;
                                    newSecond = 10;
                                }
                            } else {
                                newLast = d;
                                newSecond = k;
                                if(l != 10 && k !=10){
                                    if((l<k&&k>d)||(l>k&&k<d)) waveAdd = 1;
                                }
                            }
                            next_cnt[newTight][newLast][newSecond] += curCount;
                            next_wve[newTight][newLast][newSecond] += curWave + (waveAdd * curCount);
                        }
                        
                    }
                }
            }
            for(int t = 0; t < 2; t++){
                for(int l = 0; l <= 10; l++){
                    for(int sl = 0; sl <= 10; sl++){
                        count[t][l][sl] = next_cnt[t][l][sl];
                        wave[t][l][sl] = next_wve[t][l][sl];
                    }
                }
            }
        }
        long long totalWaviness = 0;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k <= 10; k++){
                for(int l = 0; l <= 10; l++){
                    totalWaviness += wave[j][k][l];
                }
            }
        }
        return totalWaviness;
    }
    long long totalWaviness(long long num1, long long num2) {
         if(num2<100) return 0;
        long long  cnt =0;
        // TLE 970/1013 test case passes ----->>> Brute Force Apporach..
        // for(int i=num1;i<=num2;i++){
        //     string s = to_string(i);
        //     if(s.size()>2){
        //         for(int j=1;j<s.size()-1;j++){
        //             if(s[j]>s[j-1] && s[j]>s[j+1]){
        //                 cnt++;
        //             }
        //             else if(s[j]<s[j+1] && s[j]<s[j-1]){
        //                 cnt++;
        //             }
        //     }
        // }


        // return cnt;
        return getWaviness(num2) - getWaviness(num1 - 1);
    }
};