def mutate(f):
	f[0] = 1

f = [0 for i in range(10)]
mutate(f)
for i in range(len(f)):
	print(f[i])