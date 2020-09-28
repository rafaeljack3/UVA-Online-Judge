# @JUDGE_ID: 10196 Python "Check the Check" 

# @BEGIN_OF_SOURCE_CODE

from sys import stdin

BOARD_LEN = 8

def EmptyBoard(board):
	count = 0
	for i in range(BOARD_LEN):
		for j in range(BOARD_LEN):
			if board[i][j] == '.':
				count+=1

	if count==64:
		return True
	else:
		return False

def getPosition(piece, board):

	for i in range(BOARD_LEN):
		for j in range(BOARD_LEN):
			if board[i][j] == piece:
				return (i,j)



def printBoard(board):
	for i in range(BOARD_LEN):
		for j in range(BOARD_LEN):
			print(board[i][j], end='')
		print()

def checkCheck(board, color, x_k,y_k):
	Check = False
	piece = {}
	if color == 'white':
		piece = {'k': 'k','q': 'q','r': 'r','b': 'b','n':'n'}
	else:
		piece = {'k': 'K','q': 'Q','r': 'R','b': 'B','n':'N'}

	stop = {'u': False,'d': False,'l': False,'r': False, 'u_r': False, 'u_l': False,'d_r': False,'d_l': False}
	dd = 1
	while True:
		count = 0
		for s in stop:
			if stop[s] == True:
				count+=1
		if count ==8:
			break

		coord = {'u': (y_k - dd,x_k) ,'d': (y_k + dd,x_k) ,'l': (y_k ,x_k-dd),'r': (y_k ,x_k+dd), 'u_r': (y_k - dd,x_k+dd), 'u_l': (y_k - dd,x_k-dd),'d_r': (y_k + dd,x_k+dd),'d_l': (y_k + dd,x_k-dd)}

		#VERIFICA DIRECOES (FALTA PEAO  E CAVALO)
		for direction in coord:
			cc = coord[direction]
			if cc[0]<0 or cc[0] >= BOARD_LEN or cc[1]<0 or cc[1] >= BOARD_LEN:
				stop[direction] = True
				continue

			pp = board[cc[0]][cc[1]]
			#if pp =='b':
			#	print(f'{cc[0]} {cc[1]}')

			if stop[direction] == False:
				#se a peca for outro rei 'k':
				if dd==1 and pp==piece['k']:
					Check=True 
					stop[direction] = True
					return Check
				#se a peca q (rainha)
				elif pp==piece['q']:
					Check=True
					stop[direction] = True
					return Check
				#se a peca for r (torre) e tiver na horizontal ou vertical
				elif pp == piece['r'] and (cc[0] == y_k or cc[1] == x_k):
					Check=True
					stop[direction] = True
					return Check
				elif pp == piece['b'] and ( (cc[0] == (-cc[1] + y_k + x_k) ) or (cc[0] == (cc[1] + y_k -x_k) )):
					Check=True
					stop[direction] = True
					return Check			
				elif pp != '.':
					stop[direction] = True

		dd+=1

	#verificar peao
	#------------------------------------
	if color == 'white':
		if x_k-1>=0 and y_k -1 >=0 and board[y_k-1][x_k-1]=='p':
			Check=True
			return Check
		if x_k+1< BOARD_LEN and y_k - 1 >=0  and board[y_k-1][x_k+1]=='p':
			Check=True
			return Check
	else:#black
		if x_k-1>=0 and y_k +1 < BOARD_LEN and board[y_k+1][x_k-1]=='P':
			Check=True
			return Check
		if x_k+1< BOARD_LEN and y_k +1 < BOARD_LEN and board[y_k+1][x_k+1]=='P':
			Check=True
			return Check

	#verificar cavalos
	coord = [(y_k-1,x_k+2),(y_k-2,x_k+1), (y_k-2, x_k-1),(y_k-1,x_k-2),(y_k+1,x_k-2),(y_k+2,x_k-1),(y_k+2,x_k+1),(y_k+1,x_k+2)]
	for cc in coord:
		y = cc[0]
		x = cc[1]
		if x>=0 and x< BOARD_LEN and y>=0 and y< BOARD_LEN and board[y][x] == piece['n']:
			Check=True
			return Check
			break	

	return Check



if __name__ == '__main__':

	n_game=0
	while True:
		n_game+=1
		board = []
		for x in range(BOARD_LEN):
			line = stdin.readline()
			board.append(line)

		if EmptyBoard(board):
			break

		stdin.readline() # linha vazia

		#encontrar posicao dos reis
		k_position = getPosition('k', board) #petro
		K_position = getPosition('K', board) #branco
		Check_k = False
		Check_K = False


		#print(f'{k_position} {K_position}')
		#printBoard(board)
		
		#verificar se esta sob ataque (BRANCO)
		x_k = K_position[1]
		y_k = K_position[0]
		Check_White =  checkCheck(board,'white',x_k,y_k)
		x_k = k_position[1]
		y_k = k_position[0]
		Check_Black =  checkCheck(board,'black',x_k,y_k)

		#imprir saida
		if Check_White == True:
			print(f'Game #{n_game}: white king is in check.')
		elif Check_Black == True:
			print(f'Game #{n_game}: black king is in check.')
		else:
			print(f'Game #{n_game}: no king is in check.')			


#@END_OF_SOURCE_CODE*/