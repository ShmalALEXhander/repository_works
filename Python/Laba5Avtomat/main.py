import pandas as pd

alfa = ['a', 'b']
print("Текущий алфавит: ", alfa)
m = 4  # часть словаря а е временная переменная  # a=[] b=a b - не копия, а его аватар а не самостоятельный массив.  a связана с b
print("Текущее количество вершин: ", m)
versh = ["q" + str(i) for i in range(m)]
start = input("Введите начальную вершину q с индексом n: ")
end = input("Введите конечную вершину q с индексом n: ")
slovar = {'q0': {'a': {'q1'}, 'b': set(), 'E': {'q0', 'q3'}},
          'q1': {'a': {'q1'}, 'b': {'q0'}, 'E': {'q1', 'q2'}},
          'q2': {'a': set(), 'b': {'q1'}, 'E': {'q2'}},
          'q3': {'a': set(), 'b': {'q2'}, 'E': {'q3'}}
          }

for i in slovar:
    tmp = slovar[i]["E"]
    for j in tmp:
        for k in alfa:
            slovar[i][k] |= slovar[j][k]
            slovar[i]["E"] |= slovar[j]["E"]
    tmp = []
    for f in range(m - 1):
        for k in alfa:
            tmp = slovar[i][k]
            for j in tmp.copy():
                slovar[i][k] |= slovar[j]["E"]

print("\n", slovar)


slist = {}
k = 0
for i in versh:
    slist["S" + str(k)] = slovar[i]["E"]
    k += 1
print("\n", slist, "\n")
# Новые конечные точки S
endTmp = []  # объявляем список
count2 = len(slist) - len(end)  # Конечная вершина не может быть начальной
# print(count2)
if len(end) > 1:
    for i in end:
        count2 += 1
        count = 0
        for j in slist:
            for k in slist[j]:
                if i in k:
                    endTmp.append(j)
                    count += 1
            if count == count2:
                break

else:  # Ассоциативный массив в пайтоне несортирован. Стоит это помнить
    for i in slist:
        for j in slist[i]:
            if end[0] in j:  # q2 у нас в j есть ?
                endTmp.append(i)
endTmp = list(set(endTmp))  # set убирает все повторы и листом преобразует в список
print(endTmp)

s2list = {}
for i in slist:
    tmpslov = {}
    for k in alfa:
        tmp2 = []
        n = set()
        for j in list(slist[i]):
            n = n.union(slovar[j][k])
        for j in slist:
            if (slist[j] <= n):
                tmp2.append(j)
        tmpslov[k] = set(tmp2)
    s2list[i] = tmpslov
df = pd.DataFrame(s2list)
df = df.T
print(df, "\n")
