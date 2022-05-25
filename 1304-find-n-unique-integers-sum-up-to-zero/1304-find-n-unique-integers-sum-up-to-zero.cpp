class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> a(n);
        for(int i=0;i<n;i++)
            a[i]=(i*2)-n+1;
        return a;
    }
};