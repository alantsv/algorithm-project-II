class BinSearchTree (object):
	def __init__(self, key, value=None, left=None, right=None):
		self.key = key
		self.value = value
		self.left = left
		self.right = right

	def get(self, key):
		if key < self.key:
			return self.left.get(key) if self.left else None
		elif key > self.key:
			return self.right.get(key) if self.right else None
		else:
			return self

	def add(self, node):
		if node.key < self.key:
			if self.left is None:
				self.left = node
			else:
				self.left.add(node)
		else:
			if self.right is None:
				self.right = node
			else:
				self.right.add(node)

	def show(self):
		print ("(", end="")
#		print ("%s" % self.key, end="")
		if self.left:
			self.left.show()
		print ("%s" % self.key, end="")
		if self.right:
			self.right.show()
		print (")", end="")

	def search (self, key):
		if self.key == key: 
			return 1
		if key < self.key: 
			if self.left is None: 
				return 0
			else: 
				return self.left.search(key)
		if key > self.key:
			if self.right is None:
				return 0
			else:
				return self.right.search(key)
