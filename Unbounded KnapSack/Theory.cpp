In unbounded knapsack multiple occurances of a same item is allowed 

There are two possibility to choose an item 
1. Not take -> It is sure that in remaining operation it is not going to be take -> These item are processed

2. Take -> Not processed -> It is sure that it can be again taken therefore this item is not processed

>> Variations of Unbounded KnapSack
1. Rod Cutting
2. Coin Change - I 
3. Coin Change - II
4. Maximum Ribbon Cut 

>> Unbounded Code 

int un_KnapSack(int W,int wt[],int val[],int n)
//initialization 
for(int i=0;i<n+1;i++){
for(int j= 0;j<W+1;j++){
if(i==0 || j==0){
t[i][j] = 0
  }
}
} 

for(int i=1;i<n+1;i++){
for(int j=1;j<W+1;j++){
if(arr[i-1] <= j){
t[i][j] = max(val[i-1] + un_KnapSack(t[i][j-arr[i-1]] , un_KnapSack(t[i-1][j])
  }
  else{
    un_KnapSack(t[i-1][j]
  }
}
}
return t[n][W];
}
