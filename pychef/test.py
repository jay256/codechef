import sys

lines=sys.stdin.readlines()
T=int(lines[0])
lines=lines[1:]
for line in lines:
	steplist=list(line)
	tmp=1
	result=1
	for steps in steplist:
		if tmp%2==1:		
			if steps=="l":		
				result=2*result
			elif steps=="r":
				result=2*result+2
		elif tmp%2==0:
			if steps=="l":
				result=2*result-1
			elif steps=="r":
				result=2*result+1
		tmp=tmp+1	
	print result
