'''LEETCODE 394 (Strings)'''

def decodeString(s: str) -> str:

    'Using Stacks, not super complictated though'
    
    num_stack = []
    str_stack = []
    current_num = 0
    current_str = []

    for ch in s:
        if ch.isdigit():
            current_num = current_num * 10 + int(ch)

        elif ch == '[':
            num_stack.append(current_num)
            str_stack.append(''.join(current_str))
            current_str = []
            current_num = 0
        elif ch == ']':
            digit = num_stack.pop()
            previous_string = str_stack.pop()
            current_str = [previous_string + ''.join(current_str)*digit]

        else:
            current_str.append(ch)

    return ''.join(current_str)

char = "3[ab2[b]]"

print(decodeString((char)))

