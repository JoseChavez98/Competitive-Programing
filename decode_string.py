
def go(string):
    in_word = False
    final_string = ""
    mult = -1
    word = ""
    l = ""
    for i in string:
        if(i!='[' and i!=']' ):
            if(in_word==False):
                l+=i
            elif in_word and i.isdigit()==False:
                l+=i
            else:
                print()
        if(i=='['):
            mult = int(l)
            l=""
            in_word=True
        if(i==']'):
            word = l
            l=""
            in_word=False
        if(mult!=-1 and len(word)>0):
            final_string+= (mult * word)
            mult=-1
            word=""

    return final_string

print(go("3[a]2[bc]"))