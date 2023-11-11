Problem Link : https://tinyurl.com/ypln4gw8

Approach : 
This problem is very close to Equal Sum Partition in which s1 == s2 and s1-s2 = 0 
But In this problem abs(s1-s2) = min 

Minimum Subset Sum Difference -> Equal Sum Partition -> Subset Sum Problem 

?? Subset Extreme Partition subset value can be 
1. Subset is empty {} -> Output 0 
2. Subset is equal size of the array -> Output Array element sum 

Eg. arr[] = {1, 2, 7}
  Range can be between 0 to 10 
  conside potential candidate who can be array element 
In this example the potential candidate which can be subset element between 0 to 10 are
  {0, 1, 2, 3, 7, 8, 9, 10}

Logic : 
abs(s2 - s1) where s2> s1 
  s1 + s2 = sum of array elements = Range of array
s2 = Range - s1

abs(s2 - s1)  = Range - s1 - s1 
              = Range - 2s2 -> Minimize 

So, we assume that s2 > s1. Therefore s1 is less that < mid of Range 

Implementation of Example : arr[] = {1, 2, 7}
  s1/s2 = {0, 1, 2, 3, 7, 8, 9, 10} 
  s2 = Range - 2s1 

When s1 = 1 => s2 = 10-2*1 = 8
when s1 = 2 => s2 = 10-2*2 = 6
when s1 = 3 => s2 = 10-2*3 = 4 = Minimum => output

?? How to Find Potential Candidate -> Use subset sum problem where sum = 10 return T  subset exist which are equal to 10 w.r.t to 
size of array otherwise return false 

  


  
