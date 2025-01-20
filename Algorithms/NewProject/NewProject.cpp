#include <iostream>

using namespace std;

using byte = unsigned char;
const int SIZE = 16;
const int BLOCK = 8;

union {
    byte mem[SIZE] = { 0x84,0x13 };
    struct {
        byte mat[SIZE / BLOCK];
        byte tab[SIZE / BLOCK];
    } tables;
} memory;

inline int is_free(int pos) {
    return (memory.tables.mat[pos / 8] & (0x80 >> (pos % 8))) == 0 ? 0 : 1;
}
int get_num(int size) {
    int p0;
    int len;
    for (int i = 0; i < SIZE; i++) {
        if (is_free(i) == 1) continue;
        else {
            p0 = i;
            len = 1;
            while (is_free(++i) == 0) {
                len++;
                if (len == size)
                    return p0;
            }
        }
    }
    return 0;
}
// mat memory allocate table хранит в бите единицу, если соответствующий блок памяти занят
// tab хранит в бите единицу, если соответствующий блок не последний и 0, если блок последний 
int get_mem(int size) {
    int st;
    if (st = get_num(size)) {
        int i;
        for (i = 0; i < size; i++) {
            memory.tables.mat[(st + i) / 8] |= (0x80 >> ((st + i) % 8));
            memory.tables.tab[(st + i) / 8] |= (0x80 >> ((st + i) % 8));

        }
        memory.tables.tab[st + i] = 0;
        return st;
    }
    else return 0;
}

int free_mem(int pos) {
    if (memory.tables.tab[(pos - 1) / 8] & (0x80 >> ((pos - 1) % 8)))
        return 0;
    int i = pos;
    while ((memory.tables.tab[(i) / 8]) & (0x80 >> ((i) % 8))) {
        memory.tables.mat[(i) / 8] &= (0x80 >> ((i) % 8)) ^ 0xff;
        memory.tables.tab[(i) / 8] &= (0x80 >> ((i) % 8)) ^ 0xff;
        i++;
    }
    //memory.tables.mat[pos+i] = 0;
    return pos;
}

int main()
{

    for (int i = 0; i < 16; i++) cout << is_free(i) << " ";
    int p = get_mem(5);
    cout << endl;
    for (int i = 0; i < 16; i++) cout << is_free(i) << " ";
    int p1 = get_mem(2);
    cout << endl;
    for (int i = 0; i < 16; i++) cout << is_free(i) << " ";
    free_mem(p1);
    cout << endl;
    for (int i = 0; i < 16; i++) cout << is_free(i) << " ";
    free_mem(p);
    cout << endl;
    for (int i = 0; i < 16; i++) cout << is_free(i) << " ";
}
