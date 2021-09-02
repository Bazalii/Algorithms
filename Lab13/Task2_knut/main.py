fin = open("search2.in")
fout = open("search2.out", "w")
wanted_string = fin.readline().rstrip()
main_string = fin.readline().rstrip()
wanted_string_size = len(wanted_string)
main_string_size = len(main_string)
if main_string_size < wanted_string_size:
    print(0, file=fout)
    exit(0)
main_string = wanted_string + '&' + main_string
prefix = [0] * (len(main_string) + 1)
answer = []
i = 1
j = 0
while i < main_string_size + wanted_string_size + 1:
    if main_string[i] == main_string[j]:
        prefix[i + 1] = j + 1
        i += 1
        j += 1
    else:
        if j > 0:
            j = prefix[j]
        else:
            prefix[i + 1] = 0
            i += 1
for i in range(main_string_size + 1):
    if prefix[wanted_string_size + i + 1] == wanted_string_size:
        answer.append(i - wanted_string_size + 1)
print(len(answer), file=fout)
print(" ".join(map(str, answer)), file=fout)
