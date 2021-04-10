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
