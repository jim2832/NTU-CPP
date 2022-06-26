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
        }

        //destructor
        ~eCash(){}

        void login(){
            string input_ID;

            cout << "eCash: 請輸入您的帳號: ";
            cin >> input_ID;
            if(input_ID == ID){
                cout << "eCash: 帳號開啟完成!" << endl;
            }
            else{
                cout << "帳號不存在, 第一次使用!" << endl;
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

        int GetMoney(){
            return money;
        }

        string getID(){
            return ID;
        }

    private:
        string ID;
        int money;
        FILE *file;
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