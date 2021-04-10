# min-heap methods
def get_left_child(i, n):
    if 2 * i + 1 < n:
        return 2 * i + 1
    return None

def get_right_child(i, n):
    if 2 * i + 2 < n:
        return 2 * i + 2
    return None

def get_parent(i):
    if i > 0:
        return (i - 1) // 2
    return None

def sift_up(a, i, n):
    p = get_parent(i)
    while p is not None and a[p] > a[i]:
        a[p], a[i] = a[i], a[p]
        i = p
        p = get_parent(i)

def sift_down(a, i, n):
    l = get_left_child(i, n)
    r = get_right_child(i, n)

    m = i
    if l is not None and a[l] < a[m]:
        m = l
    if r is not None and a[r] < a[m]:
        m = r
        
    if m == i: return
    
    a[i], a[m] = a[m], a[i]

    sift_down(a, m, n)


#priority queue methods
def pop_min(a):
    if len(a) == 0:
        return '*'
    a[0], a[-1] = a[-1], a[0]
    sift_down(a, 0, len(a) - 1)
    return a.pop()

def push(a, x):
    a.append(x)
    sift_up(a, len(a)-1, len(a))

def decrease_key(a, keys, x, y):
    v = keys[x]
    keys[x] = y
    ind = a.index(v)
    a[ind] = y
    sift_up(a, ind, len(a))
    

a = []
keys = dict()
with open('priorityqueue.in') as fin,\
     open('priorityqueue.out', 'w') as fout:
    for ind, _command in enumerate(fin):
        command = _command.split()
        if command[0] == 'push':
            x = int(command[1])
            keys[ind + 1] = x
            push(a, x)
        elif command[0] == 'extract-min':
            fout.write(str(pop_min(a)))
            fout.write('\n')
        elif command[0] == 'decrease-key':
            x = int(command[1])
            y = int(command[2])
            decrease_key(a, keys, x, y)









    
    
