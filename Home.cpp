#include <iostream>
using namespace std;
#include <fstream>
#include "Home_user.cpp"
#include "Home_host.cpp"

void Home(){
    int i;
    Menu_infor();
    Menu_home(i);
    system("cls");
    switch (i){
        case 1: Home_user(); break;
        case 2: Home_host(); break;
        case 3: exit(0);
    }
    Home();
}