def Height(Tree, i, left, right):
    if Tree[i][1] != 0:
        left = Height(Tree, Tree[i][1]-1, left, right)
    else:
        left = 0
    if Tree[i][2] != 0:
        right = Height(Tree, Tree[i][2]-1, left, right)
    else:
        right = 0
    return 1 + max(left, right)

fin = open("height.in")
fout = open("height.out", "w")
N = int(fin.readline())
Tree = []
left = 0
right = 0
for i in range(N):
    Input_Array = list(map(int, fin.readline().split()))
    Tree.append(Input_Array)
if Tree == []:
    print(0, file=fout)
else:
    print(Height(Tree, 0, left, right), file=fout)
fout.close()

