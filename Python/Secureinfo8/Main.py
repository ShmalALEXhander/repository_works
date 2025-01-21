import random

def primes(n): 
    primes_list = [] 
    for num in range(2, n):
        if all(num % i != 0 for i in range(2, int(num * 0.5) + 1)):
            primes_list.append(num)
    return primes_list

def is_prime(num): 
    if num <= 1:
        return False
    for i in range(2, int(num * 0.5) + 1):
        if num % i == 0:
            return False
    return True

def gcd(a, b):  #
    while b:
        a, b = b, a % b
    return a

def find_coprimes(num, primes):
    coprimes = [prime for prime in primes if gcd(num, prime) == 1]
    return coprimes

def find_d(fi, exp, primes): 
    for el in primes:  
        if (el * exp) % fi == 1:
            return el


# 1. Генерирует простые числа p и q.
# 2. Вычисляет модуль mod = p * q.
# 3. Вычисляет φ(n) = (p-1) * (q-1).
# 4. Выбирает экспоненту exp из взаимно простых чисел.
# 5. Находит секретный ключ d, удовлетворяющий (d * exp) % φ(n) == 1.
def get_keys():
    d = None
    exp = 0
    n = 0
    while d is None:
        iter = 1000  
        primes_arr = primes(iter)
        p = random.choice(primes_arr)
        q = random.choice(primes_arr)
        while p == q:
            q = random.choice(primes_arr)

        n = p * q
        fi = (p - 1) * (q - 1)

        ferm_numbers = [3, 5, 17, 65537]

        for i in ferm_numbers:
            if i < fi and gcd(i, fi) == 1:
                exp = i
                break
        d = find_d(fi, exp, primes_arr)
        print("p = ", p)
        print("q = ", q)
        print("n = ", n)
        print("exp = ", exp)
        print("d = ", d)
    return exp, n, d

def letter_position(letter):
    if 'a' <= letter <= 'z':
        return ord(letter) - ord('a')
    elif 'A' <= letter <= 'Z':
        return ord(letter) - ord('A') + 26 
    return -1

def letter_by_position(position):
    if 0 <= position < 26:
        return chr(position + ord('a'))
    elif 26 <= position < 52:
        return chr(position - 26 + ord('A'))
    return '?'

def encode_letter(exp, mod, letter):
    return pow(letter, exp, mod)

def decode_letter(d, mod, letter):
    return pow(letter, d, mod)

exp, n, d = get_keys()

word = input("Введите слово: ")
word_arr = [letter_position(i) for i in word if letter_position(i) != -1]

print(f"Представление в виде цифр (ASCII): {word_arr}")

encode_word = [encode_letter(exp, n, el) for el in word_arr]
print(f"Закодированное слово: {encode_word}")

decode_word = [decode_letter(d, n, el) for el in encode_word]
print(f"Декодированное слово: {decode_word}")

final_word = "".join([letter_by_position(el) for el in decode_word])
print(f"Итоговое слово: {final_word}")