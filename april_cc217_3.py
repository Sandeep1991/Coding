t=int(raw_input())
for i in range(0,t):
	s=raw_input()
	c0=0; c1=0; cnt=0; f1=0;f2=0
	for i in range(0,len(s)):
		if i==len(s)-1 and s[i]=='0':
			c0 += 1
			cnt += c1 * (c0+1)
			#print cnt
		if s[i] == '1' and f1==1:
			cnt += c1 * (c0+1)
			#print cnt,
			c0=0
		if s[i]=='1':
			c1 += 1
			f1=0
		if s[i] == '0' and c1!=0:
			c0+=1
			f1=1
	print cnt
