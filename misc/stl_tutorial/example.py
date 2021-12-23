# see python syntax from this file: python is useful for problems that involve outputting large numbers

import sys
sys.stdin = open('puzzle.in', 'r')
sys.stdout = open('puzzle.out', 'w')

n = raw_input().split()
a= int(n[0])
b= int(n[1])
c= int(n[2])

count = 0
while(a != 1):
	a = (a + 1) / 2
	count += 1
while(b != 1):
	b = (b + 1) / 2
	count += 1
while(c != 1):
	c = (c + 1) / 2
	count += 1


print(count)