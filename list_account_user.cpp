#include <iostream>
using namespace std;
#include "list_account_user.h"
#include <fstream>
#include <string>

void list_account_user::getlist_account(){
	ifstream f;
	f.open("./database/data_account_user.txt", ios_base::out);
	ifstream s;
	s.open("./database/data_account_sophim.txt", ios_base::out);
    while(!f.eof()){
    	account_user t;
    	t.getaccount(f);
    	t.getdata_sophim(s);
    	this->addLast(t);
	}
	f.close();
	s.close();
}

void list_account_user::outlist_account(){
	cout<<"Danh sach tai khoan:"<<endl;
	for(int i=0;i<this->length();i++){
		int j=i+1;
		cout<<j<<" - ";
		this->get(i).outaccount();
	} 
}

void list_account_user::login(account_user &a){
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
	system("pause");
	system("cls");
}

int list_account_user::checklogin(string id, string pwd, account_user &a){
	int i;
    account_user t;
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

void list_account_user::signup(account_user &a){
	cout<<"---Dang ki!!---"<<endl;
	string new_ID, new_pwd, name;
	cout<<"Nhap ID: "; getline(cin, new_ID);
	if(new_ID.empty()){
		cout<<"ID khong hop le!"<<endl;
		this->signup(a);
		return;
	}
	for(int i=0; i<this->length();i++){
		if(this->get(i).checkid(new_ID)){
			cout<<"ID da ton tai. Hay nhap ID khac!!"<<endl;
			this->signup(a);
			return;
		}
	}
	cout<<"Nhap mat khau: "; getline(cin, new_pwd);
	cout<<"Nhap ten cua ban: "; getline(cin, name);
	a.setaccount(new_ID, new_pwd, name);
    this->addLast(a);
    this->update_list_account();
	cout<<"Dang ki thanh cong!"<<endl;
	system("pause");
	system("cls");
}

void list_account_user::update_sophim(int n, account_user a){
	ofstream l0;
	l0.open("./database/data_account_sophim.txt", ios_base::out);
	l0.close();
	fstream l1;
	l1.open("./database/data_account_sophim.txt");
	account_user b;
	for(int i=0; i<this->length();i++){
		b = this->get(i);
		if(b.checkid(a.getID())){
			if(i!=0) l1<<endl;
		    b.fix_sophim(n).save_update_sophim(l1);
		}
		else{
			if(i!=0) l1<<endl;
			b.save_update_sophim(l1);
		}
	}
	l1.close();
}

void list_account_user::chance_list_account(){
	cout<<"Ban muon?"<<endl;
	cout<<" - 1. Xem thong tin tai khoan."<<endl;
	cout<<" - 2. Xoa tai khoan nguoi dung."<<endl;
	cout<<" - 3. Them mot tai khoan moi."<<endl;
	cout<<" - 4. Thoat"<<endl;
	int i;
	cout<<"----> ";cin>>i;
	string e;
	getline(cin, e);
	switch (i){
		case 1:{
			cout<<endl<<"Nhan 1: Xem het danh sach"<<endl;
			cout<<"Nhan 2: Tra cuu theo ID"<<endl;
			int k;
			cout<<"--->";cin>>k;
			getline(cin, e);
			if(k==1){
				system("cls");
				this->outlist_account();
				system("pause");
			}
			else{
                account_user a;
                cout<<endl<<"Nhap ID muon xem: ";
	            getline(cin, e);
				this->find_account(e, a, k);
				a.outaccount();
				system("pause");
			}
			break;
		}
		case 2: this->remove_account(); break;
		case 3: this->add_account(); break;
		case 4:{
			system("pause");
			system("cls");
			return;
		}
	}
	system("cls");
	chance_list_account();
}

void list_account_user::find_account(string e, account_user &a, int &index){
	for(int j=0;j<this->length();j++){
		if(this->get(j).checkid(e)){
			a=this->get(j);
			index =j;
			return;
		}
	}
    cout<<"Khong tim thay tai khoan. Ban co tim lai khong?"<<endl;
	cout<<" - 1. Tiep tuc"<<endl;
	cout<<" - 2. Thoat"<<endl;
	int j; cout<<"---->"; cin>>j;
	if(j==1) find_account(e, a, index);
	else{
		system("cls");
		return;
	}
}

void list_account_user::remove_account(){
	system("cls");
	string s;
	account_user a;
    int index;
	cout<<"Nhap ID tai khoan muon xoa:"; getline(cin,s);
	this->find_account(s, a, index);
	a.outaccount();
	cout<<"Ban co chac muon xoa tai khoan nay khong?"<<endl;
	cout<<" - 1. Xoa tai khoan"<<endl;
	cout<<" - 2. Thoat"<<endl;
	int i;
	cout<<"----> "; cin>>i;
	if(i==1){
		this->removeAtIndex(index);
		this->update_list_account();
		cout<<"Xoa thanh cong!"<<endl;
		system("pause");
	}
}

void list_account_user::update_list_account(){
	ofstream f1;
	f1.open("./database/data_account_user.txt", ios_base::out);
	f1.close();
	fstream f2;
	f2.open("./database/data_account_user.txt");
	this->get(0).save_account(f2);
    for(int i=1; i<this->length();i++){
		f2<<endl;
		this->get(i).save_account(f2);
	}
	f2.close();
	account_user a;
	this->update_sophim(0,a);
}

void list_account_user::add_account(){
	system("cls");
	string new_ID, new_pwd, new_name;
	cout<<"Hay nhap thong tin tai khoan moi!"<<endl;
    this->add_ID(new_ID);
    cout<<" - Nhap mat khau: "; getline(cin,new_pwd);
	cout<<" - Nhap ho ten: "; getline(cin, new_name);
	account_user a;
	a.setaccount(new_ID, new_pwd, new_name);
	this->addLast(a);
	this->update_list_account();
	cout<<"Them tai khoan thanh cong!"<<endl;
	system("pause");
}

void list_account_user::add_ID(string &id){
    cout<<"Nhap ID: "; getline(cin,id);
	if(this->checkid(id)){
		cout<<"ID da ton tai. Hay nhap ID khac!"<<endl;
		this->add_ID(id);
	}
}

bool list_account_user::checkid(string id){
    for(int i=0; i<this->length();i++){
		if(this->get(i).checkid(id)) return true;
	}
	return false;
}