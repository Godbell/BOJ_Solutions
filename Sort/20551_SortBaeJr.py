from sys import stdin

arrSize, valueToFindSize = map(int, stdin.readline().split())

arr = sorted([int(stdin.readline()) for i in range(arrSize)])

def findValue(array, value):
	left = 0
	right = len(array) - 1
	while left <= right:
		mid = (left + right) // 2
		if array[mid] == value: 
			if right == mid:
				return mid
			right = mid
		elif array[mid] < value : 
			left = mid + 1
		elif array[mid] > value :
			right = mid - 1
	return -1

for i in range(valueToFindSize):
	valueToFind = int(stdin.readline())
	print(str(findValue(arr, valueToFind)))