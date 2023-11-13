Find : Minimum number of coins to make given sum 

Approach : Unbounded knapsack + 2nd row initialization 

Time Complexity: O(N*T)
Reason: There are two nested loops
Space Complexity: O(N*T)
Reason: We are using an external array of size ‘N*T’. Stack Space is eliminated.
  
#include <bits/stdc++.h> 
int minimumElements(vector<int> &coin, int sum)
{
    int n = coin.size();
    int t[n+1][sum+1];
 //Initialization 1st row and 1st col
for(int i=0;i<n+1;i++)
{
    for(int j=0;j<sum+1;j++){
        if(i==0){
        t[i][j] = INT_MAX - 1;
        }
    if(j == 0){
    t[i][j] = 0;
    }
    }
}

// Initialization of 2nd row 
for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
if(j% coin[0] == 0){
    t[i][j] = j/coin[0];
} else {
    t[i][j] = INT_MAX - 1;
}
    }
}

for(int i=2;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
    if(coin[i-1] <= j){
    t[i][j] = min(t[i][j-coin[i-1]] + 1,
    t[i-1][j]);
    }
else{
    t[i][j] = t[i-1][j];
}
    }
}
if(t[n][sum] == INT_MAX-1)
{
    return -1;
}
return t[n][sum];
}
