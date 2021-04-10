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


def push(Queue, x):
    Queue.append(x)


def extract_min(Queue):
    if len(Queue) == 0:
        fout.write('*')
        fout.write('\n')
    else:
        minimum = min(Queue)
        Queue.remove(minimum)
        fout.write(str(minimum))
        fout.write('\n')


def decrease_key(Queue, x, y):
    Queue[x] = y


fin = open("priorityqueue.in")
fout = open("priorityqueue.out", "w")
Queue = []
Index_Array = DictSim()
checker = 0
for line in fin:
    checker += 1
    Input_Array = line.split()
    if Input_Array[0] == "push":
        Index_Array[checker] = len(Queue)
        push(Queue, int(Input_Array[1]))
    elif Input_Array[0] == "extract-min":
        extract_min(Queue)
    elif Input_Array[0] == "decrease-key":
        decrease_key(Queue, Index_Array[int(Input_Array[1])], int(Input_Array[2]))
fout.close()
