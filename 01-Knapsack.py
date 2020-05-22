# result = []

# def knapsack(items, index, capacity):
#     if capacity == 0 or index < 0:
#         return 0

#     elif items[index][1] > capacity:
#         return knapsack(items, index - 1, capacity)

#     takingValue = items[index][0] + knapsack(items, index - 1, capacity - items[index][1])

#     # if(items[index] not in result):
#     #     result.append(items[index])

#     notTakingValue = knapsack(items, index - 1, capacity)

#     return max(takingValue,notTakingValue)

#     # if(takingValue>=notTakingValue):
#     #     print(takingValue,notTakingValue)
#     #     if(items[index] not in result):
#     #         result.append(items[index])
#     #     return takingValue
#     # else:
#     #     return notTakingValue


################################################################################
################################################################################
class Cell:
    def __init__(self, value, whereFrom):
        self.value = value
        self.whereFrom = whereFrom

def printTable(table):
    for i in range(len(table)):
        for j in range(len(table[0])):
            print(table[i][j].value,end=" ")
        print()

def knapsack_bottomUp(items, weight):
    row = [Cell(0, "none") for i in range(weight + 1)]
    
    table = [list(row) for i in range(len(items))]

    for item in range(len(items)):
        for capacity in range(weight + 1):
            print("---------------------")
            print(item,capacity)
            print()
            if items[item][1] > capacity:
                print("continue")
                continue
                # poner direccion
            elif(item-1>=0):
                # print(items[item][0]+ table[item-1][capacity-items[item][1]].value,table[item-1][capacity].value)

                print(table[item-1][capacity-items[item][1]].value)

                table[item][capacity].value = max(items[item][0]+ table[item-1][capacity-items[item][1]].value,table[item-1][capacity].value)
                
                print(table[item-1][capacity-items[item][1]].value)

                # poner direccion
            else:
                table[item][capacity].value = items[item][0]
                print(table[item][capacity].value)
        print()
        print("###############################")
        print()
    printTable(table)
    return table[-1][-1].value



items = [(1, 2), (4, 3), (5, 6), (6, 7)]  # value - weight

capacity = 10

print(knapsack_bottomUp(items, capacity))
# print(knapsack(items, len(items) - 1, capacity))
# print(result)
