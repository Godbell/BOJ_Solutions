mapSize = int(input())
WALL = '1'
RIGHT = 0
RIGHTDOWN = 1
DOWN = 2

pipeMap = []
pipeDP = [[[0 ,0, 0] for i in range(mapSize)] for j in range(mapSize)]

for i in range(mapSize):
	inputLine = input().split(' ')
	pipeMap.append(inputLine)

for y in range(mapSize):
	for x in range(mapSize):
		if pipeMap[y][x] == WALL or x == 0:
			continue
		if y == 0 and x == 1:
			pipeDP[y][x] = [1, 0, 0]
		else:
			pipeDP[y][x][RIGHT] = pipeDP[y][x - 1][RIGHT] + pipeDP[y][x - 1][RIGHTDOWN]
			pipeDP[y][x][DOWN] = pipeDP[y - 1][x][DOWN] + pipeDP[y - 1][x][RIGHTDOWN]
			
			if pipeMap[y - 1][x] != WALL and pipeMap[y][x - 1] != WALL:
				pipeDP[y][x][RIGHTDOWN] = pipeDP[y - 1][x - 1][RIGHT] + pipeDP[y - 1][x - 1][RIGHTDOWN] + pipeDP[y - 1][x - 1][DOWN]
			
			
print(pipeDP[mapSize - 1][mapSize - 1][RIGHT] + pipeDP[mapSize - 1][mapSize - 1][RIGHTDOWN] + pipeDP[mapSize - 1][mapSize - 1][DOWN])