# use python3
dp = [[0 for i in range(61)] for j in range(61)]
for i in range(61):
	dp[0][i] = 1
	dp[1][i] = 1

for i in range(2, 61):
	dp[i][0] = 1
	for j in range(1, 61):
		dp[i][j] = 1
		for k in range(1, j + 1):
			dp[i][j] += 1 if i - k < 0 else dp[i - k][j]

token = input().split()
n, m = int(token[0]), int(token[1])
t = 0
while(n <= 60):

	print('Case {}: {}'.format(t + 1, dp[n][m] if n >= 0 else 1))
	t += 1

	token = input().split()
	n, m = int(token[0]), int(token[1])