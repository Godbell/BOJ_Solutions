#class
class Map:
	def __init__(self, size, mapArray):
		self.map = mapArray
		self.size = size
		self.endPoint = Location(size, size)
	
	def isWallAt(self, location):
		assert not self.outOfMapAt(location)
		return self.map[location.row - 1][location.col - 1] == 1
		
	def outOfMapAt(self, location):
		if (location.col > self.size or location.row > self.size) or (location.col < 1 or location.row < 1):
			return True
		else:
			return False

class PipeTree:
	def __init__(self, aMap):
		self.root = PipeNode(RightPipe(Location(1,1)))
		self.map = aMap
		self.endPointNodes = []
		self.setupTreeFrom(self.root)

	def setupTreeFrom(self, node):
		queue = [node]
		while len(queue) > 0:
			currentNode = queue.pop(0)
			currentNode.setupNodeWithMap(self.map)
			if currentNode.isEndPoint:
				self.endPointNodes.append(currentNode)
			else:
				for child in currentNode.childPipes:				
					queue.append(child)

	def getNumOfPathsToTheEndPoint(self):
		return len(self.endPointNodes) 
			
class Location:
	def __init__(self, row, col):
		self.col = col
		self.row = row
		
	def __eq__(self, other):
		assert type(other) == Location
		return self.col == other.col and self.row == other.row
		
	def __str__(self):
		return '(' + str(self.row) +', ' + str(self.col) +')'

class PipeNode:	
	def __init__(self, pipe):
		self.pipe = pipe
		self.childPipes = []
		self.isEndPoint = False
	
	def setupNodeWithMap(self, aMap):
		if self.pipe.endLocation() == aMap.endPoint:
			self.isEndPoint = True
			return
		for compatiblePipe in self.pipe.compatibles:
			newPipeNode = PipeNode(compatiblePipe(self.pipe.endLocation()))
			if newPipeNode.pipe.canBeInstalledIn(aMap):
				self.childPipes.append(newPipeNode)

class Pipe:
	def __init__(self, startLocation):
		self.startLocation = startLocation
		self.compatibles = []
		self.occupieds = []
		
	def endLocation(self):
		pass

	def canBeInstalledIn(self, aMap):
		outOfMap = aMap.outOfMapAt(self.endLocation())
		if outOfMap:
			return False
		for location in self.occupieds:
			if aMap.isWallAt(location):
				return False
		return True

class RightPipe(Pipe):
	def __init__(self, startLocation):
		super(RightPipe, self).__init__(startLocation)
		self.compatibles = [RightPipe, RightDownPipe]
		self.occupieds = [self.endLocation()]

	def endLocation(self):
		return Location(self.startLocation.row, self.startLocation.col + 1)
									
class RightDownPipe(Pipe):
	def __init__(self, startLocation):
		super(RightDownPipe, self).__init__(startLocation)
		self.compatibles = [RightPipe, RightDownPipe, DownPipe]
		self.occupieds = [self.endLocation(), Location(self.endLocation().row, self.endLocation().col - 1), Location(self.endLocation().row - 1, self.endLocation().col)]

	def endLocation(self):
		return Location(self.startLocation.row + 1, self.startLocation.col + 1)

class DownPipe(Pipe):
	def __init__(self, startLocation):
		super(DownPipe, self).__init__(startLocation)
		self.compatibles = [RightDownPipe, DownPipe]
		self.occupieds = [self.endLocation()]

	def endLocation(self):
		return Location(self.startLocation.row + 1, self.startLocation.col)

#solution
mapSize = int(input())
assert 3 <= mapSize and mapSize <= 16

pipeMapArray = []
for i in range(mapSize):
	column = input().split()
	for j in range(mapSize):
		column[j] = int(column[j])
	pipeMapArray.append(column)
	
pipeMap = Map(mapSize, pipeMapArray)
pipeTree = PipeTree(pipeMap)
print(pipeTree.getNumOfPathsToTheEndPoint())