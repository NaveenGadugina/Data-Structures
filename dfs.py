class Node:
    def _init_(self, value):
        self.value= value
        self.children =[]

def dfs(root):
    if not root:
        return
    stack=[root]
    while stack:
        current_node=stack.pop()
        print(current_node.value, end=' ')
        for child in current_node.children:
            stack.append(child)

A=Node("A")
B=Node("B")
C=Node("C")
D=Node("D")
E=Node("E")
F=Node("F")

A.children = [B, C, D]
B.children = [E]   
C.children = [F]

print("BFS Traversal of the tree:")
dfs(A)
