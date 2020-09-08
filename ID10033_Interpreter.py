# @JUDGE_ID: 10033 Python "Interpreter" 

# @BEGIN_OF_SOURCE_CODE

from sys import stdin

def cleanMEM(V,LEN):
	for x in range(LEN):
		V[x] = 0
	return


if __name__ == '__main__':
	REG_LEN = 10
	RAM_LEN = 1000

	N = int(stdin.readline())

	REG = [0 for x in range(REG_LEN)]
	RAM = [0 for x in range(RAM_LEN)]

	stdin.readline() #first blank line

	for x in range(N):
		cleanMEM(RAM,RAM_LEN)
		cleanMEM(REG,REG_LEN)

		#read instructions
		n_inst = 0
		while True:
			line = stdin.readline()
			if line== '' or line[0] =='\n':
				break
			RAM[n_inst] = int(line)
			n_inst+=1


		pointer = 0
		n_exec = 0
		while True:
			exec_inst = RAM[pointer] 
			#exec_inst = <code><d><n>
			code = exec_inst // 100
			d = (exec_inst // 10) % 10
			n = exec_inst % 10

			if code == 1:
				n_exec+=1
				break
			elif code == 2:
				REG[d] = n
				n_exec+=1
				pointer+=1
			elif code ==3:
				REG[d] = (REG[d]+n) % 1000
				n_exec+=1
				pointer+=1
			elif code ==3:
				REG[d] = (REG[d]+n) % 1000
				n_exec+=1
				pointer+=1
			elif code ==4:
				REG[d] = (REG[d]*n) % 1000
				n_exec+=1
				pointer+=1
			elif code ==5:
				REG[d] = REG[n] % 1000
				n_exec+=1
				pointer+=1
			elif code ==6:
				REG[d] = (REG[d]+REG[n]) % 1000
				n_exec+=1
				pointer+=1
			elif code ==7:
				REG[d] = (REG[d]*REG[n]) % 1000
				n_exec+=1
				pointer+=1
			elif code ==8:
				REG[d] = RAM[REG[n]] % 1000
				n_exec+=1
				pointer+=1
			elif code ==9:
				RAM[REG[n]] = REG[d] % 1000
				n_exec+=1
				pointer+=1
			else:
				if REG[n]==0:
					pointer+=1
				else:
					pointer = REG[d]
				n_exec+=1

			
		print(n_exec)
		if x<N-1:
			print()

#@END_OF_SOURCE_CODE*/