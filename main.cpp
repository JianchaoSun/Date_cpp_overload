#include <iostream>
using namespace std;

class Date {
    int d,m,y;
    string months[13]={"null","January", "February", "March", "April", "May",
                       "June", "July", "August", "September", "October", "November", "December"};

public:

    friend ostream& operator<<(ostream& os, const Date& dt);
    friend istream&operator>>(istream& is, Date& dt);
    void readInput(){
        while(!isValid()) {
            cout << "enter a date";
            cin >> m;
            cin.get();
            cin >> d;
            cin.get();
            cin >> y;
        }
    }
    Date operator++(){
        cout<<"updated date: "<<endl;
        if(m==1||m==3||m==5||m==7||m==8||m==10){
            if(d ==31){
                d=1;
                m++;
            }
            else{
                d++;
            }
        }
        else if(m==12){
            if(d ==31){
                d=1;
                m=1;
                y++;
            }else{
                d++;
            }
        }
        else if(m==2){
            if(d ==28){
                d=1;
                m++;
            }
            else{
                d++;
            }
        }
        else{
            if(d ==30){
                d=1;
                m++;
            }
            else{
                d++;
            }
        }
        return *this;
    }

    Date operator++(int ){
        cout<<"updated date: "<<endl;
        if(m==1||m==3||m==5||m==7||m==8||m==10){
            if(d ==31){
                d=1;
                m++;
            }
            else{
                d++;
            }
        }
        else if(m==12){
            if(d ==31){
                d=1;
                m=1;
                y++;
            }else{
                d++;
            }
        }
        else if(m==2){
            if(d ==28){
                d=1;
                m++;
            }
            else{
                d++;
            }
        }
        else{
            if(d ==30){
                d=1;
                m++;
            }
            else{
                d++;
            }
        }
        return *this;
    }

    Date operator--(){
        //2,4,6,8,9,11

        cout<<"lower date: "<<endl;
        if(m==2||m==4||m==6||m==8||m==9||m==11){
            if(d ==1){
                d=31;
                m--;
            }
            else{
                d--;
            }
        }
        else if(m==1){
            if(d ==1){
                d=31;
                m=12;
                y--;
            }else{
                d--;
            }
        }
        else if(m==3){
            if(d ==1){
                d=28;
                m--;
            }
            else{
                d--;
            }
        }
        else{
            if(d ==1){
                d=30;
                m--;
            }
            else{
                d--;
            }
        }
        return *this;

    }

    Date operator--(int){
        //2,4,6,8,9,11

        cout<<"lower date: "<<endl;
        if(m==2||m==4||m==6||m==8||m==9||m==11){
            if(d ==1){
                d=31;
                m--;
            }
            else{
                d--;
            }
        }
        else if(m==1){
            if(d ==1){
                d=31;
                m=12;
                y--;
            }else{
                d--;
            }
        }
        else if(m==3){
            if(d ==1){
                d=28;
                m--;
            }
            else{
                d--;
            }
        }
        else{
            if(d ==1){
                d=30;
                m--;
            }
            else{
                d--;
            }
        }
        return *this;

    }

    int operator-(const Date& t) {
        int day1=0, day2 =0;

        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            day1+=m*31;
        } else if (m == 2) {
            day1+=m*28;

        } else {
            day1 +=m*30;
        }

        if (t.m == 1 || t.m == 3 || t.m == 5 || t.m == 7 || t.m == 8 || t.m == 10 || t.m == 12) {
            day2+=t.m*31;
        } else if (t.m == 2) {
            day2+=t.m*28;

        } else {
            day2 +=t.m*30;
        }

        day1 +=d;
        day1 +=365*y;
        day2 +=t.d;
        day2 +=365*t.y;

        return day2 -day1;
    }




    bool isValid(){
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        return (d<=31&&m<=12&&d>0&&m>0);
        }
        else if(m==2){
            return (d<=28&&m<=12&&d>0&&m>0);
        }
        else
            return (d<=30&&m<=12&&d>0&&m>0);
    }
};
ostream& operator<<(ostream& os, const Date& dt){
    os<<dt.months[dt.m]<<" "<<dt.d<<", "<<dt.y<<endl;
    return os;
}

istream&operator>>(istream& is, Date& dt){
    while(!dt.isValid()) {
        cout << "enter a date";
        cin >> dt.m;
        cin.get();
        cin >> dt.d;
        cin.get();
        cin >> dt.y;
    }
    return is;
}

int main() {
    Date d;
    cin>>d;
    cout<<d;
    d++;
    cout<<d;
    d--;
    cout<<d;

    Date d2;
    cin>>d2;
    cout<<d2;

    int x = d-d2;
    cout<<"After subtraction: "<<x<<endl;


}