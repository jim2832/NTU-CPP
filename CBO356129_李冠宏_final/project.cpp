#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
記帳程式
主選單：
*/

class Accounting{
    private:
        int catagory[12][31][50];
        int price[12][31][50];
        int count[12][31];
        int month;
        int day;

    public:
        void start(){
            cout << "|-----------------------------------------------|" << endl
                << "|\t\t 歡迎使用記帳程式\t\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "|\t1:程式介紹\t\t2:開始記帳\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "| 3:查看2022年的支出狀況     4:查詢某一日的記帳 |" << endl
                << "|-----------------------------------------------|" << endl
                << "|\t\t輸入q即可退出程式\t\t|" << endl
                << "|-----------------------------------------------|" << endl;
        }

        int getMonth(){
            return month;
        }

        int getDay(){
            return day;
        }

        void getToday(){
            time_t now = time(0);
            tm *ltm = localtime(&now);
            month = 1 + ltm->tm_mon;
            day = ltm->tm_mday;
        }

        void show_catagory(){
            cout << "要記什麼類別呢？" << endl
                << "|-----------------------------------------------|" << endl
                << "|\t\t   所有類別\t\t\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "|    1:早餐    |    2:中餐    |    3:晚餐\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "|    4:飲料    |    5:交通    |   6:日常用品    |" << endl
                << "|-----------------------------------------------|" << endl
                << "|    7:娛樂    |    8:教育    |    9:其他\t|" << endl
                << "|-----------------------------------------------|" << endl;
        }

        //記帳時問說要記多少錢
        void ask_price(){
            cout << "請問花了多少錢呢？ ";
        }

        //設定某一天的類別
        void set_catagory(int &mon, int &da, int &cnt, int cat){
            catagory[mon][da][cnt] = cat;
        }

        //設定某一天的價錢
        void set_price(int &mon, int &da, int &cnt, int &pri){
            price[mon][da][cnt] = pri;
        }

        //某一天的記帳數量增加
        void count_increment(int &mon, int &da){
            count[mon][da]++;
        }

        //取得某一天的記帳數量
        int get_count(int &mon, int &da){
            return count[mon][da];
        }

};



int main(void){
    char input, input2, c_input;
    Accounting account;
    int zero = 0;

    //初始化
    for(int i=0; i<12; i++){
        for(int j=0; j<31; j++){
            for(int k=0; k<50; k++){
                account.set_catagory(i, j, k, zero);
                account.set_price(i, j, k, zero);
            }
        }
    }

    while(1){
        account.start();
        cout << "請輸入要使用的功能: ";
        cin >> input;

        cout << endl;
        cout << endl;

        switch(input){
            //程式介紹
            case '1':
                break;

            //開始記帳
            case '2':
                int m, d, c, p;// month, day, conut, price
                cout << "請問是要記今天還是其他天的帳呢？" << endl
                << "|-----------------------------------------------|" << endl
                << "|\t1: 今天\t\t|\t2: 其他天\t|" << endl
                << "|-----------------------------------------------|" << endl;
                
                cout << "您的選擇: ";
                cin >> input2;
                //選擇今日記帳
                if(input2 == '1'){
                    cout << endl;
                    cout << endl;
                    account.getToday(); //取得今天日期
                    account.show_catagory();
                    cout << "您的選擇: ";
                    cin >> c_input;
                    switch(c_input){ //catagory input
                        case '1':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 1); //m月d日的第c筆資料為1類型(早餐)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;

                        case '2':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 2); //m月d日的第c筆資料為2類型(中餐)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;

                        case '3':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 3); //m月d日的第c筆資料為3類型(晚餐)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;

                        case '4':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 4); //m月d日的第c筆資料為4類型(飲料)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;

                        case '5':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 5); //m月d日的第c筆資料為5類型(交通)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;

                        case '6':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 6); //m月d日的第c筆資料為6類型(日常用品)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;

                        case '7':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 7); //m月d日的第c筆資料為7類型(娛樂)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;

                        case '8':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 8); //m月d日的第c筆資料為8類型(教育)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;

                        case '9':
                            account.ask_price();
                            cin >> p; //price input

                            m = account.getMonth();
                            d = account.getDay();
                            account.count_increment(m, d);
                            c = account.get_count(m, d);        

                            account.set_catagory(m, d, c, 9); //m月d日的第c筆資料為9類型(其他)
                            account.set_price(m, d, c, p); //m月d日的第c筆資料為p元
                            cout << "記帳成功！" << endl;
                            break;
                        
                        default:
                            cout << "請輸入有效指令！" << endl;
                            break;
                    }
                }
                //選擇其他日記帳
                else if(input2 == '2'){
                    continue;
                }
                else{
                    cout << "請輸入有效指令！" << endl;
                    break;
                }

                break;

            //查看2022年的支出狀況
            case '3':
                break;

            //查詢某一日的記帳
            case '4':
                break;

            //退出
            case 'q':
                cout << "感謝您使用此程式！" << endl;
                return 0;
            
            default:
                cout << "請輸入有效指令！" << endl;
                break;
            }
            cout << "請按Enter鍵繼續..." << endl;
            getchar();
            fgetc(stdin);
            system("clear");
        }

    return 0;
}