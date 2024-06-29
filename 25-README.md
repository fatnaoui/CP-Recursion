## Friends Problem Using Recursion
-----------------------------------
Given N friends, who want go to the party on bikes, each guy can go as single or as a couple. Find the number 
in which N friends can go to the party 

To solve this problem, let's take one friend, he is either can go alone or in couple:

the first case is 1*f(n-1) 
the second case he will choose one to go with him C(n-1)(1) == n-1   so we got (n-1)*f(n-2)

And as result f(N) = 1*f(N-1) + (N-1)*f(N-2)
