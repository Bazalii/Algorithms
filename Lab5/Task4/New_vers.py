from queue import Queue
import string

fin = open("quack.in")
fout = open("quack.out", "w")
number = 0
commands = [line.rstrip() for line in fin]
Main_Queue = Queue()
letters = {c: 0 for c in string.ascii_lowercase}
labels = {}
i = 0
for command in commands:
    if command[0] == ':':
        labels[command[1:]] = i
    i += 1
while True:
    command = commands[number]
    c = command[0]
    if c == '+':
        Main_Queue.put((Main_Queue.get() + Main_Queue.get()) % 65536)
    elif c == '-':
        Main_Queue.put((Main_Queue.get() - Main_Queue.get()) % 65536)
    elif c == '*':
        Main_Queue.put((Main_Queue.get() * Main_Queue.get()) % 65536)
    elif c == '/':
        x = Main_Queue.get()
        y = Main_Queue.get()
        if y == 0:
            Main_Queue.put(0)
        else:
            Main_Queue.put(x // y)
    elif c == '%':
        x = Main_Queue.get()
        y = Main_Queue.get()
        if y == 0:
            Main_Queue.put(0)
        else:
            Main_Queue.put(x % y)
    elif c == '>':
        letters[command[1]] = Main_Queue.get()
    elif c == '<':
        Main_Queue.put(letters[command[1]])
    elif c == 'P':
        if len(command) == 1:
            print(str(Main_Queue.get()), file=fout)
        if len(command) == 2:
            print(str(letters[command[1]]), file=fout)
    elif c == 'C':
        if len(command) == 1:
            fout.write(str(chr(Main_Queue.get() % 256)))
        if len(command) == 2:
            fout.write(str(chr(letters[command[1]] % 256)))
    elif c == 'J':
        number = labels[command[1:]]
    elif c == 'Z':
        if letters[command[1]] == 0:
            number = labels[command[2:]]
    elif c == 'E':
        if letters[command[1]] == letters[command[2]]:
            number = labels[command[3:]]
    elif c == 'G':
        if letters[command[1]] > letters[command[2]]:
            number = labels[command[3:]]
    elif c == 'Q':
        break
    elif c.isdigit():
        Main_Queue.put(int(command))
    number += 1
    if number >= len(commands):
        break


