#pragma warning(disable:4996)

#include <cctype>
#include <cstdio>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

void demo_scanf(const char* fmt, std::FILE* s) {
    while (*fmt != '\0') {
        if (*fmt == '%') {
            switch (*++fmt) {
            case 'u': {
                int c{};
                while (std::isspace(c = std::getc(s))) {}
                unsigned int num{};
                while (std::isdigit(c)) {
                    num = num * 10 + c - '0';
                    c = std::getc(s);
                }
                std::printf("%%u scanned %u\n", num);
                std::ungetc(c, s);
                break;
            } case 'c': {
                int c = std::getc(s);
                std::printf("%%c scanned '%c'\n", c);
                break;
            }
            }
        }
        else {
            ++fmt;
        }
    }
}

int main() {
    if (std::FILE* f = std::fopen("input.txt", "w+")) {
        std::fputs("123x", f);
        std::rewind(f);
        demo_scanf("%u%c", f);
        std::fclose(f);
    }

    _getch();
    return 0;
}