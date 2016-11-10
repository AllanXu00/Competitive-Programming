a = eval(raw_input())
findy = {}
words = []
while (a > 0):
	temp = (raw_input())
	if (temp == ''):
		c = 1
		for i in range (len(words)):
			for j in range(len(words[i])):
				findy[words[i][j]] = 0
		for i in range (len (words)):
			for j in range(len(words[i])):
				if (findy[words[i][j]] == 0):
					if (j == len(words[i]) -1): 
						print words[i][j]
					else: 
						print words[i][j],
					findy[words[i][j]] = c
					c = c + 1

				else:
					if (j == len(words[i]) -1): print findy[words[i][j]]
					else: print findy[words[i][j]],
		a = a - 1		
		while len(words) > 0:
			words.pop()
		findy.clear()
	else:
		words.append(temp.split())
		
