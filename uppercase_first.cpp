#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define SPACE ' '

int main()
{
    char ca_Word[200] = "War does Not determine Who is Right only who is Left";
    char ca_upper_array[200];
    char ca_lower_array[200];
    char ca_reverse_array[200];

    memset(ca_upper_array, 0x00, sizeof(ca_upper_array));
    memset(ca_lower_array, 0x00, sizeof(ca_lower_array));
    memset(ca_reverse_array, 0x00, sizeof(ca_reverse_array));

    int i_index_Word = 0;
    int i_index_upper = 0;
    int i_index_lower = 0;
    
    // 문자열 순회. 대소문자 구분해서 각각 배열에 담음.
    for (i_index_Word; i_index_Word < strlen(ca_Word); i_index_Word++){        
        // 대문자 구분
        if (ca_Word[i_index_Word] >= 'A' && ca_Word[i_index_Word] <= 'Z'){
            while (!(ca_Word[i_index_Word] == SPACE)){
                ca_upper_array[i_index_upper] = ca_Word[i_index_Word];
                
                i_index_Word++;
                i_index_upper++;
            }

            ca_upper_array[i_index_upper] = SPACE;

            i_index_upper++;
        }
        // 소문자 구분
        else
        if (ca_Word[i_index_Word] >= 'a' && ca_Word[i_index_Word] <= 'z'){            
            while (!(ca_Word[i_index_Word] == SPACE)){
                ca_lower_array[i_index_lower] = ca_Word[i_index_Word];

                i_index_Word++;
                i_index_lower++;
            }
            
            ca_lower_array[i_index_lower] = SPACE;

            i_index_lower++;
        }
    }    
    // 공백 제거
    ca_lower_array[strlen(ca_lower_array) - 1] = 0x00;
    
    int l = strlen(ca_lower_array);
    int i_index_reverse = 0;    
    int i_index_temp;
    int i = 0;

    // ca_lower_array 배열을 역순회
    for (l; l >= 0; l--){
        // 공백으로 단어를 구분. ca_reverse_array 배열에 추가.
        if (ca_lower_array[l] == SPACE){
            i_index_temp = l + 1;

            while (!(ca_lower_array[i_index_temp] == SPACE || ca_lower_array[i_index_temp] == 0x00)){
                ca_reverse_array[i_index_reverse] = ca_lower_array[i_index_temp];                

                i_index_reverse++;
                i_index_temp++;
            }
            // 단어를 배열에 담고 띄어쓰기 한 칸.
            ca_reverse_array[i_index_reverse] = SPACE;

            i_index_reverse++;
        }


        // 배열 순회가 끝나기 직전, lower_array의 첫 단어를 담는다.
        if (l == 0) {
            while (!(ca_lower_array[i] == SPACE)){
                ca_reverse_array[i_index_reverse] = ca_lower_array[i];

                i_index_reverse++;
                i++;
            }
        }
    }

    cout << ca_upper_array << " " << ca_reverse_array;
}
