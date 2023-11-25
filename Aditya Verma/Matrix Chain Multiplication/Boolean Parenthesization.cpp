Given : string T | F & T ^ F -> find number of ways to make it true 

string can be = 2 char(T,F) + 3 symbols (T, F, &, |, ^)

Eg. T ^ F & T 
((T ^ F) & T) = T & T = T  
output = 2 

Note -> k can be break on symbols not character

Algorithm 
1. Find i and j 
i = 0 
j = n - 1 
