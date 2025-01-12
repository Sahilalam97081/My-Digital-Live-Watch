#include<iostream>

#include<windows.h>

#include<ctime>

using namespace std;
void week(int w);
void display(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void drawBorder(){
    HANDLE he1=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(he1, FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_BLUE);
    
    for(int i=0;i<1;i++){
        display(40,i);
        cout<<"Submitted To:"<<endl;
}
    for(int i=0;i<1;i++){
        cout<<" Submitted By:"<<endl;
        cout<<"Name:Sahil Alam"<<endl;
        cout<<"Branch:CSE(AI&ML)"<<endl;
        cout<<"Sem: 3rd"<<endl;
        cout<<"Roll no:2339336"<<endl;
        cout<<"*SM*SM*SM*SM*SM*SM*SM*SM"<<endl;
    }
    for(int i=0;i<1;i++){
        display(40,i);
        cout<<"Submitted To:"<<endl;
}
    for(int i=0;i<1;i++){
        display(35,i);
        cout<<"DIGITAL Live WATCH (by sahil alam)"<<endl;
    
    } 
    for(int i=50;i<58;i++){
        display(20,i);
        cout<<"*";

        display(20,i);
        cout<<"SM";
    
    }
    

    for(int i=35;i<51;i++){
        display(i,8);
        cout<<"*Sahil";
    
        display(i,17);
        cout<<"*Alam";
    }
    for(int i=9;i<17;i++){
        display(35,i);
        cout<<"|";
        display(50,i);
        cout<<"|";
    }
} 
void printFormattedDate(int y,int m,int d){
    HANDLE he1=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(he1,FOREGROUND_GREEN);
    cout<< d <<"/"<< m <<"/"<< y;

}
void printFormattedTime(int h,int mi,int s){

    system("color 3A");
    HANDLE he1=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(he1,FOREGROUND_GREEN);
    cout<< h <<":"<< mi <<":"<< s;
}

void digital_watch(int y,int mi, int m, int s, int h, int we,int d){
    while(true){
        time_t t=time(NULL);
        struct tm tm=*localtime(&t);
        s=tm.tm_sec;
        mi=tm.tm_min;
        h=tm.tm_hour;
        d=tm.tm_mday;
        
        m=tm.tm_mon+1;
        y=tm.tm_year+1900;
        we=tm.tm_wday;
        system("cls");
        drawBorder();
        display(38,10);
        printFormattedDate(y,m,d);
        //print time
        display(38,12);
       printFormattedTime(h,mi,s);
        //print day of the week
        display(39,14);
        week(we);
        Sleep(1000);


    }
}
void week(int w){
    switch(w){
        case 0:
        cout<<"Sunday";
        break;
        case1:
        cout<<"Monday";
        break;
        case 2:
        cout<<"Tuesday";
        break;
        case 3:
        cout<<"Wednesday";
        break;
        case 4:
        cout<<"Thursday";
        break;
        case 5:
        cout<<"Friday";
        break;
        case 6:
        cout<<"Saturday";
        break;

    }
}
int main(){
    system("color 3A");
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    drawBorder();
    digital_watch(tm.tm_year+1900,tm.tm_min,tm.tm_mon+1,tm.tm_sec,tm.tm_mday,tm.tm_hour,tm.tm_wday);
    

    return 0;
}
