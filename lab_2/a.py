with open('input.txt','r') as line:
    lis=[i.rstrip()  for i in line .readlines() if i.rstrip()]
for i in sorted(set(lis)):
    print(i,lis.count(i))