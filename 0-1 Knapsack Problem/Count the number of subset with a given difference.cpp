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

int count(vector<int>& arr,int n,int sum){

    int dp[n+1][sum+1];

    int mod=(int)(1e9+7);

    for(int i=0;i<=n;i++){

        for(int j=0;j<=sum;j++){

            dp[i][j]=0;

        }

    }

    dp[0][0]=1;

    for(int i=1;i<=n;i++){

        for(int j=0;j<=sum;j++){

            if(arr[i-1]<=j)

                dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%mod;

            else dp[i][j]=dp[i-1][j];

        }

    }
  return dp[n][sum];

}

int countPartitions(int n, int d, vector<int> &arr) {

    int sum=0;

    for(int i:arr)sum=(sum+i)%(int)(1e9+7);
 int wanted=(sum+d)/2;

    if((d+sum)%2 != 0) return 0;

    return count(arr,n,wanted);

}
