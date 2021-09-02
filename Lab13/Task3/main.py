fin = open("prefix.in")
fout = open("prefix.out", "w")
i = 1
j = 0
main_string = fin.readline().rstrip()
answer = [0] * (len(main_string) + 1)
while i < len(main_string):
    if main_string[i] == main_string[j]:
        answer[i + 1] = j + 1
        i += 1
        j += 1
    else:
        if j > 0:
            j = answer[j]
        else:
            answer[i + 1] = 0
            i += 1
print(" ".join(map(str, answer[1:len(answer)])), file=fout)
