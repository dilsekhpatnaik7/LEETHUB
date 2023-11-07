//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int largestRectangleArea(vector<int>& histo) {
    	stack<int> st;
    	int maxA = 0;
    	int n = histo.size();
    	for(int i = 0; i <= n; i++) {
    		while(!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
    			int height = histo[st.top()];
    			st.pop();
    			int width;
    			if(st.empty()) width = i;
    			else width = i - st.top() - 1;
    			maxA = max(maxA, width * height);
    		}
    		st.push(i);
    	}
    	return maxA;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maximum = 0;

    	vector<int> heights(m, 0);
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			if(M[i][j] == 1) heights[j]++;
    			else heights[j] = 0;
    		}
    
    		int area = largestRectangleArea(heights);
    		maximum = max(maximum, area);
    	}
    	return maximum;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends