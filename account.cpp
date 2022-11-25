#include <iostream>
using namespace std;
#include "account.h"
#include <string>
#include <fstream>

string account::get_ID(){
    return this->ID_acc;
}
string account::get_pwd(){
    return this->pwd_acc;
}
string account::get_name(){
    return this->name_acc;
}

void account::getaccount(ifstream &f){
	getline(f, this->ID_acc,'-');
	getline(f, this->pwd_acc,'-');
	getline(f, this->name_acc);
}

void account::out_account(){
	cout<< "ID: "<<this->ID_acc<<endl;
	cout<< "Ten nguoi dung: "<< this->name_acc<<endl;
}

bool account::checkid(string id){
	if(this->ID_acc==id) return true;
	else return false;
}

bool account::checkpwd(string pwd){
	if(this->pwd_acc==pwd) return true;
	else return false;
}

void account::set_account(string ID, string pwd, string name){
    this->ID_acc=ID;
	this->pwd_acc=pwd;
	this->name_acc=name;
}

void account::save_account(fstream &f){
	f<<this->ID_acc<<"-"<<this->pwd_acc<<"-"<<this->name_acc;
}