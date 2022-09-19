stack = []

for i in input().split():
    if i in '+-*':
        a = stack[-2]
        b = stack[-1]
        stack.pop()
        stack.pop()

        if i == '+':
            result = a+b
        elif i == '-':
            result = a-b
        else:
            result = a*b
        stack.append(result)
    else:
        stack.append(int(i))
print(stack[0])