Problem Link : https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

Approach : Top - Down  

Time Complexity: O(sum * n), where n is the size of the array.
Auxiliary Space: O(sum*n), as the size of the 2-D array is sum*n.

class Solution{   
public:
bool t[101][10005];
    bool isSubsetSum(vector<int>arr, int sum){
    //base condition 
    // if sum == 0 then output will be empty set -> true
    // if array is empty then no output -> false
    int n = arr.size();
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i == 0){
                    t[i][j] = false;
                }
                if(j==0){
                    t[i][j] = true;
                }
            }
        }
        
    for(int i =1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++){
            
    if(arr[i-1] <= j){
        t[i][j] = t[i-1][j-arr[i-1]]|| t[i-1][j];
        
    }
    else {
t[i][j] = t[i-1][j];
    }
        }
    }
        
        return t[n][sum];
    }
};
