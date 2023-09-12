//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void solve(int index, string str, int a[], int N, vector<string>& map, vector<string>& ans) {
        if(index ==  N){
            ans.push_back(str);
            return;
        }
    
        int digit = a[index];
    
        for(auto i: map[digit]) {
            str.push_back(i);
            solve(index + 1, str, a, N, map, ans);
            str.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int N) {
        if(N == 0) return {};
        vector<string> ans;
        vector<string> map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, "", a, N, map, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends