#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define thTrillion 1000000000000000
#define trillion 1000000000000
#define billion 1000000000
#define million 1000000
#define thousand 1000

const char numString[10][7] = {"",     "mot ", "hai ", "ba ",  "bon ",
                               "nam ", "sau ", "bay ", "tam ", "chin "};

int count(unsigned long long int n) {
    int count = 1;
    while (n /= 10) {
        count++;
    }
    return count;
}
char* Case3(unsigned long long int n) {
    char* s = (char*)malloc(sizeof(char) * 500);
    strcpy(s, "");
    switch (count(n)) {
    case 3:
        strcat(s, numString[n / 100]);
        strcat(s, "tram ");
        n %= 100;
        if (n == 0) {
            break;
        }
    case 2:
        if (n < 10) {
            strcat(s, "le ");
            strcat(s, numString[n]);
            return s;
        }
        if (n / 10 != 1) {
            strcat(s, numString[n / 10]);
        }
        strcat(s, "muoi ");
        n %= 10;
        if (n == 0) {
            break;
        }
    case 1:
        strcat(s, numString[n % 10]);
    }
    return s;
}
int check(char* buf, unsigned long long int n) {
    if (n < 10) {
        strcat(buf, "le ");
        strcat(buf, numString[n]);
        return 1;
    }
    return 0;
}
char* Convert(unsigned long long n) {
    char buf[2000];
    strcpy(buf, "");
    switch (count(n)) {
    case 16 ... 18:
        strcat(buf, Case3(n / thTrillion));
        strcat(buf, "trieu ");
        n %= thTrillion;
    case 13 ... 15:
        if (n / trillion != 0) {
            strcat(buf, Case3(n / trillion));
            strcat(buf, "nghin ");
        }
        n %= billion;
    case 10 ... 12:
        strcat(buf, Case3(n / billion));
        strcat(buf, "ty ");
        n %= billion;
        if (n == 0) {
            break;
        }
        if (check(buf, n)) {
            break;
        }
    case 7 ... 9:
        if (n / million != 0) {
            strcat(buf, Case3(n / million));
            strcat(buf, "trieu ");
        }
        n %= million;
        if (n == 0) {
            break;
        }
        if (check(buf, n)) {
            break;
        }
    case 4 ... 6:
        if (n / thousand != 0) {
            strcat(buf, Case3(n / thousand));
            strcat(buf, "nghin ");
        }
        n %= thousand;
        if (n == 0) {
            break;
        }
        if (check(buf, n)) {
            break;
        }
    case 1 ... 3:
        strcat(buf, Case3(n));
        break;
    }
    strcat(buf, "dong");
    char* str = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
    strcpy(str, buf);
    return str;
}
int main(void) {
    unsigned long long int n;
    scanf("%lld", &n);
    char* s = Convert(n);
    puts(s);
    free(s);
    return 0;
}