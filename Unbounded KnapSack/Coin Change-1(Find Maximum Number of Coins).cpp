Problem Link : https://practice.geeksforgeeks.org/problems/coin-change2448/1

Find : Maximum number of ways of coins to make a given sum

Eg. coins[] = {1, 2, 3}
    sum : 5
O/P : 5 
Explanation : 2 + 3 = 5
             1 + 2 + 2 = 5
          1 + 1 + 3 = 5 
           1 + 1 + 1 + 1 + 1 = 5
          1 + 1 + 1 + 2 = 5

  Time complexity : O(N*sum)
Auxiliary Space : O(N*sum)
  
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {
long long int t[n+1][sum+1];

//initialization 
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i== 0){
            t[i][j] = 0;
        }
    if(j == 0){
        t[i][j] = 1;
    }
    }
}

for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
    if(coins[i-1] <= j){
    // find maximum number of ways
t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
    }
    else{
        t[i][j] = t[i-1][j];
    }
    }
}
return t[n][sum];
    }
};
