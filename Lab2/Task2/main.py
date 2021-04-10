def merge_sort(Main, Check, left, right):
    if left == right:
        Check.insert(left, Main[left])
        return Check
    middle = (left + right) // 2
    left_subarray = merge_sort(Main, Check, left, middle)
    right_subarray = merge_sort(Main, Check, middle + 1, right)
    outcome = Check.copy() if left_subarray == Main else Main.copy()
    current_left = left
    current_right = middle + 1
    for i in range(left, right + 1):
        if current_left <= middle and current_right <= right:
            if left_subarray[current_left] < right_subarray[current_right]:
                outcome.pop(i)
                outcome.insert(i, left_subarray[current_left])
                current_left += 1
            else:
                outcome.pop(i)
                outcome.insert(i, right_subarray[current_right])
                current_right += 1
        elif current_left <= middle:
            outcome.pop(i)
            outcome.insert(i, left_subarray[current_left])
            current_left += 1
        else:
            outcome.pop(i)
            outcome.insert(i, right_subarray[current_right])
            current_right += 1
    return outcome

fin = open("race.in")
fout = open("race.out", "w")
n = int(fin.readline())
Dictionary = {}
Input_Array = []
Help_Array = []
for i in range(n):
    Input_Array = fin.readline().split()
    if Input_Array[0] not in Dictionary.keys():
        Check_string = Input_Array[0]
        Input_Array[0].lower()
        Dictionary[Input_Array[0]] = []
        Help_Array.append(Input_Array[0])
        Dictionary[Input_Array[0]].append(Check_string)
    Dictionary[Input_Array[0]].append(Input_Array[1])
# Input_Array = [0]*len(Help_Array)
Input_Array.clear()
merge_sort(Help_Array, Input_Array, 0, len(Help_Array) - 1)
for g in range(len(Help_Array)):
    print('=== ' + Dictionary[Help_Array[g]][0] + " ===", file=fout)
    for p in range(1, len(Dictionary[Help_Array[g]])):
        print(Dictionary[Help_Array[g]][p], file=fout)
fout.close()
