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
        int month;
        int day;

    public:
        void start(){
            cout << "|-----------------------------------------------|" << endl
                << "|\t\t 歡迎使用記帳程式\t\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "| 1:程式介紹           | 2:開始記帳\t\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "| 3:列出所有記帳       | 4:今年的記帳分析\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "| 5:查詢某一個月的記帳 | 6:查詢某一天的記帳\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "|\t\t輸入q即可退出程式\t\t|" << endl
                << "|-----------------------------------------------|" << endl;
        }

        void set_month(int &mo){
            month = mo;
        }

        void set_day(int &da){
            day = da;
        }

        int getMonth(){
            return month;
        }

        int getDay(){
            return day;
        }

        void show_catagory(){
            cout << "要記什麼類別呢？" << endl
                << "|-----------------------------------------------|" << endl
                << "|\t\t   所有類別\t\t\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "|    1:早餐    |    2:中餐    |    3:晚餐\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "|    4:飲料    |    5:交通    |    6:生活\t|" << endl
                << "|-----------------------------------------------|" << endl
                << "|    7:娛樂    |    8:教育    |    9:其他\t|" << endl
                << "|-----------------------------------------------|" << endl;
        }

        //記帳時問說要記多少錢
        void ask_price(){
            cout << "請問花了多少錢呢？ ";
        }

        void date_input1(int &mon, int &da){
            cout << "幾月: ";
            cin >> mon;
            if(mon < 1 || mon > 12){
                cout << "請輸入有效月份！" << endl;
                cout << endl;
                return;
            }

            cout << "幾號: ";
            cin >> da;
            //有31天的月份
            if(mon == 1 || mon ==3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12){
                if(da < 1 || da > 31){
                    cout << "請輸入有效日期！" << endl;
                    cout << endl;
                    return;
                }
            }
            //有30天的月份
            if(mon == 4 || mon ==6 || mon == 9 || mon == 11){
                if(da < 1 || da > 30){
                    cout << "請輸入有效日期！" << endl;
                    cout << endl;
                    return;
                }
            }
            //2月只有28天
            if(mon == 2){
                if(da < 1 || da > 28){
                    cout << "請輸入有效日期！" << endl;
                    cout << endl;
                    return;
                }
            }
        }

        void date_input2(int &mon){
            cin >> mon;
            if(mon < 1 || mon > 12){
                cout << "請輸入有效月份！" << endl;
                cout << endl;
                return;
            }
        }
};



