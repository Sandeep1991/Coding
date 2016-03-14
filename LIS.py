def LIS(l):
	cnt = []
	print l
	for j in range(0,len(l)):
		cnt.append(1) 
	print cnt
	for j in range(1,len(l)):
		for k in range(0,j):
			if l[j] > l[k] and cnt[j] < cnt[k] + 1:
				cnt[j] = cnt[k] + 1
	maximum = 0
	for j in range(1,len(l)):
		maximum = max(maximum, cnt[j])		
	return maximum
	
print LIS([3,1,2,3])
