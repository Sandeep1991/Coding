# CC https://www.codechef.com/JUNE16/problems/CHEARMY/
t = int(raw_input())
while(t):
	k = int(raw_input())
	sol = 2 * (k-1) + (k-1) / 5 * 10 + (k-1) / 25 * 100 + (k-1) /125 * 1000 + (k-1)/625 * 10000 + (k-1) /3125 * 100000 + (k-1)/15625 * 1000000 +\
		(k-1) / 78125 * 10000000 + (k-1) / 390625 * 100000000 + (k-1) / 1953125 * 1000000000 + (k-1) / 9765625 * 10000000000 +\
		(k-1) / 48828125 * 10000000000 + (k-1)/244140625 * 100000000000 + (k-1)/1220703125 *1000000000000 +\
		(k-1)/ 6103515625 *10000000000000 + (k-1)/30517578125 *100000000000000 + (k-1)/152587890625 *1000000000000000 +\
		(k-1)/762939453125 *10000000000000000 + (k-1)/3814697265625 *100000000000000000
	print sol
	t = t - 1
