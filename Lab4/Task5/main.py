def binary_search1(Array, item):
    l = -1
    r = len(Array)
    while l < r - 1:
        m = (l + r) // 2
        if Array[m] < item:
            l = m
        else:
            r = m
    # return r if Array[r] == item and r != len(Array) else -1
    if r != len(Array):
        if Array[r] == item:
            return r
        else:
            return -1
    else:
        return -1

def binary_search2(Array, item):
    l = -1
    r = len(Array)
    while l < r - 1:
        m = (l + r) // 2
        if Array[m] > item:
            r = m
        else:
            l = m
    return l if Array[l] == item else -1

fin = open("binsearch.in")
fout = open("binsearch.out", "w")
checker = 0
n = int(fin.readline())
Array_Main = list(map(int, fin.readline().split()))
m = int(fin.readline())
Array_Check = list(map(int, fin.readline().split()))
Array_Numbers = []
for i in range(m):
    index_left = binary_search1(Array_Main, Array_Check[i])
    if index_left == -1:
        print(-1, -1, file=fout)
    else:
        index_right = binary_search2(Array_Main, Array_Check[i])
        print(index_left + 1, index_right + 1, file=fout)
fout.close()