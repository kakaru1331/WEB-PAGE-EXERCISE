#include <iostream>
#include <ctime>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Card
{
    int card_number;
    const char* card_shape;
};

void CardSet(Card* card_deck);
void SwapCard(Card& first_card, Card& second_card);
void PrintCard(Card card);
void Betting(Card hidden_card, int* user_chips);
void NewLine();

const char SHAPE_SPADE[6] = "SPADE";
const char SHAPE_DIAMOND[8] = "DIAMOND";
const char SHAPE_HEART[6] = "HEART";
const char SHAPE_CLOVER[7] = "CLOVER";


main()
{
    Card card_deck[52] = {};
    
    int user_chips = 10000; // 사용자 칩 배분
    int card_index = 0;
    

    
    CardSet(card_deck); // 카드 세팅


    // 메인 게임
    while (user_chips > 100 && card_index < 48){        
        Card open_card_1 = card_deck[card_index];
        Card open_card_2 = card_deck[card_index + 1];
        Card open_card_3 = card_deck[card_index + 2];
        Card open_card_4 = card_deck[card_index + 3];
        Card hidden_card = card_deck[card_index + 4];

        
        // 사용자 현황 안내
        cout << "=======< High-Low Seven >=======" << endl;
        NewLine();

        cout << " Rest Card : " << 48 - card_index << endl;
        cout << " Your Chips : " << user_chips << endl;
        NewLine();

        // 카드 출력
        cout << "=== Open Card ===" << endl;
        NewLine();

        PrintCard(open_card_1);
        PrintCard(open_card_2);
        PrintCard(open_card_3);
        PrintCard(open_card_4);
        NewLine();
        
        cout << "=== Hidden Card ===" << endl;
        NewLine();
        cout << " [ ? ] " << endl;
        NewLine();

        
        Betting(hidden_card, &user_chips); // 베팅
        
        card_index++;
    }
}


void CardSet(Card* card_deck)
{
    int i, j;
    int first, second;


    // 카드 생성
    for (i = 0; i < 52; i++){
        switch (i / 13){
            case 0: card_deck[i].card_shape = SHAPE_SPADE;      break;
            case 1: card_deck[i].card_shape = SHAPE_DIAMOND;    break;
            case 2: card_deck[i].card_shape = SHAPE_HEART;      break;
            case 3: card_deck[i].card_shape = SHAPE_CLOVER;     break;
        }

        card_deck[i].card_number = i % 13 + 1;
    }       


    // 카드 셔플
    srand(time(NULL));

    for (j = 0; j < 100; j++){
        first = rand() % 52;
        second = rand() % 52;

        SwapCard(card_deck[first], card_deck[second]);
    }
}


void SwapCard(Card& first_card, Card& second_card)
{
    Card temp = first_card;
    first_card = second_card;
    second_card = temp;
}


void PrintCard(Card card)
{
    cout << " [";
    cout << card.card_shape;
    cout << " ";

    switch (card.card_number){
        case 1: cout << 'A';    break;
        case 11: cout << 'J';   break;
        case 12: cout << 'Q';   break;
        case 13: cout << 'K';   break;

        default : cout << card.card_number; break;
    }

    cout << "] ";
    NewLine();
}


void Betting(Card hidden_card, int* user_chips)
{
    int chips;
    int result;
    int allocation;
    char choice[2];    

    while (1){       
        NewLine();
        cout << "1.High  2.Low  3.Seven" << endl;
                
        scanf("%s", choice); // 베팅 대상 입력
        

        // 배팅에 따른 배당
        switch (choice[0]){
            case '1': allocation = (hidden_card.card_number > 7) ? 2 : -1;       break;
            case '2': allocation = (hidden_card.card_number < 7) ? 2 : -1;       break;
            case '3': allocation = (hidden_card.card_number == 7) ? 13 : -1;     break;
            default : cout << "Error! Select Again"; break;
        }
        
        // 배팅 대상 예외 처리
        if (choice[0] == '1' || choice[0] == '2' || choice[0] == '3' ) break;
    }
    

    /* 예외 처리가 안 된 코딩
    NewLine();
    cout << "1.High  2.Low  3.Seven" << endl;

    // 하이 or 로우 or 세븐 선택
    switch (getch()){
        case '1': allocation = (hidden_card.card_number > 7) ? 2 : -1;       break;
        case '2': allocation = (hidden_card.card_number > 7) ? 2 : -1;       break;
        case '3': allocation = (hidden_card.card_number == 7) ? 13 : -1;     break;        
    } 
    */
    

    // 베팅 입력
    while (1){        
        cout << "Bet your chips (100 ~ ";
        cout << *user_chips;;
        cout << "): ";

        cin >> chips;

        // 배팅 한도 처리
        if (chips > 100 || chips <= *user_chips) break;
    }


    // 히든 카드 오픈
    cout << endl;
    PrintCard(hidden_card);
    cout << endl;


    // 사용자 칩 증가 또는 차감
    result = chips * allocation;
    *user_chips += result;
    
    
    // 결과 안내
    cout << result;
    cout << " chips ";
    cout << (result > 0 ? "is just Y.O.U.R.S!" : "was blown away...");
    NewLine();


    // 보유 칩이 100개 이하면 파산 처리
    if (*user_chips < 100){
        cout << "You were broke...";
        exit(0);
    }

    system("pause");
}


void NewLine()
{
    cout << endl;
}
