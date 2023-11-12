Problem Link : https://tinyurl.com/ywmyj85a

Eg. arr[] = {1, 1, 2, 3}
  diff : 1 
output : 3 
Explanation : 
subset 1 = {1+3},{1+2} = 4-3 = 1
subset 2 = {1+3}{1+2} = 4-3 = 1
subset 3 = {1+1+2}{3} = 4-3 = 1

Logic 
sum(S1) - sum(S2) = diff - (i) 
sum(S1) + sum(S2) = sum(arr) - (ii) 

  adding (i) and (ii) 
2 sum(S1) = diff + sum(arr) 
  sum(S1) = diff + sum(arr) / 2

sum(S1) = (1+7) / 2 = 4 
  sum(S1) - sum(S2) = diff 
  sum(S2) = sum(S1) - diff 
 sum(S2) = 4 - 1 
  sum(S2) = 3 

Now, this problem reduce to subset sum problem find no of subset equal to sum(S1) 

Count number of subset with given difference -> reduces to -> count of subset sum 

