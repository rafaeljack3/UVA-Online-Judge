# @JUDGE_ID: 10189 Python "Minesweeper" 

# @BEGIN_OF_SOURCE_CODE
from sys import stdin

def checkField(FIELD, row, col):
	nrow = [row-1,row-1,row-1,row,row,row+1,row+1,row+1]
	ncol = [col-1,col,col+1,col-1,col+1,col-1,col,col+1]

	M = len(FIELD)
	N = len(FIELD[0])-1

	nmina = 0
	for i in range(len(nrow)):
		if nrow[i] >= 0 and nrow[i] <M:
			if ncol[i] >= 0 and ncol[i] <N:
				if FIELD[nrow[i]][ncol[i]] =='*':
					nmina+=1
	return nmina

def Minesweeper(FIELD,M,N):
	for i in range(0,M):
		for j in range(0,N):
			if FIELD[i][j] == '.':
				nmina = checkField(FIELD,i,j)
				FIELD[i][j]=  str(nmina)



if __name__ == '__main__':
	nfield = 1
	status = False
	while(True):
		FIELD = []
		line = stdin.readline()
		v = line.split()
		M = int(v[0])
		N = int(v[1])
		if M==0 and N==0:
			break
		for x in range(M):
			line = stdin.readline()
			FIELD.append(list(line))
		
		Minesweeper(FIELD,M,N)
		if status:
			print()
		else:
			status = True
		print("Field #"+str(nfield)+":")
		for x in range(0,M):
			print(''.join(FIELD[x]),end='')

		nfield+=1






#@END_OF_SOURCE_CODE*/