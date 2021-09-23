n = int(input())
tree = {}
for _ in range(n):
    p,l,r = input().split()
    tree[p] = [l,r]

def preorder(root):
    if root == '.': return
    print(root,end="")
    preorder(tree[root][0]) #left
    preorder(tree[root][1]) #right
    if root == 'A': print()

def inorder(root):
    if root == '.': return
    inorder(tree[root][0])
    print(root,end="")
    inorder(tree[root][1])
    if root == 'A': print()

def postorder(root):
    if root == '.': return
    postorder(tree[root][0])
    postorder(tree[root][1])
    print(root,end="")
    if root == 'A': print()

preorder('A')
inorder('A')
postorder('A')