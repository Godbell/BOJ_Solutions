R = 0
G = 1
B = 2

sizeOfHouses = int(input())
houseArray = [[0,0,0] for i in range(sizeOfHouses)]
DPTable = [[0,0,0] for i in range(sizeOfHouses)]

for i in range(sizeOfHouses):
	inputCost = input().split(' ')
	houseArray[i][R] = int(inputCost[R])
	houseArray[i][G] = int(inputCost[G])
	houseArray[i][B] = int(inputCost[B])
	
DPTable[0] = houseArray[0]
for i in range(1, sizeOfHouses):
	DPTable[i][R] = houseArray[i][R] + min(DPTable[i - 1][G], DPTable[i - 1][B])
	DPTable[i][G] = houseArray[i][G] + min(DPTable[i - 1][R], DPTable[i - 1][B])
	DPTable[i][B] = houseArray[i][B] + min(DPTable[i - 1][R], DPTable[i - 1][G])
	
print(min(DPTable[sizeOfHouses - 1]))