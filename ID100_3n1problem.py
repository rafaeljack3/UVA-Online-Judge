''' @JUDGE_ID: 100 Python "The 3n + 1 Problem" '''


''' @BEGIN_OF_SOURCE_CODE '''
from sys import stdin
'''
def memodict(f):
    """ Memoization decorator for a function taking a single argument """
    class memodict(dict):
        def __missing__(self, key):
            ret = self[key] = f(key)
            return ret
    return memodict().__getitem__

@memodict
'''
CACHE = {}
def ncycle(n):
	if n in CACHE:
		return CACHE[n]
	nc = 1
	n0 = n
	while n!=1:
		if n % 2 ==0:
			n = n//2
		else:
			n = 3*n+1
		nc+=1
	CACHE[n0] = nc
	return nc

def main(x0,xn):
	if x0 > xn: x0, xn = xn, x0

	arr = map(ncycle,range(x0,xn+1))
	return max(list(arr))
		

if __name__ == '__main__':
	for line in stdin:
		try:
			arr = list(map(int, line.split()))
		except:
			exit(0)

		print("%d %d %d" %(arr[0],arr[1],main(arr[0],arr[1])))

''' @END_OF_SOURCE_CODE '''
