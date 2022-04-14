import math

inputData = input().split(' ')
speed = int(inputData[0])
slipsDown = int(inputData[1])
distance = int(inputData[2])

answer = math.ceil((distance - speed) / (speed - slipsDown)) + 1
print(answer)