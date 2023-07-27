//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int>& bloomDay, long long day, int M, int K) {
        int count = 0, noOfBouquet = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) count++;
            else {
                noOfBouquet += (count / K);
                count = 0;
            }
        }
        noOfBouquet += (count / K);
        return noOfBouquet >= M;
    }
    
    int solve(int M, int K, vector<int> &bloomDay){
        if(((long long)M * (long long)K) > bloomDay.size()) return - 1;
        int minimum = INT_MAX, maximum = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++) {
            minimum = min(minimum, bloomDay[i]);
            maximum = max(maximum, bloomDay[i]);
        }

        int low = minimum, high = maximum;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(isPossible(bloomDay, mid, M , K)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends