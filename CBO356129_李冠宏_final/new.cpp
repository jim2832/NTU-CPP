#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Data{
    char name[100];
    int money;
};

class eCash{
    public:
        //constructor
        eCash(){
            Money = 0;
        }

        void login(){

        }

        void logout(){

        }

        void store(int &m){
            Money += m;
        }

        void pay(int &m){
            Money -= m;
        }

        void display(){
            cout << "eCash: 您尚有" << Money << "元" << endl;
        }

        void setID(char input_ID[50]){
            ID = input_ID;
        }

        void setMoney(int m){
            Money = m;
        }

        string GetID(){
            return ID;
        }

        int GetMoney(){
            return Money;
        }

    private:
        string ID;
        int Money;
};

int main(void){
    char input, account_name[50]; //options and input ID
    int m; //money input
    eCash ecash; //make object
    struct Data person[50]; //結構陣列
    FILE *read;
    FILE *write;
    int number; //帳號數量
    int flag = 0; //紀錄有無找到已存在帳號
    int index;

    cout << "=== 歡迎使用eCash ===" << endl;
    cout << "eCash: 請輸入您的帳號: ";
    cin >> account_name;

    read = fopen("data.txt", "r");
    write = fopen("data.txt", "w");
    
    //read the file
    fscanf(read, "%d\n", &number);
    for(int i=1; i<=number; i++){
        fscanf(read, "%s\t%d\n", person[i].name, &person[i].money);
    }
    cout << number << endl << person[1].name << endl;
    fclose(read);

    //尋找是否有存在帳號
    for(int i=1; i<=number; i++){
        if(strcmp(person[i].name, account_name) == 0){
            flag = 1;
            index = i;
            break;
        }
    }

    if(flag == 1){
        cout << "eCash: 帳號開啟完成!" << endl << endl;
        ecash.setID(person[index].name);
        ecash.setMoney(person[index].money);
    }
    else{
        cout << "eCash: 帳號不存在, 第一次使用!" << endl << endl;
        number++;
        strcpy(person[number].name, account_name);
        person[number].money = 0;
    }

    while(1){
        cout << ecash.GetID() << "您好，請選擇項目:" << endl;
        cout << "s: 儲值" << endl;
        cout << "p: 消費" << endl;
        cout << "d: 顯示餘額" << endl;
        cout << "q: 離開" << endl;
        cout << ">";

        cin >> input;

        switch (input){

        //case s
        case 's':
            cout << "請輸入儲存金額:" << endl;
            cin >> m;
            if(m < 0){
                cout << "請輸入大於0的金額" << endl;
                m = 0;
                break;
            }
            ecash.store(m);
            cout << "eCash: 您存了" << m << "元" << endl;
            break;

        //case p
        case 'p':
            cout << "請輸入消費金額:" << endl;
            cin >> m;
            if(m < 0){
                cout << "eCash: 請輸入大於0的金額" << endl;
                m = 0;
                break;
            }
            if(ecash.GetMoney() -m < 0){
                cout << "eCash: 您的錢不夠" << endl;
                break;
            }
            ecash.pay(m);
            cout << "eCash: 您花了" << m << "元" << endl;
            break;

        //case d
        case 'd':
            ecash.display();
            break;

        //case q
        case 'q':
            cout << "eCash: 帳號登出, 已存檔!" << endl;
            cout << "謝謝,ByeBye!" << endl;
            return 0;
            break;
        
        default:
            cout << "請輸入有效的指令！" << endl;
            break;
        }
        cout << "請按Enter鍵繼續...";
        getchar();
        fgetc(stdin);
        system("clear");
    }

    return 0;
}