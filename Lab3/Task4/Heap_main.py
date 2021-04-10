class DictSim(object):
    def __init__(self, **kwargs):
        self.keys = []
        self.values = []
        for key in kwargs.keys():
            self.keys.append(key)
            self.values = kwargs[key]

    def get(self, key, fail_return):
        try:
            return self.values[self.keys.index(key)]
        except:
            return fail_return

    def __getitem__(self, item):
        return self.values[self.keys.index(item)]

    def __setitem__(self, key, value):
        try:
            self.values[self.keys.index(key)] = value
        except:
            self.keys.append(key)
            self.values.append(value)

    def keys(self):
        return self.keys.copy()

    def values(self):
        return self.values.copy()

    def clear(self):
        self.values.clear()
        self.keys.clear()

def get_right_child(i, n):
    if 2 * i + 2 < n:
        return 2 * i + 2
    return None

def get_left_child(i, n):
    if 2 * i + 1 < n:
        return 2 * i + 1
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


def extract_min(a):
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
    

Main_Array = []
Main_keys = DictSim()
fin = open("priorityqueue.in")
fout = open("priorityqueue.out", "w")
for ind, input_command in enumerate(fin):
    Input_Array = input_command.split()
    if Input_Array[0] == 'push':
        x = int(Input_Array[1])
        Main_keys[ind + 1] = x
        push(Main_Array, x)
    elif Input_Array[0] == 'extract-min':
        fout.write(str(extract_min(Main_Array)))
        fout.write('\n')
    elif Input_Array[0] == 'decrease-key':
        x = int(Input_Array[1])
        y = int(Input_Array[2])
        decrease_key(Main_Array, Main_keys, x, y)









    
    
