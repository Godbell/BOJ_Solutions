from sys import stdin, stdout

class Item:
    def __init__(self, id, weight, value):
        self.id = id
        self.weight = weight
        self.value = value

class ItemNode:
    def __init__(self, firstItem = None):
        self.currentWeight = 0
        self.currentValue = 0
        self.visitedItemIDs = {}
        if firstItem is not None:
            self.append(firstItem)
    def append(self, item):
        self.currentWeight += item.weight
        self.currentValue += item.value
        self.visitedItemIDs[item.id] = 0
    def appended(self, item):
        result = ItemNode()
        result.currentValue += self.currentValue
        result.currentWeight += self.currentWeight
        result.visitedItemIDs = self.visitedItemIDs.copy()
        result.append(item)
        return result
    def isVisited(self, id):
        return id in self.visitedItemIDs


numberOfItems, maxWeight = map(int, stdin.readline().split())
items = [Item(i, 0, 0) for i in range(numberOfItems)]
itemNodesWithWeightForIndex = [ItemNode() for i in range(maxWeight + 1)]

for i in range(numberOfItems):
    weight, value = map(int, stdin.readline().split())
    if weight > maxWeight: continue
    items[i].weight = weight
    items[i].value = value

for weight in range(1, maxWeight + 1):
    node = itemNodesWithWeightForIndex[weight]
    for item in items:
        if node.isVisited(item.id): continue
        nextWeight = node.currentWeight + item.weight
        if nextWeight > maxWeight: continue
        nextValue = node.currentValue + item.value
        if itemNodesWithWeightForIndex[nextWeight].currentValue < nextValue:
            itemNodesWithWeightForIndex[nextWeight] = node.appended(item)

stdout.write(
    str(max(itemNodesWithWeightForIndex, key=lambda x:x.currentValue).currentValue)
)