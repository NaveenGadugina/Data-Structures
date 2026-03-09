#BFS - Breadth first search
class Node:
    def __init__(self, value):
        self.value = value      # Store node value
        self.children = []      # List to store child nodes

from collections import deque
#main function for bfs
def bfs(root):
    if not root:
        return                  # Exit if tree is empty
    queue = deque([root])      # Initialize queue with root node
    while queue:
        current_node = queue.popleft()   # Remove node from front of queue
        print(current_node.value, end=' ')  # Print node value
        for child in current_node.children:
            queue.append(child)   # Add children to queue


Node1 = Node(1)
Node2 = Node(2) 
Node3 = Node(3)
Node4 = Node(4)
Node5 = Node(5)
Node6 = Node(6)

Node1.children = [Node2, Node3, Node4]   # Define children of Node1
Node2.children = [Node5]                 # Define children of Node2
Node3.children = [Node6]                 # Define children of Node3

print("BFS Traversal of the tree:")
bfs(Node1)                               # Call BFS starting from root
