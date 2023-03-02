//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int findLongestConseqSubseq(int arr[], int N) {
        int longestStreak = 0;
        unordered_set<int> hashSet;
        for(int i = 0; i < N; i++) {
            hashSet.insert(arr[i]);
        }
        
        for(int i = 0; i < N; i++) {
            if(!hashSet.count(arr[i] - 1)) {
                int currentNumber = arr[i];
                int currentStreak = 1;
                while(hashSet.count(currentNumber + 1)) {
                    currentNumber++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends