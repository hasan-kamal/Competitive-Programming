def f(dp, n, i, j):
	if dp[i][j] != -1:
		return dp[i][j]
	if i < j:
		for k in range(i, j):
			dp[i][j] = max(dp[i][j], f(dp, n, i, k) + f(dp, n, k + 1, j))
		return dp[i][j]

	l = 0
	if i < n:
		l = -1
		for k in range(i + 1, n + 1):
			l = max(l, f(dp, n, k, 1) + f(dp, n, k, j))

	r = 0
	if j > 1:
		r = -1
		for k in range(1, j):
			r = max(r, f(dp, n, i, k) + f(dp, n, n, k))

	dp[i][j] = l + r
	return dp[i][j]

tokens = input().split()
n, a_n1 = int(tokens[0]), int(tokens[1])

while len(tokens) == 2:

	dp = [ [-1 for j in range(n + 1)] for i in range(n + 1) ]
	dp[n][1] = a_n1
	print(f(dp, n, 1, n))

	try:
		tokens = input().split()
		n, a_n1 = int(tokens[0]), int(tokens[1])
	except:
		break