def minMax(array):
    mini = 1000000
    maxi = -100000
    for i in array:
        maxi = max(maxi, i)
        mini = min(mini, i)
    return (mini, maxi)


def minWSort(array):
    values = minMax(array)
    mini = values[0]
    maxi = values[1]

    flag = [False, False]

    p1 = 0
    p2 = len(array)-1

    init = [-1, False]
    end = [-1, False]

    if(array[p1] > mini):
        flag[0] = True
        init[0] = p1
        init[1] = True
    if(array[p2] < maxi):
        flag[1] = True
        end[0] = p2
        end[1] = True

    while(init[1] == False or end[1] == False):
        if(array[p1] < mini and flag[0] == False):
            init[0] = p1-1
            init[1] = True
        elif(flag[0] == False):
            mini = array[p1]
            p1 += 1
        if(array[p2] > maxi and flag[1] == False):
            end[0] = p2+1
            end[1] = True
        elif(flag[1] == False):
            maxi = array[p2]
            p2 -= 1
            # flag[1]=True
        if(p1 == p2):
            return 0

    return end[0] - init[0] + 1


print(minWSort([1, 2, 5, 3, 7, 10, 9, 12]))
print(minWSort([1, 3, 2, 0, -1, 7, 10]))
print(minWSort([1, 2, 3]))
print(minWSort([3, 2, 1]))
