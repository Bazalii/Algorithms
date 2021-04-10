def is_les(str1: str, str2: str) -> bool:
    min_len = min(len(str1), len(str2))
    return True if (str1[:min_len] < str2[:min_len]) else False


def swap(values, i1, i2):
    buffer = values[i1]
    values[i1] = values[i2]
    values[i2] = buffer


def qsort(values: list, players: list, left: int, right: int):
    if left >= right:
        return

    swap(values, (left + right) // 2, left)
    swap(players, (left + right) // 2, left)

    last = left
    for i in range(left + 1, right + 1):
        if is_les(values[i], values[left]):
            last += 1
            swap(values, i, last)
            swap(players, i, last)

    swap(values, left, last)
    swap(players, left, last)
    qsort(values, players, left, last - 1)
    qsort(values, players, last + 1, right)


countries_name = []
players = []
with open("race.in", "r") as input_file:
    n = int(input_file.readline())
    for i in range(n):
        country_name, runner_second_name = input_file.readline().split()
        if country_name in countries_name:
            players[countries_name.index(country_name)].append(runner_second_name)
        else:
            countries_name.append(country_name)
            players.append([runner_second_name])
    qsort(countries_name, players, 0, len(countries_name) - 1)

with open("race.out", "w") as output_file:
    for key in countries_name:
        print(f"=== {key} ===", file=output_file)
        for value in players[countries_name.index(key)]:
            print(value, file=output_file)
