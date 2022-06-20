from sys import stdin
from sys import stdout
import math
from itertools import combinations

testcaseSize = int(stdin.readline())
for testCase in range(testcaseSize):
	dotSize = int(stdin.readline())
	dots = [(0, 0)] * dotSize
	xSum = 0
	ySum = 0
	for i in range(dotSize):
		dotData = list(map(int, stdin.readline().split(' ')))
		dots[i] = (dotData[0], dotData[1])
		xSum += dotData[0]
		ySum += dotData[1]
	minVectorSize = -1
	combinationList = list(combinations(dots, int(dotSize / 2)))
	
	slicer = int(len(combinationList) / 2)
	for combination in combinationList[:slicer]:
		x = xSum
		y = ySum
		for dot in combination:
			x -= dot[0] * 2
			y -= dot[1] * 2
			
		vectorSize = x ** 2 + y ** 2
		if vectorSize < minVectorSize or minVectorSize == -1:
			minVectorSize = vectorSize

	stdout.write(str(math.sqrt(minVectorSize)) + '\n')