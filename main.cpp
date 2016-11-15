/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dmytro
 *
 * Created on November 15, 2016, 5:56 PM
 */



// test.cpp : Defines the entry point for the console application.
//
#include <cstdlib>
#include <cstdio>
#include <cstring>


inline int difference(char A, char B, int correction);
inline char getCharByIndex(char* string, int stringLen, int index);
void stringRevertion(char* string, int lastStringIndex);

char numbers[] = "0123456789";

inline int difference(char A, char B, int correction = 0)
{
    return (int)(A) - (int)(B) - correction;
}

inline char getCharByIndex(char* string, int stringLen, int index)
{
    if (index < 0)
    {
        return '0';
    }
    return string[index];
}

void stringRevertion(char* string, int lastStringIndex)
{
    int lastIndex = lastStringIndex;
    for (int i = 0; i < lastStringIndex >> 1; i++, lastIndex--)
    {
        char temp = string[i];
        string[i] = string[lastIndex];
        string[lastIndex] = temp;
    }
}

int strLen(char *str)
{
    int len = 0;
    while (str++)
    {
        len++;
    }
    return len + 1;
}

char* SubStraction(char* A, char* B, char *C, const int lenOfC)
{
    const int lenOfA = strlen(A);
    const int lenOfB = strlen(B);
    int indexOfA = lenOfA - 1;
    int indexOfB = lenOfB - 1;
    int indexOfC = 0;

    int longestStrLen = strlen(lenOfA > lenOfB ? A : B);
    int correction = 0;

    if (lenOfA <= 0 || lenOfB <= 0 || lenOfC < longestStrLen || lenOfC < 0)
    {
        return NULL;
    }

    for (int i = longestStrLen - 1; i >= 0; i--, indexOfA--, indexOfB--)
    {
        
        int reminder = difference(getCharByIndex(A, lenOfA, indexOfA), 
                                  getCharByIndex(B, lenOfB, indexOfB), 
                                  correction);
        
        if (reminder >= 0)
        {
            C[indexOfC] = (char)((int)'0' + reminder);
            correction = 0;
        }
        else
        {
            C[indexOfC] = (char)((int)'0' + (10 + reminder));
            correction = 1;
        }

        indexOfC++;
    }

    stringRevertion(C, indexOfC - 1);
    C[indexOfC] = '\0';
    return C;
}


int main(int argc, char** argv) 
{
    char *A = "19876543210";
    char *B = "1234567890";
    char C[255];
    
    printf("%s\n", SubStraction(A,B,C,sizeof(C)));
    
    return 0;
}

