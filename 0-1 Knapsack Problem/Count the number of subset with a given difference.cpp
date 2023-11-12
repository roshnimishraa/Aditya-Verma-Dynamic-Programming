Problem Link : https://tinyurl.com/ywmyj85a

Time Complexity: O(N*K)
Reason: There are two nested loops
Space Complexity: O(N*K)
Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.
  
Eg. arr[] = {1, 1, 2, 3}
  diff : 1 
output : 3 
Explanation : 
subset 1 = {1+3},{1+2} = 4-3 = 1
subset 2 = {1+3}{1+2} = 4-3 = 1
subset 3 = {1+1+2}{3} = 4-3 = 1

Logic 
sum(S1) - sum(S2) = diff - (i) 
sum(S1) + sum(S2) = sum(arr) - (ii) 

  adding (i) and (ii) 
2 sum(S1) = diff + sum(arr) 
  sum(S1) = diff + sum(arr) / 2

sum(S1) = (1+7) / 2 = 4 
  sum(S1) - sum(S2) = diff 
  sum(S2) = sum(S1) - diff 
 sum(S2) = 4 - 1 
  sum(S2) = 3 

Now, this problem reduce to subset sum problem find no of subset equal to sum(S1) 

Count number of subset with given difference -> reduces to -> count of subset sum 

#include <bits/stdc++.h> 
long long mod = 1e9+7;
int countSubsetSum(int n,int sum,vector<int> &arr){
int t[n+1][sum+1];

//initialization
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0){
            t[i][j] = 0;
        }
        if(j==0){
            t[i][j] = 1;
        }
    }
} 
for(int i=1;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
    if(arr[i-1] <= j){
    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % mod;
    }
    else{
        t[i][j] = t[i-1][j] ;
    }
    }
}
return t[n][sum];
}
int countPartitions(int n, int d, vector<int> &arr) {
   int sum=0;
   for(int i=0;i<n;i++){
sum = (sum+arr[i])%mod;
   }
   int s1= (sum+d)/2;
    if((d+sum)%2 != 0) return 0;
   return countSubsetSum(n, s1, arr);
}


v
