class Solution {
public:
    int countPrimes(int n) {
        if(n<3)
            return 0;
        
        vector<bool> r(n+1,true);
        r[0]=r[1]=false;
        for(int i=2;i<=sqrt(n);i++){
            if(r[i]){
                for(int j=i*i;j<=n;j=j+i){
                    r[j]=false;
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(r[i])
                c++;
        }
        return c;
    }
};