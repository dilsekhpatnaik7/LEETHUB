class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream st(s);
        string n,m; 
        while(st>>n) {
            m=n;
        }
        return m.size(); 
    }
};