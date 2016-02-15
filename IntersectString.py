#Intersection of two strings
#Task is to print the characters in string s1 and s2 namely
#Sort them and return them. Also, account for the repeated characters

def  IntersectStrings( first,  second):
    x = list(first)
    #print x
    y = list(second)
    lst1= []
    lst2= []
    for i in x:
        if i in y:
            lst1.append(i)
    lst2 = sorted(lst1) + []
    return ''.join(lst2)
#    return sorted(''.join(lst1))
print IntersectStrings('hello','mello' )
