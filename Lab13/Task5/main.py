def contains(main_string, wanted_string):
    wanted_string_size = len(wanted_string)
    main_string_size = len(main_string)
    if main_string_size < wanted_string_size:
        print('NO', file=fout)
        exit(0)
    main_string = wanted_string + '&' + main_string
    prefix = [0] * (len(main_string) + 1)
    i = 1
    j = 0
    checker = False
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
            print('YES', file=fout)
            checker = True
            break
    if not checker:
        print('NO', file=fout)

fin = open("search4.in")
fout = open("search4.out", "w")
strings_to_check = []
n = int(fin.readline().rstrip())
for i in range(n):
    strings_to_check.append(fin.readline().rstrip())
main_string = fin.readline().rstrip()
for i in strings_to_check:
    contains(main_string, i)
