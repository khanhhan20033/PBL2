#include <iostream>
using namespace std;
#include "../management/list_film.cpp"
#include "../management/list_account_user.cpp"
#include "../management/ticket.cpp"
#include "Menu_home.cpp"
#include <fstream>
#define Max 120

void Home_user(){
	account_user a;
	list_account_user la;
	la.getlist_account();
	int i, n;
	Menu_signup(i);
	switch (i){
		case 1: {
			system("cls");
			la.signup(a); 
			break;
		}
		case 2: la.login(a); break;
		case 3: {
			system("cls");
			return;
		}
    }
// system("cls");
//	a1.outlist_account();
    film f;
    int so_ve=Max;
    int x[so_ve], y[so_ve];
    loop:;
	list_film lf;
	lf.getlist_film();
	lf.booking(f,so_ve, x, y, n);
	ticket t;
	t.setticket(a, f,so_ve, x, y);
	t.outticket();
	int k;
	Menu_confirm(k);
	switch (k){
		case 1:
		   	lf.updatedata_sheet(n, f);
	        la.update_sophim(so_ve,a); 
	        t.savedata();
	        cout<<"Dat ve thanh cong! Cam on ban!"<<endl;
			system("pause");
			system("cls");
	        goto loop;
	        break;
	    case 2: 
		    goto loop; break;
		case 3:
			Home_user(); break;
	}
}
