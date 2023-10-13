Brute Force : Recursive Approach 

//User function template for C++

class Solution{   
    private:
    bool helper(vector<int> &arr,int n ,int sum)
    {
        if(sum == 0) return true;
        
        if(n == 0) return false;
        
        if(arr[n-1] <= sum){
    return helper(arr,n-1,sum-arr[n-1]) || helper(arr,n-1,sum);
        }
        
        else{
            return helper(arr,n-1,sum);
        }

    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
helper(arr,n,sum);
    }
};

Better Approach : Memoization 

//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
 int n = arr.size();
   bool t[n+1][sum+1];

 for(int i=0;i<=n;i++)
 {
     for(int j=0;j<=sum;j++){
         if(i==0) {
             t[i][j] = false;
         }
         
        if(j==0){
            t[i][j] = true;
        }
     }
 }
 
 for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
        else{
            t[i][j] = t[i-1][j];
        }
        }
    }
    return t[n][sum];
    }
};
