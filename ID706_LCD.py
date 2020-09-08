# @JUDGE_ID: 10189 Python "Minesweeper" 

# @BEGIN_OF_SOURCE_CODE
from sys import stdin

def buildDisplay(LCD,digit,pos,s,ndigit,flag):
	n_row = 2*s+3
	n_col = s+2

	for i in range(n_row):
		for j in range(n_col+flag):
				LCD[i][j+pos] = ' '

	if digit == '0':
		for i in range(1,s+1):
			LCD[0][i+pos] = '-'
			LCD[2*s+2][i+pos] = '-'

			LCD[i][0+pos] = '|'
			LCD[i+s+1][0+pos] = '|'
			LCD[i][s+1+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'
		return
	if digit == '1':
		for i in range(1,s+1):
			LCD[i][s+1+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'
		return
	if digit == '2':
		for i in range(1,s+1):
			LCD[0][i+pos] = '-'
			LCD[s+1][i+pos] = '-'
			LCD[2*s+2][i+pos] = '-'

			LCD[i][s+1+pos] = '|'
			LCD[i+s+1][0+pos] = '|'
		return
	if digit == '3':
		for i in range(1,s+1):
			LCD[0][i+pos] = '-'
			LCD[s+1][i+pos] = '-'
			LCD[2*s+2][i+pos] = '-'

			LCD[i][s+1+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'
		return
	if digit == '4':
		for i in range(1,s+1):
			LCD[s+1][i+pos] = '-'


			LCD[i][0+pos] = '|'
			LCD[i][s+1+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'
		return
	if digit == '5':
		for i in range(1,s+1):
			LCD[0][i+pos] = '-'
			LCD[s+1][i+pos] = '-'
			LCD[2*s+2][i+pos] = '-'


			LCD[i][0+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'
		return
	if digit == '6':
		for i in range(1,s+1):
			LCD[0][i+pos] = '-'
			LCD[s+1][i+pos] = '-'
			LCD[2*s+2][i+pos] = '-'


			LCD[i][0+pos] = '|'
			LCD[i+s+1][0+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'

		return
	if digit == '7':
		for i in range(1,s+1):
			LCD[0][i+pos] = '-'

			LCD[i][s+1+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'

		return
	if digit == '8':
		for i in range(1,s+1):
			LCD[0][i+pos] = '-'
			LCD[s+1][i+pos] = '-'
			LCD[2*s+2][i+pos] = '-'

			LCD[i][0+pos] = '|'
			LCD[i+s+1][0+pos] = '|'
			LCD[i][s+1+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'
		return
	if digit == '9':
		for i in range(1,s+1):
			LCD[0][i+pos] = '-'
			LCD[s+1][i+pos] = '-'
			LCD[2*s+2][i+pos] = '-'

			LCD[i][0+pos] = '|'
			LCD[i][s+1+pos] = '|'
			LCD[i+s+1][s+1+pos] = '|'
		return


if __name__ == '__main__':
	LCD = [[' ' for x in range(160)] for y in range(32)]
	while(True):
		line = input()
		ll = line.split()
		s = int(ll[0])
		
		if s==0 and int(ll[1])==0:
			break

		MROW = 2*s+3
		MCOL = (s+3)*(len(ll[1]))


		flag = 1
		for x in range(len(ll[1])):
			pos = (s+3)*x
			if x==(len(ll[1])-1):
				flag = 0
			buildDisplay(LCD,ll[1][x],pos,s,len(ll[1]),flag)

		for x in range(MROW):
			#print("bosta")
			print(''.join(LCD[x][0:(MCOL-1)]))
		print()



#@END_OF_SOURCE_CODE*/