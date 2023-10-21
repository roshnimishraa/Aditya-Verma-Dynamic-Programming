Approach : Top - Down  

Time Complexity: O(sum * n), where n is the size of the array.
Auxiliary Space: O(sum*n), as the size of the 2-D array is sum*n.

class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int sum){
int n = arr.size();
int t[n+1][sum+1];
for(int i=0;i<n+1;i++)
{
    for(int j=0;j<sum+1;j++)
    {
// making first row = false
        if(i == 0)
        {
            t[i][j] = false;
        }
        // [0,0] = true
        if(j==0)
        {
            t[i][j] = true;
        }
    }
}
//here i -> n && j -> sum 
for(int i=1;i<n+1;i++)
{
    for(int j=1;j<sum+1;j++)
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
