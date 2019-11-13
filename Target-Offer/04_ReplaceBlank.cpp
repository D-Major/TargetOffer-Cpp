// Created by renduo on 19-11-13.
#include <iostream>
#include <vector>

using namespace std;

void ReplaceBlank(char *str, int length){
    /** 双指针从后往前遍历, 遇到空格替换为%20 */
    if(str == NULL || length <= 0)
        return;
    cout << str << endl;
    int origin_length = 0;
    int blank_num = 0;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ' ')
            blank_num++;
        origin_length++;
        i++;
    }
    int new_length = origin_length + blank_num*2;
    if(new_length > length)
        return;
    int index_origin = origin_length;
    int index_new = new_length;
    while(index_origin >= 0 && index_new > index_origin){
        if(str[index_origin] != ' '){
            str[index_new--] = str[index_origin--];
        }else{
            str[index_new--] = '0';
            str[index_new--] = '2';
            str[index_new--] = '%';
            index_origin--;
        }
    }
    cout << str << endl;
}