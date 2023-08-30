//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateAllBinaryStrings(int index, int num, string str) {
        if(index == num) {
            cout << str << " ";
            return;
        }
        generateAllBinaryStrings(index + 1, num, str + '0');
        
        
        if(index == 0 || (index > 0 && str[index - 1] != '1')) {
            generateAllBinaryStrings(index + 1, num, str + '1');
        }
    }
    
    void generateBinaryStrings(int num){
        string str="";
        generateAllBinaryStrings(0, num, str);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends