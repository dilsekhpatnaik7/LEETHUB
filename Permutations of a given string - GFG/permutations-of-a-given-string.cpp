//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    void getPermutation(int index, string S, set<string>& res) {
	        if(S.size() == index) {
	            res.insert(S);
	            return;
	        }    
	        for(int i = index; i < S.size(); i++) {
	            swap(S[index], S[i]);
	            getPermutation(index + 1, S, res);
	            swap(S[index], S[i]);
	        }
	    }
	    
		vector<string> find_permutation(string S) {
		    if(!S.length()) return {};
		    
		    set<string> res;
		    vector<string> ans;
		    
		    getPermutation(0, S, res);
		    for(auto i: res) {
		        ans.push_back(i);
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends