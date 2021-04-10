fin = open("brackets.in")
fout = open("brackets.out", "w")
Stack = [0]*10000
head = 0
checker_left = 0
checker_right = 0
Main_Array = [0]*10000
for line in fin:
    Input_Array = line.rstrip()
    for i in range(len(Input_Array)):
        if Input_Array[i] == "(" or Input_Array[i] == "[" or Input_Array[i] == ")" or Input_Array[i] == "]":
            Main_Array[head] = Input_Array[i]
            head += 1
    if len(Main_Array) % 2 == 0:
        for symbol in Main_Array:
            if symbol == "(" or symbol == "[":
                Main_Array[head] = symbol
                head += 1
            elif symbol == ")":
                checker_left = 1
                if len(Stack) != 0:
                    if Stack[len(Stack) - 1] == "(":
                        head -= 1
                    else:
                        checker_right = 1
                        break
                else:
                    checker_right = 1
                    break
            elif symbol == "]":
                checker_left = 1
                if len(Stack) != 0:
                    if Stack[len(Stack) - 1] == "[":
                        head -= 1
                    else:
                        checker_right = 1
                        break
                else:
                    checker_right = 1
                    break
        if checker_right == 0 and checker_left == 1:
            fout.write("YES")
            fout.write('\n')
        else:
            fout.write("NO")
            fout.write('\n')
    else:
        fout.write("NO")
        fout.write('\n')
    Stack = [0]*10000
    Main_Array = [0]*10000
    checker_left = 0
    checker_right = 0

fout.close()
