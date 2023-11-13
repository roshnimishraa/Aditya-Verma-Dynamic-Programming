Approach : Coin change || 
  matching amount -> n
             coins -> no. of perfect squares
Find Least number of perfect squares 

class Solution {
    public:
    int minCoin(vector<int> &coins,int amount){
    int n = coins.size();
    int t[n+1][amount+1];
//initialization of 1st row and col
for(int i =0;i<n+1;i++){
    for(int j=0;j<amount+1;j++){
        if(i==0){
        t[i][j] = INT_MAX-1;
        }
    else{
    t[i][j] = 0;
    }
    }
}

// Initialization of 2nd row 
for(int i=1;i<n+1;i++){
    for(int j=1;j<amount+1;j++){
if(j% coins[0] == 0){
    t[i][j] = j/coins[0];
} else {
    t[i][j] = INT_MAX - 1;
}
    }
}

for(int i=2;i<n+1;i++){
    for(int j=1;j<amount+1;j++){
if(coins[i-1] <= j){
    t[i][j] = min(t[i][j-coins[i-1]]+1, t[i-1][j]);
}
else{
    t[i][j] = t[i-1][j];
}
    }
}
if(t[n][amount] == INT_MAX-1){
    return -1;
}
return t[n][amount];
    }
    int numSquares(int n) {
        vector<int> coins;
        for(int i = 1;i*i <= n;i++){
            coins.push_back(i*i);
        }
        return minCoin(coins,n);
    }
};
