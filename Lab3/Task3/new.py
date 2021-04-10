def count_sort_letters(array, size, col, base, max_len):
  """ Helper routine for performing a count sort based upon column col """
  output   = [0] * size
  count    = [0] * (base + 1) # One addition cell to account for dummy letter
  min_base = ord('a') - 1 # subtract one too allow for dummy character

  for item in array: # generate Counts
    # get column letter if within string, else use dummy position of 0
    letter = ord(item[col]) - min_base if col < len(item) else 0
    count[letter] += 1

  for i in range(len(count)-1):   # Accumulate counts
      count[i + 1] += count[i]

  for item in reversed(array):
    # Get index of current letter of item at index col in count array
    letter = ord(item[col]) - min_base if col < len(item) else 0
    output[count[letter] - 1] = item
    count[letter] -= 1

  return output

def radix_sort_letters(array, max_col = None):
  """ Main sorting routine """
  if not max_col:
    max_col = len(max(array, key = len)) # edit to max length

  for col in range(max_col-1, -1, -1): # max_len-1, max_len-2, ...0
    array = count_sort_letters(array, len(array), col, 26, max_col)

  return array

lst = ['bbb', 'aba', 'baa']
print(radix_sort_letters(lst, 3))