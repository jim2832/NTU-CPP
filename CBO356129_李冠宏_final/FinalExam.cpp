#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class eCash{
    public:
        //constructor
        eCash(){
            money = 0;
            ID = "No name";
            read = fopen("Users.txt", "r");
            write = fopen("Users.txt", "w");
        }

        //destructor
        ~eCash(){}

        void login(){
            char input_ID[100]; //使用者輸入的帳號
            char read_ID[100]; //從Users.txt要讀入的帳號
            int read_money; //從Users.txt要讀入的錢

            cout << "eCash: 請輸入您的帳號: ";
            cin >> input_ID;


            while(!feof(read)){
                fscanf(read, "%s\t%d\n", read_ID, &read_money);//讀檔
                /*
                如果讀到的帳號和輸入的一樣，就顯示帳號開啟完成
                並且ID = read_ID; money = read_money
                */
                if(strcmp(input_ID, read_ID) == 0){
                    cout << "eCash: 帳號開啟完成!" << endl;
                    ID = read_ID;
                    money = read_money;
                    break;
                }
                /*
                若都沒有讀到一樣的，就顯示帳號不存在，第一次使用
                並且把input_ID和money = 0寫入Users.txt
                */
                else{
                    cout << "帳號不存在, 第一次使用!" << endl;
                    fprintf(write, "%s\t%d\n", input_ID, 0);
                    ID = input_ID;
                    money = 0;
                    break;
                }
            }
        }

        void logout(){

        }

        void store(int m){
            if(m < 0){
                cout << "請輸入大於0的金額" << endl;
                m = 0;
                return;
            }
            money += m;
            cout << "eCash: 您存了" << m << "元" << endl;
        }

        void pay(int m){
            if(m < 0){
                cout << "eCash: 請輸入大於0的金額" << endl;
                m = 0;
                return;
            }
            if(money - m >= 0){
                money -= m;
            }
            else{
                cout << "eCash: 您的錢不夠" << endl;
                return;
            }
        }

        void display(){
            cout << "eCash: 您尚有" << money << "元" << endl;
        }

        string getID(){
            return ID;
        }

        int GetMoney(){
            return money;
        }

    private:
        string ID;
        int money;
        FILE *read;
        FILE *write;
};

int main(void){
    char input;
    int m = 0;
    eCash ecash; //make object

    cout << "=== 歡迎使用eCash ===" << endl;
    ecash.login(); //login
    cout << endl;

    while(1){
        cout << ecash.getID() << "您好，請選擇項目:" << endl;
        cout << "s: 儲值" << endl;
        cout << "p: 消費" << endl;
        cout << "d: 顯示餘額" << endl;
        cout << "q: 離開" << endl;

        cin >> input;

        switch (input){

        //case s
        case 's':
            cout << "請輸入儲存金額:" << endl;
            cin >> m;
            ecash.store(m);
            break;

        //case p
        case 'p':
            cout << "請輸入消費金額:" << endl;
            cin >> m;
            ecash.pay(m);
            break;

        //case d
        case 'd':
            ecash.display();
            break;

        //case q
        case 'q':
            ecash.logout();
            cout << "帳號登出, 已存擋!" << endl;
            cout << "謝謝,ByeBye!" << endl;
            return 0;
            break;
        
        default:
            cout << "請輸入有效的指令！" << endl;
            break;
        }
        //存擋
        FILE *write;
        write = fopen("Users.txt", "w");


        cout << "請按Enter鍵繼續...";
        getchar();
        fgetc(stdin);
        system("clear");
    }

    return 0;
}