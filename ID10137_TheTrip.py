# @JUDGE_ID: 10189 Python "Minesweeper" 

# @BEGIN_OF_SOURCE_CODE
from sys import stdin


if __name__ == '__main__':
	while(True):
		data = input()
		N = int(data)
		if N==0:
			break
		spent = []
		avg = 0
		for i in range(N):
			line = stdin.readline()
			x = float(line.split()[0])
			spent.append(x)
			avg+=x
		avg = avg/N

		sum_pos = 0
		sum_neg = 0
		for i in range(N):
			x = int((spent[i] - avg)*100.00)
			x = float(x/100.00)

			if x > 0:
				sum_pos+=x
			else:
				sum_neg+=x
		sum_neg=-sum_neg
		resp = max(sum_pos, sum_neg)

		print("$%.2f" %(resp))


#@END_OF_SOURCE_CODE*/