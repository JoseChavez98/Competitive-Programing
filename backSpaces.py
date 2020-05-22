from collections import deque

# def computeWord(word):
#     stack = deque()
#     newWord=[]
#     i=0
#     for character in word:
#         if(character=='#' and len(stack)>0):
#             stack.pop()
#         else:
#             stack.append(character)
#     while(i <len(stack)):
#         newWord.insert(1,stack.pop())
#         i+=1
#     return newWord
    
# def backSpaces(word1, word2):
#     newW1 = computeWord(word1)
#     newW2 = computeWord(word2)
#     if(newW1 == newW2):
#         return True
#     else:
#         return False

# print(backSpaces("xy#z","xzz#"))
# print(backSpaces("xy#z","xyz#"))
# print(backSpaces("xp#","xyz##"))


def computeWord(word):
    countOfBS = 0
    p1=0
    p2=0
    for character in reversed(word):
        if(word[p2]=='#'):
            countOfBS+=1
            p2-=1
        if(word[p2]!='#'):
            if(countOfBS):
                countOfBS-=1
                continue
            else:
                word[p1]=word[p2]
        else:
            p1-=1
            p2-=1
    return word[p1:len(word)-1]

def backSpaces(word1,word2):
    newW1 = computeWord(word1)
    newW2 = computeWord(word2)
    if(newW1 == newW2):
        return True
    else:
        return False

print(backSpaces("xy#z","xzz#"))
print(backSpaces("xy#z","xyz#"))
print(backSpaces("xp#","xyz##"))
 