class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

from collections import deque
def bfs(root):
    if not root:
        return 
    queue = deque([root])
    while queue:
        current_node = queue.popleft()
        print(current_node.value, end=' ')
        for child in current_node.children:
            queue.append(child)

Node1 = Node(1)
Node2 = Node(2) 
Node3 = Node(3)
Node4 = Node(4)
Node5 = Node(5)
Node6 = Node(6)

Node1.children = [Node2, Node3, Node4]
Node2.children = [Node5 ]
Node3.children = [Node6]

print("BFS Traversal of the tree:")
bfs(Node1)
