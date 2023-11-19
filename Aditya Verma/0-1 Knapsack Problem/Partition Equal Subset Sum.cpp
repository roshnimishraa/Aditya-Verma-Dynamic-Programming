Problem Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

Approach : Subset Sum + Even sum partition 

Eg. Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
  Here sum of array elements = 22 which is even that means it can be divided into two parts 
if in array there exist sum/2(find using subset sum) exist it implies that remaining sum/2 will also present in this case return true


Time Complexity: O(sum * N) 
Auxiliary Space: O(sum * N)
  

class Solution{
    bool subsetSum(int n,int arr[],int sum)
    {
        bool t[n+1][sum+1];
        //initialization 
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j] = true;
            }
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
        if(arr[i-1] <= j){
    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        }
    else{
        t[i][j] = t[i-1][j];
    }
        }
    }
    return t[n][sum];
    }
public:
    int equalPartition(int n, int arr[])
    {
     int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    bool isEqual =false;
    if(sum % 2 !=0){
        return 0;
    }
else if(sum% 2 == 0){
    isEqual = subsetSum(n,arr,sum/2);
}
if(isEqual){
    return 1;
}
return 0;
    
    }
};
