fin = open("quack.in")
fout = open("quack.out", "w")
l = 0
r = 0
x = 0
y = 0
Array2 = []
Array1 = []
label = []
label_index = []
labels = 0
j = 0
checker = 0
ALPHA = []
for line in fin:
    Array1.insert(checker, line.rstrip())
    if Array1[checker][0] == ':':
        Array1[checker] = Array1[checker][1: len(Array1[checker])]
        label.insert(labels, (Array1[checker]))
        label_index.insert(labels, checker)
        labels += 1
    checker += 1
while j < checker:
    Main_checker = Array1[j]
    if Main_checker == "Q":
        break
    if Main_checker.isdigit():
        Array2.insert(r, int(Main_checker) & 65535)
        r += 1
    if Main_checker == "+":
        Array2.insert(r, (Array2[l] + Array2[l + 1]) & 65535)
        r += 1
        l += 2
    if Main_checker == "-":
        Array2.insert(r, (Array2[l] - Array2[l + 1]) & 65535)
        r += 1
        l += 2
    if Main_checker == "*":
        Array2.insert(r, (Array2[l] * Array2[l + 1]) & 65535)
        r += 1
        l += 2
    if Main_checker == "/":
        x = Array2[l]
        l += 1
        y = Array2[l]
        l += 1
        if y == 0:
            Array2.insert(r, 0)
            r += 1
        else:
            Array2.insert(r, (x // y) & 65535)
            r += 1
    if Main_checker == "%":
        x = Array2[l]
        l = l + 1
        y = Array2[l]
        l += 1
        if y == 0:
            Array2.insert(r, 0)
            r += 1
        else:
            Array2.insert(r, (x % y) & 65535)
            r += 1
    if Main_checker[0] == '>':
        ALPHA.insert(ord(Main_checker[1]) - 97, Array2[l])
        l += 1
    if Main_checker[0] == '<':
        Array2.insert(r, ALPHA[ord(Main_checker[1]) - 97])
        r += 1
    if Main_checker == "P":
        print(Array2[l], file=fout)
        l += 1
    if Main_checker[0] == 'P' and len(Main_checker) != 1:
        print(ALPHA[ord(Main_checker[1]) - 97], file=fout)
    if Main_checker == "C":
        if ord(chr(Array2[l] % 256)) >= 5:
            fout.write(str(chr(Array2[l] % 256)))
        l += 1
    if Main_checker[0] == 'C' and len(Main_checker) != 1:
        if ord(chr(ALPHA[ord(Main_checker[1]) - 97] % 256)) >= 5:
            fout.write(str(chr(ALPHA[ord(Main_checker[1]) - 97] % 256)))
    if Main_checker[0] == 'J':
        Main_checker = Main_checker[1:len(Main_checker)]
        for i in range(labels):
            if label[i] == Main_checker:
                j = label_index[i]
                break
    if Main_checker[0] == 'Z':
        if ALPHA[ord(Main_checker[1]) - 97] == 0:
            Main_checker = Main_checker[2:len(Main_checker)]
            for i in range(labels):
                if label[i] == Main_checker:
                    j = label_index[i]
                    break
    if Main_checker[0] == 'E':
        if ALPHA[ord(Main_checker[1]) - 97] == ALPHA[ord(Main_checker[2]) - 97]:
            Main_checker = Main_checker[3:len(Main_checker)]
            for i in range(labels):
                if label[i] == Main_checker:
                    j = label_index[i]
                    break
    if Main_checker[0] == 'G':
        if ALPHA[ord(Main_checker[1]) - 97] > ALPHA[ord(Main_checker[2]) - 97]:
            Main_checker = Main_checker[3:len(Main_checker)]
            for i in range(labels):
                if label[i] == Main_checker:
                    j = label_index[i]
                    break
    j += 1
