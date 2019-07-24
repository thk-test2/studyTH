
from itertools import combinations_with_replacement
from itertools import product
import operator

channel = int(input())
broken_n = int(input())
broken_button = input().split()

if channel == 100:
    print('0')
    exit()

buttons = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

# print(channel, broken_n, broken_button)

for i in broken_button:
    buttons.remove(i)

final_buttons = []

# for i in range(len(buttons)):
    # final_buttons = final_buttons + list(permutations(buttons, i))
# final_buttons = final_buttons + list(combinations_with_replacement(buttons, 3))
final_buttons = final_buttons + list(product(buttons, repeat=len(buttons)))
# print(final_buttons)

new_final_buttons = []

for i in range(1, len(final_buttons)):
    test = int(''.join(final_buttons[i]))
    new_final_buttons.append(test)


abs_list = []
if channel in new_final_buttons:
    print(len(str(channel)))
else:
    for i in range(0, len(new_final_buttons)):
        abs_list.append(abs(new_final_buttons[i]-channel))


min_index, min_value = min(enumerate(abs_list), key=operator.itemgetter(1))
original_value = new_final_buttons[min_index]
# print(new_final_buttons)
# print(abs_list)

print(len(str(original_value)) + min_value)
