from queue import Queue
import string



with open('quack.in') as fin,\
     open('quack.out', 'w') as fout:
    commands = [l.strip() for l in fin]


    q = Queue()
    regs = {c: 0 for c in string.ascii_lowercase}
    labels = dict()
    
    for i, s in enumerate(commands):
        if s[0] == ':':
            labels[s[1:]] = i
    
    ind = 0
    while True:
        s = commands[ind]
        c = s[0]
        if c == '+':
            q.put((q.get() + q.get()) % 65536)
        elif c == '-':
            q.put((q.get() - q.get()) % 65536)
        elif c == '*':
            q.put((q.get() * q.get()) % 65536)
        elif c == '/':
            x, y = q.get(), q.get()
            if y == 0:
                q.put(0)
            else:
                q.put(x // y)
        elif c == '%':
            x, y = q.get(), q.get()
            if y == 0:
                q.put(0)
            else:
                q.put(x % y)
        elif c == '>':
            regs[s[1]] = q.get()
        elif c == '<':
            q.put(regs[s[1]])
        elif c == 'P':
            if len(s) == 1:
                fout.write(str(q.get()))
                fout.write('\n')
            if len(s) == 2:
                fout.write(str(regs[s[1]]))
                fout.write('\n')
        elif c == 'C':
            if len(s) == 1:
                fout.write(str(chr(q.get() % 256)))
            if len(s) == 2:
                fout.write(str(chr(regs[s[1]] % 256)))
        elif c == 'J':
            ind = labels[s[1:]]
        elif c == 'Z':
            if regs[s[1]] == 0:
                ind = labels[s[2:]]
        elif c == 'E':
            if regs[s[1]] == regs[s[2]]:
                ind = labels[s[3:]]
        elif c == 'G':
            if regs[s[1]] > regs[s[2]]:
                ind = labels[s[3:]]
        elif c == 'Q':
            break
        elif c in '1234567890':
            q.put(int(s))
        ind += 1
        if ind >= len(commands):
            break
        
            
