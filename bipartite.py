 '''
 This question appeared in Codefights as a day challenge.
 
 The Gangsteranos family has been through a lot of trouble lately. With all the quarrels that have been breaking out, the family is starting to lose its authority on the streets, and it's time to do something about it.

The Father decided to start dealing with the troublemakers without making decisions that are too harsh. To begin with, he wants to try to split the family into two groups, such that in each group no two members hate one another.

Given haters, the list of family members who hate each other, figure out if it's possible to split them into two groups like Father wants.

Psst: Here's the Vietnamese version of the description.

Example

For haters = ["Dead_Bowie Fake_Thomas_Jefferson"], the output should be
theFather(haters) = true.

Since only two members of the family hate one another, they can be put into separate groups.

For

haters = ["Dead_Bowie Fake_Thomas_Jefferson", 
          "Fake_Thomas_Jefferson Fury_Leika", 
          "Fury_Leika Dead_Bowie"]
the output should be
theFather(haters) = false.

There's no way to split the haters into two groups as Father wants.

Input/Output

[time limit] 500ms (cpp)
[input] array.string haters

An array of pairs of family members who hate one another and can't be put into one group. Each pair is given as a string, with the two names separated by a single whitespace character. It is guaranteed that no person hates themselves.

Guaranteed constraints:
1 ≤ haters.length ≤ 13000,
3 ≤ haters[i].length ≤ 100.

[output] boolean

Return true if it's possible to split the family members into two groups like Father wants, otherwise return false.

'''
 
 def bipartite(h):
	r =set()
	b =set() 
	visited=set()
	m={}
	for i in h:
		k=i.split(" ")[0]
		l=i.split(" ")[1]
		if k not in m:
			m[k]=[]
		if l not in m:
			m[l]=[]
		m[k].append(l)
		m[l].append(k)
	print m
	ql=[m[k][0]]
	for key in ql:
		#ql=ql[1:]
		if key not in visited:
			visited.add(key)
			if (key not in b and key not in r) or key in b:
				b.add(key)
				for j in m[key]:
					if j in b:
						return False
					r.add(j)
					ql.append(j)
					#visited.add(j)
			else:
				r.add(key)
				for j in m[key]:
					if j in r:
						print "-----------------------------"
						print r
						print b
						return False
					b.add(j)
					ql.append(j)
					#visited.add(j)
	print "-----------------------------"
	print r
	print b
	return True
	
#print k 
#print l 
'''
print bipartite(["Sun_Girl Golddigger", 
 "Jewelee Golddigger", 
 "Zaladane Deuce", 
 "Sun_Girl Deuce", 
 "Mai_Shen Golddigger", 
 "Jewelee Lazara", 
 "Mai_Shen Lazara", 
 "Sun_Girl Lazara", 
 "Zaladane Lashina", 
 "Jewelee Lashina"])
'''
print bipartite(["a b","d c","b c"])
#print bipartite(["Dead_Bowie Fake_Thomas_Jefferson"]) 
 #"Fake_Thomas_Jefferson Fury_Leika", 
 #"Fury_Leika Dead_Bowie"])
