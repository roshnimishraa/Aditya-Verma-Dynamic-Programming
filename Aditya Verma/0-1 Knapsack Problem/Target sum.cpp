Problem Link : https://leetcode.com/problems/target-sum/

//This question same as number of subset with given difference
/* Time Complexity - O(n * target)
Space Complexity - O(n * target) tabulation solution
*/


class Solution {
public:
int countSubsetSum(int sum,vector<int> &arr,int n){
    int t[n+1][sum+1];
    //initialization
for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0){
            t[i][j] = 0;
        }
        if(j == 0){
            t[i][j] = 1;
        }
    }
}
    
for(int i=1;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
    if(arr[i-1] <= j){
t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
    }
    else{
        t[i][j] = t[i-1][j];
    }
    }
}
return t[n][sum];
}
    int findTargetSumWays(vector<int>& nums, int target) {
  int sum=0;
  int n = nums.size();
target = abs(target);
  for(int i=0;i<n;i++){
sum += nums[i];
  }      
  int s1 = (target+sum)/2;
  if(sum < target || (sum + target) % 2 != 0){
      return 0;
  }
  return countSubsetSum(s1,nums,n);
    }
};
