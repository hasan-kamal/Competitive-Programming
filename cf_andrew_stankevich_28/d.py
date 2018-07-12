import sys
out = sys.stdout
sys.stdin = open('dinner.in', 'r')
sys.stdout = open('dinner.out', 'w')

s = raw_input()
l = s.split()
k_d = int(l[0])
n_d = int(l[1])

nCr = [[0] * 101 for _ in xrange(101)]

for n in range(1, 101):
	for r in range(101):
		if(r == 0 or r == n):
			nCr[n][r] = 1
			continue
		elif(r > n):
			nCr[n][r] = 0
			continue
		else:
			nCr[n][r] = nCr[n - 1][r - 1] + nCr[n - 1][r]

grid = [[0] * 101 for _ in xrange(101)]

# grid[k][n]
grid[1][0] = 0
for n in range(1, 101):
	grid[1][n] = 1

for k in range(2, 101):
	for n in range(1, 101):
		if(n < k):
			grid[k][n] = 0
			continue

		ans = 0
		for i in range(0, n):
			ans += nCr[n - 1][i] * grid[k - 1][n - i - 1]
		grid[k][n] = ans * k

print(grid[k_d][n_d])