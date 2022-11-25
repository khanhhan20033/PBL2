#include <iostream>
using namespace std;
#include "../management/list_account_host.cpp"

void host_chance(){
    int i;
    Menu_host_chance(i);
    switch (i){
        case 1: break;
        case 2: {
            list_film lf;
            lf.getlist_film();
            lf.chance_list_film();
            break;
        }
        case 3: {
            list_account_user la;
            la.getlist_account();
            la.chance_list_account();
            break;
        }
        case 4: {
            list_film lf;
            lf.getlist_film();
            lf.check_sheet();
            break;
        }
        case 5: {
            system("cls");
            return;
        }
    }
    host_chance();
}

void Home_host(){
    account_host a;
	list_account_host la;
	la.getlist_account();
	int l, n;
    Menu_host_login(l);
    switch (l){
        case 1: la.login(a); break;
        case 2: {
            system("cls");
            return;
        }
    }
    host_chance();
    return;
}