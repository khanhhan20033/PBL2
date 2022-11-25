#include <iostream>
#include "film.h"
#include <fstream>
#include <string>
using namespace std;

void film::getfilm(fstream &f){
	getline(f, this->ID_film, '-');
	getline(f, this->name_film, '-');
	getline(f, this->infor_film, '-');
	f>>this->start_time;
	f>>this->cost;
	string e;
	getline(f, e);
}

void fix_time(float x){
	int t;
	t=x;
	int p;
	p=(x-int(x))*60;
	string a = " AM";
	if(t>12){
		a = " PM";
        t=t-12;
	}
	cout<< t<<"h"<<p<<a;
}

void film::outfilm(){
	cout<<"ID phim: "<<this->ID_film<<endl;
	cout<<"Ten phim: "<<this->name_film<<endl;
    cout<<"Thong tin: "<<this->infor_film<<endl;
    cout<<"Gio chieu: "; fix_time(this->start_time); cout<<endl;
    cout<<"Gia: "<<this->cost<<endl;
}

void film::outfilm_ticket(){
	cout<<"Ten phim: "<<this->name_film<<endl;
	cout<<"Gio chieu: "; fix_time(this->start_time); cout<<endl;
}

int film::getcost(){
	return this->cost;
}

void film::outname_film(){
	cout<<this->name_film<<endl;
}

void film::getdata_sheet(fstream &f){
	string e;
	getline(f,e);
	for(int j=0;j<10;j++){
	    for(int i=0;i<12;i++){
	    	f>>this->data_sheet[j][i];
		}
		getline(f, e);
    }
}

bool film::checksheet(int x, int y){
	if(this->data_sheet[x][y]==1) return false;
	else return true;
}

void film::outdata_sheet(){
    cout<<endl<<"            ---Man Hinh---    "<<endl;
	cout<<"   1  2  3  4  5  6  7  8  9  10 11 12  "<<endl;
	cout<<"    -------------------------------"<<endl;
	char a='A';
	for(int i=0; i<10;i++){
		cout<<char(a+i)<<"- ";
    	for(int j=0; j<12;j++){
    		cout<<this->data_sheet[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void film::savedata_sheet(fstream &f){
	f<<this->ID_film<<endl;
	for(int i=0; i<10;i++){
    	for(int j=0; j<11;j++){
    		f<<this->data_sheet[i][j]<<" ";
		}
		f<<this->data_sheet[i][11]<<endl;
	}
}

film film::fixsheet(int x, int y){
	this->data_sheet[x][y]=1;
	return *this;
}

string film::getID(){
	return this->ID_film;
}

void film::get_suggest(int x[], int y[]){
	int count = 0;
	for(int i=0;i<10;i++){
		for(int j=0;j<12;j++){
			if(this->data_sheet[i][j]==3){
				x[count]=i;
				y[count]=j;
				count++;
			}
		}
	}
	cout<<endl;
}
bool film::checkid(string id){
	if(this->ID_film==id) return true;
	else return false;
}

void film::setfilm(string id, string name, string infor, float t, int c){
    this->ID_film=id;
	this->name_film=name;
	this->infor_film=infor;
	this->start_time=t;
	this->cost=c;
	for(int i=0;i<10;i++){
		for(int j=0;j<12;j++){
			this->data_sheet[i][j]=0;
		}
	}
}

void film::save_data_film(fstream &f){
    f<<this->ID_film<<"-"<<this->name_film<<"-"<<this->infor_film<<"-"<<this->start_time<<" "<<this->cost;
}

void film::edit_infor_film(){
	int i;
	cout<<endl<<"Ban muon thay doi thong tin gi?"<<endl;
	cout<<" - 1. Ten phim"<<endl;
	cout<<" - 2. Thong tin"<<endl;
	cout<<" - 3. Gio chieu"<<endl;
	cout<<" - 4. Gia ve"<<endl;
	cout<<"----->"; cin>>i;
	string new_infor;
	getline(cin,new_infor);
	switch (i){
		case 1: {
			cout<<"Nhap ten moi: ";
			getline(cin, new_infor);
			this->name_film = new_infor;
			break;
		}
		case 2: {
			cout<<"Nhap thong tin moi: ";
			getline(cin, new_infor);
			this->infor_film = new_infor;
			break;
		}
		case 3:{
			float t;
			cout<<"Nhap gio moi: ";
			cin>>t;
			this->start_time = t;
			break;
		}
		case 4:{
			int c;
			cout<<"Nhap gia tien moi: ";
			cin>>c;
			this->cost =c;
			break;
		}
	}
	int t;
	cout<<"Thay doi them (1. Co, 2. Khong) ?"; cin>>t;
	if(t==1) this->edit_infor_film();
}