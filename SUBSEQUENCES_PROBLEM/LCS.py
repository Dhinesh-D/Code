a=input()
b=input()
m = len(a) 
n = len(b) 
LCS= [[0 for j in range(n+1)] for i in range(m+1)] 
for i in range(m+1): 
	for j in range(n+1): 
		if i == 0 or j == 0: 
			LCS[i][j] = 0
		elif a[i-1] == b[j-1]: 
			LCS[i][j] = LCS[i-1][j-1] + 1
		else: 
			LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]) 
x=LCS[m][n] 
l= [""] * (x+1) 
l[x] = "" 
i = m 
j = n 
while i > 0 and j > 0: 
	if a[i-1] == b[j-1]: 
		l[x-1] = a[i-1] 
		i-=1
		j-=1
		x-=1
	elif LCS[i-1][j] > LCS[i][j-1]: 
		i-=1
	else: 
		j-=1
print(len(l)-1)
