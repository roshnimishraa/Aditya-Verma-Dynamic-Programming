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

Approach 1 : Recursive 

steps 
1. find i and j value 
2. find base condition 
3. move k -> i to j
option 1 : k = i to j-1 -> for(i to k) and for(k+1 to j)
option 2 : k = i+1 to j -> for(i to k-1) and (k to j) 

int solve(int arr[],int i,int j) 
{
  if(i>=j) return 0;
  int mn = INT_MAX;
  for(int k=i;k<=j-1;k++){
    int temp_ans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
    if(temp_ans < mn) {
    mn = temp;
    }
  }
  return mn;
}

Approach 2 : Memoization (Bottom-Up Approach) 

  // User function Template for C++

class Solution{
    
public:
int t[501][501];
int helper(int arr[],int i,int j)
{
    int mn = INT_MAX;
    //base condition
    if(i>=j) return 0;
    if(t[i][j] != -1) return t[i][j];
//move k 
for(int k = i; k<=j-1;k++)
{
    int temp_ans = helper(arr,i,k) + helper(arr,k+1,j)+
                    arr[i-1]*arr[k]*arr[j];

    if(temp_ans < mn)
    {
        mn =temp_ans;
    }
    
}
return t[i][j]=mn;
}
    int matrixMultiplication(int N, int arr[])
    {
        memset(t,-1,sizeof(t));
   return  helper(arr,1,N-1);
    }
};

  
