import sys
import itertools
import array

lines=sys.stdin.readlines()
T=int(lines[0])
c=0
while (T>0):
	l=lines[c+1].split()	
	N=int(l[0])
	K=int(l[1])
	arr=lines[c+2].split()
	c=c+2
	for i in range(N+1):
		subset=list(itertools.combinations(arr, i))
		print subset
	T=T-1
