#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define SPACE 32

main()
{
    char Word[200] = "War does Not determine Who is Right only who is Left";
    char upper_array[200];
    char lower_array[200];
    char reverse_array[200];

    memset(upper_array, 0x00, sizeof(upper_array));
    memset(lower_array, 0x00, sizeof(lower_array));
    memset(reverse_array, 0x00, sizeof(reverse_array));


    int index_Word = 0;
    int index_upper = 0;
    int index_lower = 0;
    

    // 문자열 순회. 대소문자 구분해서 각각 배열에 담음.
    for (index_Word; index_Word < strlen(Word); index_Word++){
        
        // 대문자 구분
        if (Word[index_Word] >= 65 && Word[index_Word] <= 90){
            while (!(Word[index_Word] == SPACE)){
                upper_array[index_upper] = Word[index_Word];
                
                index_Word++;
                index_upper++;
            }

            upper_array[index_upper] = SPACE;

            index_upper++;
        }

        // 소문자 구분
        else
        if (Word[index_Word] >= 97 && Word[index_Word] <= 122){
            
            while (!(Word[index_Word] == SPACE)){
                lower_array[index_lower] = Word[index_Word];

                index_Word++;
                index_lower++;
            }
            
            lower_array[index_lower] = SPACE;

            index_lower++;
        }
    }
    
    // 공백 제거
    lower_array[strlen(lower_array) - 1] = 0x00;

    
    int l = strlen(lower_array);
    int index_reverse = 0;    
    int index_temp;
    int x = 0;

    // lower_array 배열을 역순회
    for (l; l >= 0; l--){
        // 공백으로 단어를 구분. reverse_array 배열에 추가.
        if (lower_array[l] == SPACE){
            index_temp = l + 1;

            while (!(lower_array[index_temp] == SPACE || lower_array[index_temp] == 0x00)){
                reverse_array[index_reverse] = lower_array[index_temp];                

                index_reverse++;
                index_temp++;
            }

            // 단어를 배열에 담고 띄어쓰기 한 칸.
            reverse_array[index_reverse] = SPACE;

            index_reverse++;
        }


        // 배열 순회가 끝나기 직전, lower_array의 첫 단어를 담는다.
        if (l == 0) {
            while (!(lower_array[x] == SPACE)){
                reverse_array[index_reverse] = lower_array[x];

                index_reverse++;
                x++;
            }
        }
    }

    cout << upper_array << " " << reverse_array;
}
