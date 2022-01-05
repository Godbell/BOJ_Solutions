#pylint:disable=W0612
class Expression:
	def __init__(self, expressionStr):
		assert len(expressionStr) > 0
		assert len(expressionStr) % 2 == 1
		self.BRACED = '0'
		self.UNBRACED = '1'
		self.numOfOperators = 0
		for elem in expressionStr:
			if Expression.isOperator(elem):
				self.numOfOperators = self.numOfOperators + 1
		self.OperBraced = 2 ** self.numOfOperators - 1
		self.originExpression = expressionStr
		self.currentExpression = expressionStr
		
	def findMaxEval(self):
		result = self.eval()
		while self.nextBracePermutation():
			#print("**** 현재 permutation: " + self.currentPermutation())
			self.setBraces()
			newResult = self.eval()
			if newResult > result:
				result = newResult
		return result
	
	def eval(self):
		result = 0
		numStack = []
		#print("현재 식: " + self.currentExpression)
		express = Expression.ExpressionInReversePoland(self.currentExpression)
		for elem in express:
			if Expression.isNumber(elem):
				numStack.append(int(elem))
			elif Expression.isOperator(elem):
				num2 = numStack.pop()
				num1 = numStack.pop() 
				numStack.append(Expression.calc(num1, elem, num2))
		result = numStack.pop()
		#print("계산된 값: " + str(result))
		return result

	def nextBracePermutation(self):
		self.OperBraced = self.OperBraced - 1
		while not self.braceIsValid():
			self.OperBraced = self.OperBraced - 1
		if self.OperBraced <= 0:
			return False
		else:
			return True

	def setBraces(self):
		permutation = self.currentPermutation()
		self.currentExpression = self.originExpression
		for i in range(len(permutation)):
			if permutation[i] == self.BRACED:
				self.currentExpression = insertString(self.currentExpression, self.findNthOperatorIndex(i) - 1, '(')
				self.currentExpression = insertString(self.currentExpression, self.findNthOperatorIndex(i) + 2, ')')	
	
	def findNthOperatorIndex(self, n):
		count = 0
		for i in range(len(self.currentExpression)):
			if Expression.isOperator(self.currentExpression[i]):
				if count == n:
					return i
				count = count + 1
	
	def braceIsValid(self):
		validation = True
		permutation = self.currentPermutation()
		for i in range(len(permutation) - 1):
			if permutation[i] == self.BRACED and permutation[i+1] == self.BRACED:
				validation = False
		return validation
	
	def currentPermutation(self):
		return "{0:b}".format(self.OperBraced).zfill(self.numOfOperators)
	
	@staticmethod
	def ExpressionInReversePoland(expressionStr):
		result = ""
		operStack = []
		for elem in expressionStr:
			if Expression.isNumber(elem):
				result = result + elem
			elif Expression.isOperator(elem):
				if len(operStack) > 0:
					top = operStack[len(operStack) - 1]
					while len(operStack) > 0 and (Expression.isOperator(top)):
						result = result + operStack.pop()
				operStack.append(elem)
			elif Expression.isOpeningBrace(elem):
				operStack.append(elem)
			elif Expression.isClosingBrace(elem):
				popped = operStack.pop()
				while not Expression.isOpeningBrace(popped):
					result = result + popped
					popped = operStack.pop()
		while len(operStack) > 0:
				result = result + operStack.pop()
		#print("후위 표기 변환 결과: " + result)	
		return result
		
	@staticmethod
	def calc(num1, operator, num2):
		result = 0
		if operator == '+':
			result = num1 + num2
		elif operator == '-':
			result = num1 - num2
		elif operator == '*':
			result = num1 * num2
		return result
		
	@staticmethod
	def isNumber(character):
		return character >= '0' and character <= '9'
	
	@staticmethod
	def isOperator(character):
		operators = ['+', '-', '*']
		return character in operators

	@staticmethod
	def isOpeningBrace(character):
		return character == '('

	@staticmethod
	def isClosingBrace(character):
		return character == ')'

#functions
def insertString(string, pos, content):
	primary = string[:pos]
	latter = string[pos:]
	return primary + content + latter

#solution
sizeOfExpression = int(input())
expression = input()
solution = Expression(expression)
print(solution.findMaxEval())
