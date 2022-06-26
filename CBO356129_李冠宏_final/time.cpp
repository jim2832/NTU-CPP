#include <iostream>
#include <ctime>
using namespace std;
 
int main( )
{
// 基於當前系統的當前日期/時間
time_t now = time(0);
 
   cout << "1970 到目前經過秒數:" << now << endl;
 
   tm *ltm = localtime(&now);
 
   // 輸出 tm 結構的各個組成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;
   cout << "月: "<< 1 + ltm->tm_mon<< endl;
   cout << "日: "<<  ltm->tm_mday << endl;
   cout << "時間: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}