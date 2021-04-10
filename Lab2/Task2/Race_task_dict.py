def is_les(str1:str, str2:str) -> bool:
    min_len = min(len(str1), len(str2))
    return True if (str1[:min_len].lower() < str2[:min_len].lower()) else False


def qsort(values : list, left : int, right : int):
    if left >= right: return

    buffer = values[left]
    index = (left + right)//2
    values[left] = values [index]
    values[index] = buffer

    last = left
    for i in range(left + 1, right + 1):
        if is_les(values[i], values[left]):
            last += 1
            buffer = values[i]
            values[i] = values [last]
            values[last] = buffer

    buffer = values[left]
    values[left] = values [last]
    values[last] = buffer
    qsort(values, left, last - 1)
    qsort(values, last+1, right)


results_dict = {}
with open("race.in", "r") as input_file:
    n = int(input_file.readline())
    for i in range(n):
        country_name, runner_second_name = input_file.readline().split()
        if results_dict.get(country_name, False):
            results_dict[country_name].append(runner_second_name)
        else:
            results_dict[country_name] = [runner_second_name]
    sorted_list = list(results_dict.keys())
    qsort(sorted_list, 0, len(sorted_list) - 1)

with open("race.out", "w") as output_file:
    for key in sorted_list:
        print(f"=== {key} ===", file=output_file)
        for value in results_dict[key]:
            print(value, file=output_file)
