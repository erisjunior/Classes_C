#include <stdio.h>

int main(){
    int number;

    scanf("%d", &number);

    while (number > 0){
        if (number >= 900) {
            number = number - 900;
            printf("CM");
        } else if (number >= 800) {
            number = number - 800;
            printf("DCCC");
        } else if (number >= 700) {
            number = number - 700;
            printf("DCC");
        } else if (number >= 600) {
            number = number - 600;
            printf("DC");
        } else if (number >= 500) {
            number = number - 500;
            printf("D");
        } else if (number >= 400) {
            number = number - 400;
            printf("CD");
        } else if (number >= 300) {
            number = number - 300;
            printf("CCC");
        } else if (number >= 200) {
            number = number - 200;
            printf("CC");
        } else if (number >= 100) {
            number = number - 100;
            printf("C");
        } else if (number >= 90) {
            number = number - 90;
            printf("XC");
        } else if (number >= 80) {
            number = number - 80;
            printf("LXXX");
        } else if (number >= 70) {
            number = number - 70;
            printf("LXX");
        } else if (number >= 60) {
            number = number - 60;
            printf("LX");
        } else if (number >= 50) {
            number = number - 50;
            printf("L");
        } else if (number >= 40) {
            number = number - 40;
            printf("XL");
        } else if (number >= 30) {
            number = number - 30;
            printf("XXX");
        } else if (number >= 20) {
            number = number - 20;
            printf("XX");
        } else if (number >= 10) {
            number = number - 10;
            printf("X");
        } else if (number >= 9) {
            number = number - 9;
            printf("IX");
        } else if (number >= 8) {
            number = number - 8;
            printf("VIII");
        } else if (number >= 7) {
            number = number - 7;
            printf("VII");
        } else if (number >= 6) {
            number = number - 6;
            printf("VI");
        } else if (number >= 5) {
            number = number - 5;
            printf("V");
        } else if (number >= 4) {
            number = number - 4;
            printf("IV");
        } else if (number >= 3) {
            number = number - 3;
            printf("III");
        } else if (number >= 2) {
            number = number - 2;
            printf("II");
        } else if (number >= 1) {
            number = number - 1;
            printf("I");
        }
    }

    printf("\n");

    return 0;
}
