//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> stack;
        for(int num : arr) {
            if(stack.empty()) {
                stack.push(num);
            } else {
                if((stack.top() >= 0 && num < 0) || (stack.top() < 0 && num >= 0)) {
                    stack.pop();
                } else {
                    stack.push(num);
                }
            }
        }
    
        vector<int> result;
        while(!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends