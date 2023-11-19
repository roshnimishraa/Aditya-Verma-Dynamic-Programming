Problem Link : https://tinyurl.com/yot3wjca

Time Complexity: O(n2), In the worst case, all possible combinations of partitions are found and because subproblems are 
stored they need not be recalculated.
Auxiliary Space: O(n2) where ‘N’ is the length of the rod.Since we are using a 2 - D array of 
size (N + 2) rows and (N + 2) columns, therefore, overall space complexity will be O(N ^ 2).

  Approach : Unbounded KnapSack
Find : Maximum Profit 

class Solution{
  public:
    int cutRod(int price[], int n) {
      int length[n];
      for(int i= 0;i<n;i++){
          length[i] = i+1;
      }
      
     int t[n+1][n+1];
     
 for(int i=0;i<n+1;i++){
     for(int j=0;j<n+1;j++){
         if(i== 0 || j==0) {
             t[i][j] = 0;
         }
     }
 }
     
     for(int i=1;i<n+1;i++){
         for(int j=1;j<n+1;j++){
             if(length[i-1] <= j) {
        // find max profit 
        t[i][j] = max (price[i-1] + t[i][j-length[i-1]] , t[i-1][j]);
             }
    else {
        t[i][j] = t[i-1][j];
    }
         }
     }
     return t[n][n];
    }
};
