# functions
def gcdOf(a, b):
	bigOne = biggerBetween(a, b)
	smallOne = smallerBetween(a ,b)
	while smallOne > 0:
		quarter = bigOne % smallOne
		bigOne = smallOne
		smallOne = quarter
	return bigOne
	
def gcdOfMany(alist):
	assert len(alist) >= 1
	if len(alist) == 2:
		return gcdOf(alist[0], alist[1])
	elif len(alist) > 2:
		return gcdOf(alist[0], gcdOfMany(alist[1:]))
	elif len(alist) == 1:
		return alist[0]
	else:
		raise Exception
	
def lcmOf(a, b):
	return (a * b) / gcdOf(a, b)
	
def lcmOfMany(alist):
	assert len(alist) >= 1
	if len(alist) == 2:
		return lcmOf(alist[0], alist[1])
	elif len(alist) > 2:
		return lcmOf(alist[0], lcmOfMany(alist[1:]))
	elif len(alist) == 1:
		return alist[0]
	else:
		raise Exception
	
def biggerBetween(a, b):
	bigOne = 0
	if a > b:
		bigOne = a
	else:
		bigOne = b
	return bigOne
	
def smallerBetween(a, b):
	smallOne = 0
	if a < b:
		smallOne = a
	else:
		smallOne = b
	return smallOne
	
def smallestIn(alist):
	smallest = alist[0]
	for elem in alist:
		if smallest > elem:
			smallest = elem
	return smallest
		
def biggestIn(alist):
	biggest = alist[0]
	for elem in alist:
		if biggest < elem:
			biggest = elem
	return biggest
	
# solution
deviders = []
sizeOfDeviders = int(input())

deviders = input().split()
for i in range(sizeOfDeviders):
	deviders[i] = int(deviders[i])

multiplier = 1
lcm = int(lcmOfMany(deviders))
while lcm * multiplier in deviders:
	multiplier = multiplier * smallestIn(deviders)
answer = lcm * multiplier
print(int(answer))
