t=int(raw_input())
for i in range(0,t):
	n,k = map(int,raw_input().split(' '))
	lst_set=[]
	for j in range(0,n):
		lst_set.append(set(map(int,raw_input().split(' '))))
	cnt_set=len(lst_set)
	union_set=set([])
	c=0
	f1=0
	f2=0
	for st in lst_set:
		c += 1
		union_set=union_set.union(st)
		if union_set == set(range(1,k+1)) and c != cnt_set:
			f1 = 1
			break
		elif union_set == set(range(1,k+1)) and c == cnt_set:
			f2 = 1
		
			
			
	#print union_set, set(range(1,k+1))
	if f1 == 1:
		print "some"
	elif f2 == 1:
		print "all"
	else:
		print "sad"
		
	'''
	if union_set != set(range(1,k+1)):
		print "sad"
	else:
		f=0
		if f!=1:
			for ind in range(0,len(lst_set)):
				if f!=1:
					for in_ind in range(0,len(lst_set)):
						if ind != in_ind and lst_set[ind].issubset(lst_set[in_ind]):
							print "some"
							f=1
							break
		if f!=1:
			print "all"
	'''