int main(void){
    char input, c_input;
    Accounting account;
    int zero = 0;
    string catagory[12][31][50];
    int price[12][31][50];
    int count[12][31];

    //初始化
    for(int i=0; i<12; i++){
        for(int j=0; j<31; j++){
            for(int k=0; k<50; k++){
                catagory[i][j][k] = "";
                price[i][j][k] = 0;
            }
        }
    }

    while(1){
        int m, d, c, p; //month, day, count, price
        int month_sum = 0; //當月總花費
        int day_sum = 0; //當日總花費

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
                cout << "請問要記哪天的帳呢？ " << endl;

                cout << "幾月: ";
                cin >> m;
                if(m < 1 || m > 12){
                    cout << "請輸入有效月份！" << endl;
                    cout << endl;
                    break;
                }

                cout << "幾號: ";
                cin >> d;
                //有31天的月份
                if(m == 1 || m ==3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
                    if(d < 1 || d > 31){
                        cout << "請輸入有效日期！" << endl;
                        cout << endl;
                        break;
                    }
                }
                //有30天的月份
                if(m == 4 || m ==6 || m == 9 || m == 11){
                    if(d < 1 || d > 30){
                        cout << "請輸入有效日期！" << endl;
                        cout << endl;
                        break;
                    }
                }
                //2月只有28天
                if(m == 2){
                    if(d < 1 || d > 28){
                        cout << "請輸入有效日期！" << endl;
                        cout << endl;
                        break;
                    }
                }

                cout << endl;
                cout << endl;
                account.show_catagory();
                cout << "您的選擇: ";
                cin >> c_input;

                switch(c_input){ //catagory input
                    case '1':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "早餐";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;

                    case '2':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "中餐";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;

                    case '3':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "晚餐";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;

                    case '4':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "飲料";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;

                    case '5':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "交通";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;

                    case '6':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "生活";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;

                    case '7':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "娛樂";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;

                    case '8':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "教育";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;

                    case '9':
                        account.ask_price();
                        cin >> p; //price input

                        count[m][d]++; //m月d日的記帳數量增加
                        c = count[m][d];

                        catagory[m][d][c] = "其他";
                        price[m][d][c] = p; //m月d日的第c筆資料為p元
                        cout << "記帳成功！" << endl;
                        cout << endl;
                        break;
                    
                    default:
                        cout << "請輸入有效指令！" << endl;
                        break;
                }
                break;

            //查看2022年的支出狀況
            case '3':
                //列出所有的記帳
                cout << "2022年的記帳紀錄:" << endl;
                cout << endl;
                cout << " 日期\t\t類別\t\t花費" << endl
                    << "------------------------------------" << endl;
                for(int i=0; i<12; i++){
                    for(int j=0; j<31; j++){
                        for(int k=0; k<50; k++){
                            if(price[i][j][k] != 0){
                                cout << i << "月" << j << "日" << "\t\t"
                                << catagory[i][j][k] << "\t\t" << price[i][j][k] << endl;
                            }
                        }
                    }
                }
                cout << "------------------------------------" << endl;
                cout << endl;
                break;

            //今年的記帳分析
            case '4':
                break;

            //查詢某一個月的記帳
            case '5':
                cout << "請問要查詢幾月呢？(輸入月份數字) ";
                cin >> m;
                if(m < 1 || m > 12){
                    cout << "請輸入有效月份！" << endl;
                    cout << endl;
                    break;
                }
                cout << endl;
                cout << "2022年" << m << "月" << "的記帳紀錄為:" << endl;
                cout << endl;
                cout << " 日期\t\t類別\t\t花費" << endl
                    << "------------------------------------" << endl;
                for(int i=0; i<31; i++){
                    for(int j=0; j<50; j++){
                        if(price[m][i][j] != 0){
                            cout << m << "月" << i << "日" << "\t\t"
                            << catagory[m][i][j] << "\t\t" << price[m][i][j] << endl;
                            month_sum += price[m][i][j];
                        }
                    }
                }
                cout << "------------------------------------" << endl;
                cout << m << "月總共花了" << month_sum << "元" << endl;
                cout << endl;
                break;
                

            //查詢某一天的記帳
            case '6':
                cout << "請問要查詢哪一天呢？" << endl;

                cout << "幾月: ";
                cin >> m;
                if(m < 1 || m > 12){
                    cout << "請輸入有效月份！" << endl;
                    cout << endl;
                    break;
                }

                cout << "幾號: ";
                cin >> d;
                //有31天的月份
                if(m == 1 || m ==3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
                    if(d < 1 || d > 31){
                        cout << "請輸入有效日期！" << endl;
                        cout << endl;
                        break;
                    }
                }
                //有30天的月份
                if(m == 4 || m ==6 || m == 9 || m == 11){
                    if(d < 1 || d > 30){
                        cout << "請輸入有效日期！" << endl;
                        cout << endl;
                        break;
                    }
                }
                //2月只有28天
                if(m == 2){
                    if(d < 1 || d > 28){
                        cout << "請輸入有效日期！" << endl;
                        cout << endl;
                        break;
                    }
                }

                cout << endl;
                cout << "2022年" << m << "月" <<  d << "日" << "的記帳紀錄為:" << endl;
                cout << endl;
                cout << " 日期\t\t類別\t\t花費" << endl
                    << "------------------------------------" << endl;
                for(int i=0; i<50; i++){
                    if(price[m][d][i] != 0){
                        cout << m << "月" << d << "日" << "\t\t"
                            << catagory[m][d][i] << "\t\t" << price[m][d][i] << endl;
                        day_sum += price[m][d][i];
                    }
                }
                cout << "------------------------------------" << endl;
                cout << m << "月" << d << "日總共花了" << day_sum << "元" << endl; 
                cout << endl;
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