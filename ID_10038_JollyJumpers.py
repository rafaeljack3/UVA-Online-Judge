# @JUDGE_ID: 10267 Python "Graphical Editor"

# @BEGIN_OF_SOURCE_CODE


from sys import stdin



if __name__ == '__main__':
	v = []
	m = {}

	while True:
		v.clear()
		m.clear()
		line = stdin.readline()
		if not line:
			break

		l = line.split()
		N = int(l[0])

		if N == 1:
			print('Jolly')
			continue

		for i in range(1,N+1):
			v.append(int(l[i]))
			if i<N:
				m[i] = 0

		for i in range(1,N):
			x = abs(v[i]-v[i-1])
			if x< N:
				m[x] = 1

		status = True
		for key in m:
			if m[key]==0:
				status = False

		if status:
			print('Jolly')
		else:
			print('Not jolly')



#@END_OF_SOURCE_CODE
