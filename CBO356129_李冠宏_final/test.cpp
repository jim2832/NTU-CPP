#include <iostream>

using namespace std;

class eCash {
    public:
        eCash() {
            Money = 0;
            file = fopen("test1.txt", "r");
            fscanf(file, "%d", &Money);
            fclose(file);
            ID = 123;        
        }

    int login() {
        int ID1 = 0;
        cout << "請輸入帳號登入:";
        cin >> ID1;
        if( ID1 == ID ) {
            cout << "Login Success!\n";
            return 0;
        }
        else {
            cout << "Login Error!\n";
            return 1;
        }
    }
    int logout() {
        cout << "Thanks, Bye Bye.\n";
        return 1;
    }
    void save( int Money1 ) {
        file = fopen("test1.txt", "w+");
        fscanf(file, "%d", &Money);
        Money = Money + Money1;
        cout << "您的餘額還有" << Money << "元\n";
        fprintf(file,"%d", Money);
        fclose(file);
    }
    void consume( int Money1 ) {
        if( Money >= Money1 ) {
        file = fopen("test1.txt", "w+");
        fscanf(file, "%d", &Money);
            Money = Money - Money1;
            cout << "您的餘額還有" << Money << "元\n";
        fprintf(file, "%d", Money);
        fclose(file);
        }
        else {
            cout << "您的餘額不足喔!只有" << Money << "元\n";
        }
    }
    void query() {
        file = fopen("test1.txt", "r");
        fscanf(file,"%d", &Money);
        cout << "您的餘額還有" << Money << "元\n";
        fclose(file);
    }

    private:
        int Money;
        int ID;
        FILE *file;
};

int main() {
    int Money1 = 0;
    char input = ' ';
    eCash ecash;
   
    if( ecash.login() == 0 ) {
   
    do {
        cout << "===============\n";
        cout << "輸入's': 儲值\n";
        cout << "輸入'c': 消費\n";
        cout << "輸入'q': 查詢餘額\n";
        cout << "輸入'e': 離開\n";
        cout << "===============\n";
        cout << "請輸入您的選擇:";
        cin >> input;
        switch( input ) {
            case 's':
                cout << "請輸入儲值金額:";
                cin >> Money1;
                ecash.save(Money1);
                break;
            case 'c':
                cout << "請輸入您的消費金額:";
                cin >> Money1;
                ecash.consume(Money1);
                break;
            case 'q':
                ecash.query();
                break;
            case 'e':
                ecash.logout();
                break;
        }
    } while( input != 'e' );
}
return 0;
}