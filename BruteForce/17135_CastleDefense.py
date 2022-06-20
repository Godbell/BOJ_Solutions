from sys import stdin, stdout
import itertools

def getDistanceOfTwo(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

def copyBoard(arr):
    newBoard = []
    for row in arr:
        newBoard.append(row.copy())
    return newBoard

# def printBoard(arr):
#     for row in arr:
#         for cell in row:
#             print(cell, end=' ')
#         print()
#     print()

class Archer:
    def __init__(self, x):
        self.x = x
        self.attacks = (100, 100)

boardRows, boardCols, archerRange = map(int, stdin.readline().split(' '))

assert 3 <= boardCols and boardCols <= 15
assert 3 <= boardRows and boardRows <= 15
assert 1 <= archerRange <= 10

board = [[0] * boardCols] * boardRows
for row in range(boardRows):
    board[row] = list(map(int, stdin.readline().split(' ')))
    assert len(board[row]) == boardCols

EMPTY = 0
ENEMY_EXISTS = 1
X = 0
Y = 1

howManyArchers = 3
archerXCoordRange = range(boardCols)
archerXCoordCombinations = itertools.combinations(archerXCoordRange, howManyArchers)
maxNumAttackedEnemies = -1
maxAttackPosition = None
for archerXCoordCombination in archerXCoordCombinations:
    currentBoard = copyBoard(board)
    currentBoardRows = boardRows
    
    archers = [Archer(archerXCoordCombination[0]), Archer(archerXCoordCombination[1]), Archer(archerXCoordCombination[2])]
    currentAttackedEnemies = 0
    while currentBoardRows > 0:
        archerYCoord = currentBoardRows
        for archer in archers:
            searchYUpperBound = archerYCoord - archerRange if archerYCoord - archerRange > 0 else 0
            searchYLowerBound = archerYCoord - 1
            assert searchYUpperBound <= searchYLowerBound
            searchXLeftBound = archer.x - archerRange + 1 if archer.x - archerRange + 1 > 0 else 0
            searchXRightBound = archer.x + archerRange - 1 if archer.x + archerRange - 1 < boardCols else boardCols - 1
            assert searchXLeftBound <= searchXRightBound

            for y in range(searchYUpperBound, searchYLowerBound + 1):
                for x in range(searchXLeftBound, searchXRightBound + 1):
                    assert archer.attacks[Y] == 100 or archer.attacks[Y] < archerYCoord # 이거때문에 찾았다 으어
                    currentCell = currentBoard[y][x]
                    if currentCell == EMPTY:
                        continue
                    assert currentCell == ENEMY_EXISTS
                    distanceFromArcher = getDistanceOfTwo(archer.x, archerYCoord, x, y)
                    if distanceFromArcher > archerRange:
                        continue
                    assert distanceFromArcher <= archerRange
                    existingEnemyDistanceFromArcher = getDistanceOfTwo(archer.attacks[X], archer.attacks[Y], archer.x, archerYCoord)
                    if distanceFromArcher <= existingEnemyDistanceFromArcher:
                        if distanceFromArcher < existingEnemyDistanceFromArcher:
                            archer.attacks = (x, y)
                        elif distanceFromArcher == existingEnemyDistanceFromArcher:
                            if x < archer.attacks[X]:
                                archer.attacks = (x, y)
            assert archerYCoord == currentBoardRows
            
        for archer in archers:
            if archer.attacks == (100, 100):
                continue
            attackedCell = currentBoard[archer.attacks[Y]][archer.attacks[X]]
            if attackedCell == ENEMY_EXISTS:
                currentBoard[archer.attacks[Y]][archer.attacks[X]] = EMPTY
                currentAttackedEnemies += 1
            archer.attacks = (100, 100)
                #printBoard(currentBoard)
                #print(currentAttackedEnemies, end='\n\n')

        currentBoardRows -= 1

    if currentAttackedEnemies > maxNumAttackedEnemies:
        maxNumAttackedEnemies = currentAttackedEnemies
        maxAttackPosition = archerXCoordCombination

stdout.write(str(maxNumAttackedEnemies) + '\n')