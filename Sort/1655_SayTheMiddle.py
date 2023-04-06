from sys import stdin, stdout
import heapq

sizeOfNumbers = int(stdin.readline())
rightHalfMinHeap = []
leftHalfMaxHeap = []

for i in range(sizeOfNumbers):
    inputNumber = int(stdin.readline())
    if len(rightHalfMinHeap) == len(leftHalfMaxHeap):
        if rightHalfMinHeap and inputNumber > rightHalfMinHeap[0]:
            heapq.heappush(rightHalfMinHeap, inputNumber)
            heapq.heappush(leftHalfMaxHeap, -heapq.heappop(rightHalfMinHeap))
        else:
            heapq.heappush(leftHalfMaxHeap, -inputNumber)
    else:
        assert leftHalfMaxHeap
        assert len(leftHalfMaxHeap) - 1 == len(rightHalfMinHeap)
        if inputNumber < -leftHalfMaxHeap[0]:
            heapq.heappush(leftHalfMaxHeap, -inputNumber)
            heapq.heappush(rightHalfMinHeap, -heapq.heappop(leftHalfMaxHeap))
        else:
            heapq.heappush(rightHalfMinHeap, inputNumber)
    
    #print("median: ", end="")
    if len(leftHalfMaxHeap) == len(rightHalfMinHeap):
        stdout.write(str(min(-leftHalfMaxHeap[0], rightHalfMinHeap[0])) + '\n')
    else:
        assert len(leftHalfMaxHeap) - 1 == len(rightHalfMinHeap)
        stdout.write(str(-leftHalfMaxHeap[0]) + '\n')