def maxSumNotAdjacent(array):
    incl = 0
    excl = 0
     
    for i in array: 
          
        # Current max excluding i (No ternary in  
        # Python) 
        new_excl = excl if excl>incl else incl 
         
        # Current max including i 
        incl = excl + i 
        excl = new_excl 
      
    # return max of incl and excl 
    return (excl if excl>incl else incl) 

array = [75,105,120,75,90,135]
print(maxSumNotAdjacent(array))

#https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/