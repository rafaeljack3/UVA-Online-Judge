# @JUDGE_ID: 10142 Python "Australian Voting" 

# @BEGIN_OF_SOURCE_CODE

from sys import stdin


if __name__ == '__main__':
	N = int(stdin.readline())

	stdin.readline() #newline

	count = 0
	while N> 0:
		# numero de candidatos
		nc = int(stdin.readline())
		cand = {} #nome dos candidatos
		votes = {} 
		for i in range(nc):
			cand[i+1] = stdin.readline()
			votes[i+1] = 0

		ballots = []
		nb = 0
		while True:
			s = stdin.readline()
			if s=='' or s=='\n':
				break
			#divide a string em um lista e converte cada
			#elemento em int
			l = list( map(lambda x: int(x), s.split(' ')) )
			ballots.append(l)
			nb+=1

		#controla candidatos eliminados
		del_cand = [ False for i in range(nc)]

		#conta votos ateh um ganhar
		while True: #verificar criterio de parada
			#zera votos
			for k, v in votes.items():
				votes[k] = 0

			#conta votos
			for x in range(nb):
				votes[ballots[x][0]]+=1

			#verifica maior valor de votos
			key_max = max(votes, key=votes.get)
			max_votes = votes[key_max]

			#verifica se tem ganhador
			if max_votes > nb/2:
				print(cand[key_max], end='')
				break
			#se nao tem verifica menor nota
			key_min = min(votes,key = votes.get)
			min_votes = votes[key_min]
			#verificar maior e igual menor
			if min_votes == max_votes:
				#imprime candidatos empatados
				for k,v  in cand.items():
					print(v, end='')
				break
			#elimina menor candidatos
			list_votes = list(votes.items())
			for i  in range(len(list_votes)):
				k = list_votes[i][0]
				v = list_votes[i][1]
				if v == min_votes:
					del votes[k]
					del cand[k]

					#apaga votacoes
					keys = list(votes.keys())
					for x in range(nb):
						idx = 0
						if ballots[x][0] == k:
							del ballots[x][0]
							while True:
								if ballots[x][0] in keys:
									break
								else:
									del ballots[x][0]
								
								
		ballots*=0
		N = N-1
		count+=1
		if N> 0:
			print()
#@END_OF_SOURCE_CODE*/