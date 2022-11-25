#include <iostream>
using namespace std;
#include "list_account_host.h"
#include <fstream>
#include <string>

void list_account_host::getlist_account(){
	ifstream f;
	f.open("./database/data_account_host.txt", ios_base::out);
    while(!f.eof()){
    	account_host t;
    	t.getaccount(f);
    	this->addLast(t);
	}
	f.close();
}

void list_account_host::outlist_account(){
	cout<<"Danh sach tai khoan:"<<endl;
	for(int i=0;i<this->length();i++){
		int j=i+1;
		cout<<j<<" - ";
		this->get(i).out_account();
	} 
}

void list_account_host::login(account_host &a){
	cout<<"Dang nhap!"<<endl;
	string id, pwd;
	cout<<"Nhap ID: "; getline(cin, id);
	cout<<"Nhap mat khau: "; getline(cin, pwd);
	int i;
	i = this->checklogin(id, pwd, a);
	if(i == 1){
		cout<< "ID khong ton tai. Hay dang nhap lai!"<<endl;
		this->login(a);
	}
	else if (i == 2){
		cout<< "Mat khau sai. Hay dang nhap lai!"<<endl;
		this->login(a);
	}
	else{
		cout<<"Dang nhap thanh cong!!"<<endl<<endl;
	}
}

int list_account_host::checklogin(string id, string pwd, account_host &a){
	int i;
    account_host t;
	for(i=0; i<this->length();i++){
		if(this->get(i).checkid(id)){
			t=this->get(i);
			i=this->length();
		}
	}
	if(i==this->length()) return 1;
	else{
		if(t.checkpwd(pwd)){
			a=t;
			return 3;
		}
		else return 2;
	}
}