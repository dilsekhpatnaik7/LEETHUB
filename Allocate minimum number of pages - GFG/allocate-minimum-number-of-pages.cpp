//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution {
public:
    int findMax(int A[], int N) {
        int maximum = INT_MIN;
        for(int i = 0; i < N; i++) {
            maximum = max(maximum, A[i]);
        }
        return maximum;
    }
    
    int summation(int A[], int N) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += A[i];
        }
        return sum;
    }
    
    bool canAllocate(int A[], int N, int pageCapacity, int noOfStudents) {
        int students = 1, pages = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] + pages <= pageCapacity) pages += A[i];
            else {
                students++;
                pages = A[i];
            }
            if(students > noOfStudents) return true;
        }
        return false;
    }
    
    int findPages(int A[], int N, int M) {
        if(M > N) return -1;
        int low = findMax(A, N);
        int high = summation(A, N);
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(canAllocate(A, N, mid, M)) low = mid + 1;
            else high = mid -1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends