def gcd(a, b):
	if(a % b == 0):
		return b
	return gcd(b, a % b)

import sys
out = sys.stdout
sys.stdin = open('toral.in', 'r')
sys.stdout = open('toral.out', 'w')
s = raw_input().split()
n = int(s[0])
m = int(s[1])
print(gcd(n, m))