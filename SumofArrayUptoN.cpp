//{ Driver Code Starts
#include <iostream>
#include<string.h>
#include<vector>
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
 void comsum(int ind,int sum,vector<int>&arr,int N,vector<int>&answer){
     if(ind == N){
         answer.push_back(sum);
         return;
     }
     sum += arr[ind];
     comsum(ind+1,sum,arr,N,answer);
     
     sum -= arr[ind];
     comsum(ind+1,sum,arr,N,answer);
    
 }
    vector<int> subsetSums(vector<int> arr, int N)
    {   
        vector<int>answer;
        comsum(0,0,arr,N,answer);
        sort(answer.begin(),answer.end());
        return answer;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends