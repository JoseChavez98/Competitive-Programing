from collections import deque

def find_max_sliding_window(arr, w):
    myQ =deque()
    for i in range(w):
        while(myQ and arr[i]>=arr[myQ[-1]]):
            myQ.pop()
        myQ.append(i)

    for i in range(w, len(arr)): 
          
       
        print(str(arr[myQ[0]]) + " ", end = "") 
          
        
        while myQ and myQ[0] <= i-w: 
              
            
            myQ.popleft()  
          
        
        while myQ and arr[i] >= arr[myQ[-1]] : 
            myQ.pop() 
          
        
        myQ.append(i) 
      
    
    print(arr[myQ[0]]) 

array = [10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67]
find_max_sliding_window(array,3)