#Codechef easy problem pay up
def Paying():
    #t = int(raw_input())
    #t = int(t)

    #for i in range(0,t):
        dict = set()
        n,m = map(int,raw_input().split())

        target = m
        #target = int(target)
        lst = []
        for i in range(0,n):
            a = int(raw_input())
            lst.append(a)
            #lst[i-1] = int(k)
        #print lst
        flag = 0

        for j in lst:
            if(j==target):
                print "YES"
                flag = 1
                break
            else:
                if(target-j in dict):
                    print "YES"
                    flag = 1
                    break
                else:
                    dict.add(j)
        if flag == 0:
          print "NO"

t = int(raw_input())
    #t = int(t)

for i in range(0,t):
  Paying()
