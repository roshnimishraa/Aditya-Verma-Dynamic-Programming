Problem Link : https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

>>>> Similar to subset sum but in subset sum if it is possible then true 
In this problem return count of subset 

Imp : such that t[i][j] stores true if sum j is possible with array elements from 0 to i. 
  we store the path before reaching it and consider two possibilities for the element. 

Element is included in the current path. 
Element is not included in the current path.
Whenever the sum becomes 0, we stop the recursive calls and print the current path.

Time Complexity: O(n * sum), As we are using a nested for loop of size n*sum.
Space Complexity: O(n * sum), due to the 2D dp array

class Solution{

	public:
	
	int perfectSum(int arr[], int n, int sum)
	{
	    int t[n+1][sum+1];
	    long long mod = 1e9+7;
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
            if(arr[i-1] <=j)
            {
    t[i][j] =(t[i-1][j-arr[i-1]]%mod) + (t[i-1][j] % mod);
            }
            else {
    t[i][j] = t[i-1][j] % mod;
            }
        }
    }
    // return count of subset with given sum
   return t[n][sum]%mod;
	}
	  
};
