personalInfo = 'AB@qq.com'
personalInfo = '+12-345-678-7012'
if '@' in personalInfo:
    
    llist = personalInfo.split('@')
    name = llist[0].lower()
    first = name[0] + '*'*5 + name[-1]
    ans = first + '@' + llist[1].lower()
    print(ans)
else:
    t = ''
    for i in range(len(personalInfo)):
        if personalInfo[i] =='(' or personalInfo[i]==')' or personalInfo[i]=='+' or personalInfo[i]=='-' or personalInfo[i]==' ':
            continue
        t+=personalInfo[i];
    ans = '###-###-' + t[-4:]
    if len(t) >= 10:
        val = len(t) - 10
        ans = '+' + '#'*val + '-' + ans
    print(ans)