def sum (freq, i, j):
	s = 0
	for k in list(range(i,j+1)):
		s = s + freq[k]
	return s

def optimalSearchTree(keys, freq, n):
	cost = dict()
	c = 0
	for i in list(range(0,n)):
		cost[(i,i)] = freq[i]
	for L in list(range(0,n+1)):
		for i in list(range(0,n-L+2)):
			j = i + L-1
			cost[(i,j)] = float("inf")
		
			for r in list(range(i,j+1)):
				#c = cost[(i,r-1)] if r > i else 0 + cost[(r+1,j)] if r < j else 0 + sum(freq, i, j)
				if r > i:
					c = c + cost[(i,r-1)]
				if r < j:
					c = c + cost[(r+1,j)]
				
				c = c + sum(freq, i, j)

				if (c < cost[(i,j)]):
					cost[(i,j)] = c
	return cost[(0, n-1)]



keys = [10,12,20]
freq = [34,8,50]

n = len(keys)

num = optimalSearchTree(keys, freq, n)

print ("Custo %s" % num)
