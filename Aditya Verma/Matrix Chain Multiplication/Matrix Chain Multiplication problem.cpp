  cost = Miniumm number of Multiplication 
  Size of Matrix = size of array - 1 = n-1 

Eg. arr[] = { 40, 20, 30, 10, 30} 
    Ai = arr[i-1] * arr[i] 
    size of matrix = n-1 = 5 - 1 = 4
  A1 = arr[0] * arr[1] = 40 * 20 
  A2 = arr[1] * arr[2] = 20 * 30 
  A3 = arr[2] * arr[3] = 30 * 10 
  A4 = arr[3] * arr[4] = 10 * 30 

Logic : Put bracket everywhere solve it recursively and find minimum cost 
take i = 1, j = arr.size() - 1 

Invalid Input 
1. i > j => size 0 
2. i == j => size 1 
if(i>= j) return 0 

Algorithm 
1. Find i and j value => i = 1, j = n-1 
2. Find Base Condition 
3. move k -> i to j 
What should be K value there are two options 
i) k = i to j-1 then it can be partition into two parts such as (a) i to k (b) k+1 to j  
or 
ii) k = i+1 to j then it can be partition into two parts such as (a) i to k-1 (b) k to j 
4. Find temp ans 
  solve(arr,i, k) + solve(arr,k+1,j) + cost 

cost = arr[i-1] * arr[k] * arr[j] 

5. Calculate ans <- temp ans 
return min cost 
initialize mini = INT_MAX 
if(mini > temp) mini = temp 
return mini 

Approach 1 : Recursive 

class Solution{
public:
int solve(int arr[],int i,int j){
    // base case 
    if(i>= j) {
        return 0;
    }
int mini = INT_MAX;    
// move k -> i to j-1
for(int k = i;k<=j-1;k++){
    int cost = arr[i-1] * arr[k] * arr[j];
int temp_ans = solve(arr,i,k) + solve(arr,k+1,j) + cost;
if(temp_ans < mini){
    mini = temp_ans;
}
}
return mini;
}
    int matrixMultiplication(int n, int arr[])
    {
return solve(arr,1,n-1);
    }
};

Approach 2 : Memoization (Bottom-Up Approach) 

class Solution{
public:
int t[501][501];
int solve(int arr[],int i,int j){
    // base case 
    if(i>= j) {
return 0;
    }
    if(t[i][j] != -1) return t[i][j];
int mini = INT_MAX;    
// move k -> i to j-1
for(int k = i;k<=j-1;k++){
    int cost = arr[i-1] * arr[k] * arr[j];
int temp_ans = solve(arr,i,k) + solve(arr,k+1,j) + cost;
if(temp_ans < mini){
    mini = temp_ans;
}
}
return t[i][j] = mini;
}
    int matrixMultiplication(int n, int arr[])
    {
        memset(t,-1,sizeof(t));
return solve(arr,1,n-1);
    }
};
  
