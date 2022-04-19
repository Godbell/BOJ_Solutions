import math

sizeIOI = int(input())
sizeStr = int(input())
ioiStr = input()

def getIOIsInCluster(zeroSize, n):
	if zeroSize < n:
		return 0
	else:
		return zeroSize - n + 1

sizePn = 0
clusterSizeCnt = 0
charCache = 'O'
for character in ioiStr:
	if character == charCache:
		if character == 'O': clusterSizeCnt -= 1
		sizePn += getIOIsInCluster(math.floor(clusterSizeCnt / 2), sizeIOI)
		clusterSizeCnt = 0 if character == 'O' else 1
	else:
		clusterSizeCnt += 1
	charCache = character

if clusterSizeCnt >= 3:
	if charCache == 'O': clusterSizeCnt -= 1
	sizePn += getIOIsInCluster(math.floor(clusterSizeCnt / 2), sizeIOI)

print(sizePn)