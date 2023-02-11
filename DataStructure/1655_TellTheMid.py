from collections import deque
from sys import stdin, stdout
from copy import deepcopy

NULL = 99999

class heap:
    def __init__(self, size):
        assert 1 <= size <= 100000
        self.maxSize = size
        self.lastIndex = 0
        self.nodes = [NULL for i in range(self.maxSize)]
        self.mids = [NULL for i in range(self.maxSize)]
    def pop(self):
        popped = self.nodes[0]
        self.nodes[0] = self.nodes[self.currentSize - 1]
        self.nodes[self.lastIndex] = NULL
        self.__down__(0)
        self.currentSize -= 1
        return popped
    def push(self, value):
        self.lastIndex += 1
        self.nodes[self.lastIndex +] = value
        self.__up__(self.lastIndex)
        self.currentSize += 1
    def __up__(self, index):
        pass
    def __down__(self, index):
        pass
    def sorted(self):
        size = self.currentSize
        result = [NULL for i in range(size)]
        while self.currentSize >= 0:
            result[size - self.currentSize] = self.pop()
        return result

numberOfNumbers = int(stdin.readline())
priorityQueue = heap(numberOfNumbers)

for i in range(numberOfNumbers):
    inputNumber = int(stdin.readline())
    priorityQueue.push(inputNumber)
    priorityQueueCopy = deepcopy(priorityQueue)
    result = priorityQueueCopy.sorted()
    if priorityQueue.currentSize % 2 == 0:
        stdout.write(str(
            min(
                result[priorityQueue.currentSize % 2 - 1], 
                result[priorityQueue.currentSize % 2]
            )
            + '\n'
        ))
    else:
        stdout.write(str(result[priorityQueue.currentSize % 2]) + '\n')
