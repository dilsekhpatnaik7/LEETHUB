//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insertAtPosition(int x, stack<int>& St) {
        if(St.size() == 0) St.push(x);
        else {
            int a = St.top();
            St.pop();
            insertAtPosition(x, St);
            St.push(a);
        }
    }

    void reverse(stack<int>& St) {
        if(St.size() > 0) {
            int x = St.top();
            St.pop();
            reverse(St);
            insertAtPosition(x, St);
        }
    }
    void Reverse(stack<int> &St){
        reverse(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends