# @JUDGE_ID: 10267 Python "Graphical Editor" 

# @BEGIN_OF_SOURCE_CODE


from sys import stdin

def setClear(IMG,M,N):

	for i in range(1,N+1):
		IMG[i][M+1] = '0'
		for j in range(1,M+1):
			IMG[i][j] = 'O'
			IMG[N+1][j] = '0'
	IMG[N+1][M+1] = '0'


def printIMG(IMG,M,N):
	for i in range(1,N+1):
		for j in range(1,M+1):
			print('%c'%(IMG[i][j]),end='')
		print()

def setRegionR(IMG,M,N,x,y, ncolor):

	color = IMG[y][x]
	if color == ncolor:
		return

	p = (x,y)
	q = [p]
	IMG[y][x] = ncolor
	while len(q)>0 :
		xx,yy = q.pop()
		IMG[yy][xx] = ncolor
		if x >= 1 and IMG[yy][xx-1] == color:
			q.append((xx-1,yy))

		if x <=M and IMG[yy][xx+1] == color:
			q.append((xx+1,yy))

		if y>=1 and IMG[yy-1][xx] == color:
			q.append((xx,yy-1))

		if y<=N and IMG[yy+1][xx] == color:
			q.append((xx,yy+1))

	return

if __name__ == '__main__':
	IMG = [['0' for x in range(252)] for y in range(252)]
	M = 0
	N = 0
	while(True):
		line = stdin.readline()
		ll = line.split()
		if ll[0]=='X':
			break

		if ll[0]=='I':
			M = int(ll[1])
			N = int(ll[2])
			setClear(IMG,M,N)

		if ll[0]=='C':
			setClear(IMG,M,N)

		if ll[0]=='L':
			IMG[int(ll[2])][int(ll[1])] = ll[3]

		if ll[0]=='V':
			y1 = int(ll[2])
			y2 = int(ll[3])
			if y1 > y2:
				tmp = y1
				y1 = y2
				y2 = tmp
			for i in range(y1,y2+1):
				IMG[i][int(ll[1])] = ll[4]
			
		if ll[0]=='H':
			x1 = int(ll[1])
			x2 = int(ll[2])
			if x1 > x2:
				tmp = x1
				x1 = x2
				x2 = tmp

			for j in range(x1,x2+1):
				IMG[int(ll[3])][j] = ll[4]
		if ll[0]=='K':
			x1 = int(ll[1])
			x2 = int(ll[3])
			y1 = int(ll[2])
			y2 = int(ll[4])
			if x1 > x2:
				tmp = x1
				x1 = x2
				x2 = tmp
			if y1 > y2:
				tmp = y1
				y1 = y2
				y2 = tmp

			for i in range(y1,y2+1):
				for j in range(x1,x2+1):
					IMG[i][j] = ll[5]

		if ll[0]=='F':
			x = int(ll[1])
			y = int(ll[2])
			xycolor = IMG[y][x]
			ncolor = ll[3]
			#IMG[y][x] = ncolor
			setRegionR(IMG,M,N,x,y,ncolor)

		if ll[0]=='S':
			print(ll[1])
			printIMG(IMG,M,N)



#@END_OF_SOURCE_CODE*/