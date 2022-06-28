#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

/*
記帳程式
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
};



int main(void){
    char input, c_input;
    Accounting account;
    string catagory[13][32][50]; //紀錄某月某日某一筆的種類
    int price[13][32][50]; //紀錄某月某日某一筆的花費
    int count[13][32]; //紀錄某月某日有幾筆記帳

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
        int total = 0; //總花費
        int sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9; //各類總和
        double percent1 = 0, percent2 = 0, percent3 = 0,
                percent4 = 0, percent5 = 0, percent6 = 0,
                percent7 = 0, percent8 = 0, percent9 = 0; //各類佔比

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
                for(int i=1; i<=12; i++){
                    for(int j=1; j<=31; j++){
                        for(int k=0; k<=50; k++){
                            if(price[i][j][k] != 0){
                                if(i>9){
                                    cout << i << "月" << j << "日" << "\t"
                                    << catagory[i][j][k] << "\t\t" << price[i][j][k] << endl;
                                }
                                else{
                                    cout << i << "月" << j << "日" << "\t\t"
                                    << catagory[i][j][k] << "\t\t" << price[i][j][k] << endl;
                                }
                            }
                        }
                    }
                }
                cout << "------------------------------------" << endl;
                cout << endl;
                break;

            //今年的記帳分析
            case '4':
                cout << "--------------------" << endl;
                cout << "| 2022年的記帳分析 |" << endl;
                cout << "--------------------" << endl;
                cout << endl;

                //每月花費
                cout << "每月花費:" << endl;
                cout << endl;
                cout << "月份" << "\t" << "花費" << endl
                    << "------------" << endl;
                for(int i=1; i<=12; i++){
                    month_sum = 0;
                    for(int j=1; j<=31; j++){
                        for(int k=0; k<50; k++){
                            month_sum += price[i][j][k];
                            total += price[i][j][k];
                        }
                    }
                    cout << i << "月" << "\t" << month_sum << endl;
                }
                cout << "------------" << endl;
                cout << "-> 總花費:" << total << endl;
                cout << endl;
                cout << endl;

                //每類型佔比
                for(int i=1; i<=12; i++){
                    for(int j=1; j<=31; j++){
                        for(int k=0; k<50; k++){
                            if(catagory[i][j][k] == "早餐"){
                                sum1 += price[i][j][k];
                            }
                            if(catagory[i][j][k] == "中餐"){
                                sum2 += price[i][j][k];
                            }
                            if(catagory[i][j][k] == "晚餐"){
                                sum3 += price[i][j][k];
                            }
                            if(catagory[i][j][k] == "飲料"){
                                sum4 += price[i][j][k];
                            }
                            if(catagory[i][j][k] == "交通"){
                                sum5 += price[i][j][k];
                            }
                            if(catagory[i][j][k] == "生活"){
                                sum6 += price[i][j][k];
                            }
                            if(catagory[i][j][k] == "娛樂"){
                                sum7 += price[i][j][k];
                            }
                            if(catagory[i][j][k] == "教育"){
                                sum8 += price[i][j][k];
                            }
                            if(catagory[i][j][k] == "其他"){
                                sum9 += price[i][j][k];
                            }
                        }
                    }
                }
                //計算比例
                percent1 = (double)sum1 / total *100;
                percent2 = (double)sum2 / total *100;
                percent3 = (double)sum3 / total *100;
                percent4 = (double)sum4 / total *100;
                percent5 = (double)sum5 / total *100;
                percent6 = (double)sum6 / total *100;
                percent7 = (double)sum7 / total *100;
                percent8 = (double)sum8 / total *100;
                percent9 = (double)sum9 / total *100;

                //四捨五入
                if(percent1 - floor(percent1) >= 0.5){
                    percent1 = floor(percent1) + 1;
                }
                else{
                    percent1 = floor(percent1);
                }
                if(percent2 - floor(percent2) >= 0.5){
                    percent2 = floor(percent2) + 1;
                }
                else{
                    percent2 = floor(percent2);
                }
                if(percent3 - floor(percent3) >= 0.5){
                    percent3 = floor(percent3) + 1;
                }
                else{
                    percent3 = floor(percent3);
                }
                if(percent4 - floor(percent4) >= 0.5){
                    percent4 = floor(percent4) + 1;
                }
                else{
                    percent4 = floor(percent4);
                }
                if(percent5 - floor(percent5) >= 0.5){
                    percent5 = floor(percent5) + 1;
                }
                else{
                    percent5 = floor(percent5);
                }
                if(percent6 - floor(percent6) >= 0.5){
                    percent6 = floor(percent6) + 1;
                }
                else{
                    percent6 = floor(percent6);
                }
                if(percent7 - floor(percent7) >= 0.5){
                    percent7 = floor(percent7) + 1;
                }
                else{
                    percent7 = floor(percent7);
                }
                if(percent8 - floor(percent8) >= 0.5){
                    percent8 = floor(percent8) + 1;
                }
                else{
                    percent8 = floor(percent8);
                }
                if(percent9 - floor(percent9) >= 0.5){
                    percent9 = floor(percent9) + 1;
                }
                else{
                    percent9 = floor(percent9);
                }

                cout << "各類型消費佔的比例:" << endl;
                cout << "---------------------------------------------------------" << endl;
                printf("|\t早餐: %d%%\t 中餐: %d%%\t 晚餐: %d%%\t|\n", (int)percent1, (int)percent2, (int)percent3);
                printf("|\t飲料: %d%%\t 交通: %d%%\t 生活: %d%%\t|\n", (int)percent4, (int)percent5, (int)percent6);
                printf("|\t娛樂: %d%%\t 教育: %d%%\t 其他: %d%%\t|\n", (int)percent7, (int)percent8, (int)percent9);
                cout << "---------------------------------------------------------" << endl;
                cout << endl;

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
                for(int i=1; i<=31; i++){
                    for(int j=1; j<=50; j++){
                        if(price[m][i][j] != 0){
                            if(m>9){
                                cout << m << "月" << i << "日" << "\t"
                                << catagory[m][i][j] << "\t\t" << price[m][i][j] << endl;
                                month_sum += price[m][i][j];
                            }
                            else{
                                cout << m << "月" << i << "日" << "\t\t"
                                << catagory[m][i][j] << "\t\t" << price[m][i][j] << endl;
                                month_sum += price[m][i][j];
                            }
                        }
                    }
                }
                cout << "------------------------------------" << endl;
                cout << "-> " << m << "月總共花了" << month_sum << "元" << endl;
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
                cout << endl;
                cout << "2022年" << m << "月" <<  d << "日" << "的記帳紀錄為:" << endl;
                cout << endl;
                cout << " 日期\t\t類別\t\t花費" << endl
                    << "------------------------------------" << endl;
                for(int i=1; i<=50; i++){
                    if(price[m][d][i] != 0){
                        if(m>9){
                            cout << m << "月" << d << "日" << "\t"
                                << catagory[m][d][i] << "\t\t" << price[m][d][i] << endl;
                            day_sum += price[m][d][i];
                        }
                        else{
                            cout << m << "月" << d << "日" << "\t\t"
                                << catagory[m][d][i] << "\t\t" << price[m][d][i] << endl;
                            day_sum += price[m][d][i];
                        }
                    }
                }
                cout << "------------------------------------" << endl;
                cout << "-> " << m << "月" << d << "日總共花了" << day_sum << "元" << endl; 
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