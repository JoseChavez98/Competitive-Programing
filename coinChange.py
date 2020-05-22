def coinChange(array,amount): 
 
    table = [0 for k in range(amount+1)] 
  
    table[0] = 1
  
    for i in range(0,len(array)): 
        for j in range(array[i],amount+1): 
            table[j] += table[j-array[i]] 
  
    return table[amount] 


# array = [1,5]
array = [1,2,3]
# amount = 6
amount=4

print(coinChange(array,amount))

#https://www.geeksforgeeks.org/coin-change-dp-7/