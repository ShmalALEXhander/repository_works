#include <iostream>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <errno.h>
#include <iomanip>
#include "Structs.h"
#include "Prototips.h"
using namespace std;

#pragma warning(disable : 4996) 

const char* PATH = "C:\\Users\\Александр\\source\\repos\\ProjectC++DataBase\\ProjectC++DataBase";

int open_b_r(int* fd) {
    char buf[128];
    strcpy(buf, PATH);
    strcat(buf, "\\books.txt");
    errno_t err1 = _sopen_s(fd, buf, O_RDONLY | O_CREAT | O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
    if (err1 != 0) {
        cout << strerror(err1) << endl; return -1;
    }
}
int open_a_r(int* fd) {
    char buf[128];
    strcpy(buf, PATH);
    strcat(buf, "\\authors.txt");
    errno_t err1 = _sopen_s(fd, buf, O_RDONLY | O_CREAT | O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
    if (err1 != 0) {
        cout << strerror(err1) << endl; return -1;
    }
}
int open_p_r(int* fd) {
    char buf[128];
    strcpy(buf, PATH);
    strcat(buf, "\\publishers.txt");
    errno_t err1 = _sopen_s(fd, buf, O_RDONLY | O_CREAT | O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
    if (err1 != 0) {
        cout << strerror(err1) << endl; return -1;
    }
}
int open_p_w(int* fd) {
    char buf[126];
    strcpy(buf, PATH);
    strcat(buf, "\\publishers.txt");
    errno_t err = _sopen_s(fd, buf, O_RDWR | O_CREAT | O_BINARY, _SH_DENYRW, _S_IREAD | _S_IWRITE);
    if (err != 0) {
        cout << strerror(err) << endl; return -1;
    }
    return 1;
}
int open_a_w(int* fd) {
    char buf[126];
    strcpy(buf, PATH);
    strcat(buf, "\\authors.txt");
    errno_t err = _sopen_s(fd, buf, O_RDWR | O_CREAT | O_BINARY, _SH_DENYRW, _S_IREAD | _S_IWRITE);
    if (err != 0) {
        cout << strerror(err) << endl; return -1;
    }
    return 1;
}
int open_b_w(int* fd) {
    char buf[126];
    strcpy(buf, PATH);
    strcat(buf, "\\books.txt");
    errno_t err = _sopen_s(fd, buf, O_RDWR | O_CREAT | O_BINARY, _SH_DENYRW, _S_IREAD | _S_IWRITE);
    if (err != 0) {
        cout << strerror(err) << endl; return -1;
    }
    return 1;
}
int open_db_r(int* fd_b, int* fd_a, int* fd_p) {
    char buf[128];
    strcpy(buf, PATH);
    strcat(buf, "\\books.txt");
    errno_t err1 = _sopen_s(fd_b, buf, O_RDONLY | O_CREAT | O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
    if (err1 != 0) {
        cout << strerror(err1) << endl; return -1;
    }
    strcpy(buf, PATH);
    strcat(buf, "\\authors.txt");
    errno_t err2 = _sopen_s(fd_a, buf, O_RDONLY | O_CREAT | O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
    if (err2 != 0) {
        cout << strerror(err2) << endl; return -1;
    }
    strcpy(buf, PATH);
    strcat(buf, "\\publishers.txt");
    errno_t err3 = _sopen_s(fd_p, buf, O_RDONLY | O_CREAT | O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
    if (err3 != 0) {
        cout << strerror(err3) << endl; return -1;
    }
    return 1;
}
int open_db_w(int* fd_b, int* fd_a, int* fd_p) {
    char buf[128];
    strcpy(buf, PATH);
    strcat(buf, "\\books.txt");
    errno_t err1 = _sopen_s(fd_b, buf, O_RDWR | O_CREAT | O_BINARY, _SH_DENYRW, _S_IREAD | _S_IWRITE);
    if (err1 != 0) {
        cout << strerror(err1) << endl; return -1;
    }
    strcpy(buf, PATH);
    strcat(buf, "\\authors.txt");
    errno_t err2 = _sopen_s(fd_a, buf, O_RDWR | O_CREAT | O_BINARY, _SH_DENYRW, _S_IREAD | _S_IWRITE);
    if (err2 != 0) {
        cout << strerror(err2) << endl; return -1;
    }
    strcpy(buf, PATH);
    strcat(buf, "\\publishers.txt");
    errno_t err3 = _sopen_s(fd_p, buf, O_RDWR | O_CREAT | O_BINARY, _SH_DENYRW, _S_IREAD | _S_IWRITE);
    if (err3 != 0) {
        cout << strerror(err3) << endl; return -1;
    }
    return 1;
}
int close_db(int fd_b, int fd_a, int fd_p) {
    close(fd_b);
    close(fd_a);
    close(fd_p);
    return 1;
}