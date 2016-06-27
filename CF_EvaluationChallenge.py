You are given a math Expression with N variables. Their values are given in the array Values, so that Values[0] is the value of variable 'a', Values[1] is the value of variable 'b', and so on.

The expression contains variables, brackets (( , )), binary operators (+,-,*) and unary operators (-,+,[]), where [] means square of a number (E.g. [5] = 25).

Order of priority:

Unary Operators;
Operator *;
Operators +,-;
The expression doesn't contain spaces (' ').
Your task is to return the value of the given expression.

Example

Evaluation(1, [1], "a+a") = 2;
Evaluation(2, [0,25], "[b*a]+--b") = 25;
Evaluation(3, [1,2,3], "[a]*(b+c)*(a*a+b*--+c)-c") = 32;
Evaluation(1,[1],"-+++a") = -1, since -+++a = -(+(+(+(a))));
Evaluation(3,[1,1,1],"(((-((+(a+b+c))))))" = -3.
Input/Output

[time limit] 4000ms (py)
[input] integer N

Number of variables.

Constraints:
1 ≤ N ≤ 26

[input] array.integer Values

Value of each variable.

Constraints:
Values.length = N,
-106 ≤ Valuesi ≤ 106.

[input] string Expression

The expression.

Constraints:
1 ≤ Expression.length < 5 * 104.

[output] string

Value of Expression.


"""
V = dict()
	L = list(string.ascii_lowercase)
	for ind in range(0,len(Values)):
		V[L[ind]] = Values[ind]

	se = Expression
	xe =''
	for inde in se:
		if inde=='[': xe = xe+'('
		elif inde==']': xe = xe +')**2'
		elif inde>='a' and inde <= 'z': xe = xe + str(V[inde])
		else: xe = xe + inde
	te = eval(xe)
	return te
	
print Evaluation(1,[1],"a+a")
print Evaluation(2,[0,25],"[b*a]+--b")
