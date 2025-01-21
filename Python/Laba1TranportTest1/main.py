f = open("C:\\Users\\Александр\\Desktop\\data\\data.txt")
line = f.readline()
sklad = [int(x) for x in line.split()] # символ разделителя можно ставить в скобку
line = f.readline()
potr = [int(x) for x in line.split()]

mtr = []
print("Вектор поставщиков")
print(sklad)
print("Вектор потребителей")
print(potr)
print("План перевозок - пустой")
P = len(potr)
S = len(sklad)

sumSklad = sum(sklad)
sumPotr = sum(potr)


if sumSklad == sumPotr:
    for j in range(S):
        a1 = []
        for i in range(P):
            a1.append(0)
        mtr.append(a1)
    #print(mtr)
    for line in mtr:
        print(line)
    for i in range(P):
        for j in range(S):
            if potr[i] > sklad[j]:
                mtr[i][j] = sklad[j]
                potr[i] -= sklad[j]
                sklad[j] = 0
            else:
                mtr[i][j] = potr[i]
                sklad[j] -= potr[i]
                potr[i] = 0
                break

    print("----------------------------------")
    print("План перевозок по северо-западному углу")
    for line in mtr:
        print(line)
    print("Вектор поставщиков")
    print(sklad)
    print("Вектор потребителей")
    print(potr)

elif sumSklad > sumPotr: # добавили фиктивного потребителя
    potr.append(sumSklad-sumPotr)
    P = len(potr)
    for j in range(S):
        a1 = []
        for i in range(P):
            a1.append(0)
        mtr.append(a1)

    for i in range(P):
        for j in range(S):
            if potr[i] > sklad[j]:
                mtr[i][j] = sklad[j]
                potr[i] -= sklad[j]
                sklad[j] = 0
            else:
                mtr[i][j] = potr[i]
                sklad[j] -= potr[i]
                potr[i] = 0
                break
    for line in mtr:
        print(line)

elif sumSklad < sumPotr: # добавили фиктивного поставщика
    sklad.append(sumPotr-sumSklad)
    for j in range(S):
        a1 = []
        for i in range(P + 1):
            a1.append(0)
        mtr.append(a1)

    for i in range(P + 1):
        for j in range(S):
            if potr[i] > sklad[j]:
                mtr[i][j] = sklad[j]
                potr[i] -= sklad[j]
                sklad[j] = 0
            else:
                mtr[i][j] = potr[i]
                sklad[j] -= potr[i]
                potr[i] = 0
                break

    for line in mtr:
     print(line)