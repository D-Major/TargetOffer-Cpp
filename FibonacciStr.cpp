// Created by D_Major on 2020/3/29.
#include <iostream>
#include <cstring>

using namespace std;

int* Char_Count(char *s){
    int i = 0;
    static int res[26] = {0};
    int len = strlen(s);
    while(len > 0){
        if(s[i] >= 'a' && s[i] <= 'z')
            res[s[i]-'a']++;
        i++;
        len--;
    }

    return res;
}

int* Fibonacci_Str(int n, char *str1, char *str2){
    /* f(n)=f(n-1)+f(n-2) */
    if(n == 0)
        return nullptr;
    if(n == 1)
        return Char_Count(str1);
    if(n == 2)
        return Char_Count(str2);
    char* one = str1;
    char* two = str2;
    char* fib = {};

    while(n > 2){
        fib = strcat(one,two);
        one = two;
        two = fib;
        n--;
    }
    return Char_Count(fib);
}

bool IsLower(const char *s){
    char c;
    int i = 0;
    while(s[i]){
        c = s[i];
        if(!islower(c))
            return false;
        i++;
    }
    return true;
}

int main(){
    int n=6;
    char s1[10]="abc";
    char s2[10]="af";
//    cin >> n;
//    cin >> s1 >> s2;
    if(n<=0 || n>=40)
        return 0;
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    if(len_s1 <= 0 || len_s1 >= 10 ||
       len_s2 <= 0 || len_s2 >= 10)
        return 0;
    if(!IsLower(s1) || !IsLower(s2))
        return 0;
    int* res = Fibonacci_Str(n, s1, s2);
    char outstring[26] = {'a','b','c','d','e','f',
                          'g','h','i','j','k','l',
                          'm','n','o','p','q','r',
                          's','t','u','v','w','x','y','z'};
    for(int j = 0; j < 26; j++){
        if(res[j] != 0)
            cout << outstring[j] << ":" << res[j] << endl;
    }

    return 0;
}