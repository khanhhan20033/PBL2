#include <iostream>
using namespace std;
#include "account_user.h"
#include <string>
#include <fstream>

char xep_loai_acc(int n){
	if(n>=30) return 'A';
	else if (n>=20) return 'B';
	else if (n>=10) return 'C';
	else return 'D';
}

void account_user::getdata_sophim(ifstream &f){
	string e;
	getline(f, e, '-');
	f>>this->sophimdaxem;
	this->loai_khach_hang = xep_loai_acc(this->sophimdaxem);
}

void account_user::outaccount(){
	this->out_account();
	cout<< "So phim da xem: "<< this->sophimdaxem<< endl;
	cout<< "Loai khach hang: "<< this->loai_khach_hang<<endl;
}

void account_user::outaccount_ticket(){
	cout<< "ID: "<<this->get_ID()<<endl;
	cout<< "Ten khach hang: "<< this->get_name()<<endl;
	cout<< "Loai khach hang: "<< this->loai_khach_hang<<endl;
}

string account_user::getID(){
	return this->get_ID();
}

void account_user::setaccount(string ID, string pwd, string name){
	this->set_account(ID, pwd, name);
	this->sophimdaxem=0;
	this->loai_khach_hang='D';
}


account_user account_user::fix_sophim(int n){
	this->sophimdaxem=this->sophimdaxem+n;
	return *this;
}

void account_user::save_update_sophim(fstream &f){
	f<<this->getID()<<"-"<<this->sophimdaxem;
}
