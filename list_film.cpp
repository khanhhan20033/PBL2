#include <iostream>
#include "list_film.h"
#include "../suggest_sheets/main_suggest.cpp"
#include <string>
#include <fstream>

using namespace std;

void list_film::getlist_film(){
	fstream f;
	f.open("./database/data_film.txt");
	fstream s;
	s.open("./database/data_sheet.txt");
    while(!f.eof()){
    	film t;
    	t.getfilm(f);
    	t.getdata_sheet(s);
    	this->addLast(t);
	}
	f.close();
	s.close();
}

void list_film::outlist_film(){
	cout<<"Danh sach phim:"<<endl;
	for(int i=0;i<this->length();i++){
		int j=i+1;
		cout<<j<<" - ";
		this->get(i).outname_film();
	} 
}

void list_film::outlist(){
	for(int i=0;i<this->length();i++){
		int j=i+1;
		cout<<j<<" - ";
		this->get(i).outfilm();
	} 
}

void choose_sheet(int &x, int &y){
	cout<< "Chon vi tri (vi du: 'A1'): ";
	char a;
	cin >> a;
	x = int(a)-65;
    cin >> y; y--; 
}

void list_film::booking_banphim(film t, int &n, int x[], int y[]){
	for(int i=0;i<n;i++){
		choose_sheet(x[i],y[i]);
		while(t.checksheet(x[i], y[i])==0){
		    cout<< "Ghe da duoc dat. Vui long chon lai!"<<endl;
		    choose_sheet(x[i], y[i]);
	    }
	}
}

void list_film::booking(film &t, int &so_ve, int x[], int y[], int &n){
	this->outlist_film();
	cout<<endl<<"Nhap phim muon xem:";cin>>n;
	n=n-1;
	t= this->get(n);
	t.outfilm();
	int k;
	cout<<endl<<"Ban co xem phim nay khong?"<<endl;
	cout<<"Nhan 1: De mua ve."<<endl;
	cout<<"Nhan 2: Chon phim khac."<<endl;
	cout<<"------------->"; cin>>k;
	if(k==2){
    	system("cls");
    	this->booking(t,so_ve, x, y, n);
    	return;
    }
    else if(k==1){
    	cout<<endl<< "-----So do cho ngoi----- "<<endl<<endl;
    	t.outdata_sheet();
	}
	int c=0, i;
	cout<<"Nhap so luong ve muon dat: "; cin>>so_ve;
	list_film l;
	main_suggest(l,t,so_ve, i);
	if(i!=1) menu_suggest(c);
	if(i==1) c=2;
	switch (c){
        case 1: get_suggest(l, so_ve, x, y); break;
        case 2: this->booking_banphim(t,so_ve,x,y); break;
        case 3: {film film; this->booking(film,so_ve, x, y, n); break;}
        case 4: exit(0);
	} 
    for(int i=0; i<so_ve;i++){
     	t.fixsheet(x[i],y[i]);
	}
}

void list_film::fix_sheet(int n, int x, int y){
	this->get(n).fixsheet(x,y);
}

void list_film::updatedata_sheet(int n, film t){
	ofstream f1;
	f1.open("./database/data_sheet.txt",ios_base::out);
	f1.close();
	fstream f;
	f.open("./database/data_sheet.txt");
	for(int i=0;i<this->length();i++){
		if(i!=n){
			this->get(i).savedata_sheet(f);
		}
		else{
            t.savedata_sheet(f);
		}
	}
	f.close();
}

void list_film::chance_list_film(){
	this->outlist_film();
	cout<<endl<<"Ban muon?"<<endl;
	cout<<"1. Them phim moi."<<endl;
	cout<<"2. Xoa phim."<<endl;
	cout<<"3. Thay doi thong tin cua phim"<<endl;
	cout<<"4. Thoat."<<endl;
	int i;
	cout<<"--->";cin>>i;
	string a; getline(cin, a);
	switch (i){
		case 1: this->add_new_film(); break;
		case 2: this->remove_film();  break;
		case 3: this->edit_infor_film(); break;
		case 4: {
			system("pause");
			system("cls");
			return;
		}
	}
	this->chance_list_film();
}

void list_film::add_new_film(){
    cout<<endl<< "Nhap cac thong tin cua phim moi!"<<endl;
	string new_ID, new_name, new_infor;
	float new_start_time;
	int new_cost;
	this->add_ID(new_ID);
	cout<<"Ten phim: "; getline(cin,new_name);
	cout<<"Thong tin: "; getline(cin,new_infor);
	cout<<"Thoi gian chieu: "; cin>>new_start_time;
	cout<<"Gia ve: "; cin>>new_cost;
	film t;
	t.setfilm(new_ID, new_name, new_infor, new_start_time, new_cost);
	this->addLast(t);
	fstream a;
	a.open("./database/data_film.txt");
    a.seekp(0, ios_base::end);
	a<<endl;
	t.save_data_film(a);
	a.close();
	fstream s;
	s.open("./database/data_sheet.txt");
	s.seekp(0,ios_base::end);
	t.savedata_sheet(s);
	s.close();
	cout<<"Da them thanh cong!!"<<endl<<endl;
}

void list_film::add_ID(string &id){
	cout<<"ID: "; getline(cin,id);
	if(id.empty()){
		cout<<"ID khong hop le!"<<endl;
		this->add_ID(id);
	}
	for(int i=0; i<this->length();i++){
		if(this->get(i).checkid(id)){
			cout<<"ID da ton tai. Hay nhap ID khac!!"<<endl;
			this->add_ID(id);
		}
	}
}

void list_film::remove_film(){
    int i, j;
	cout<<"Chon phim muon xoa: ";cin>>i;
	i=i-1;
	this->get(i).outfilm();
	cout<<endl<<"Ban co chac muon xoa phim nay khong?"<<endl;
	cout<<"1. Xoa."<<endl;
	cout<<"2. Khong xoa nua."<<endl;
	cout<<"--->"; cin >>j;
	if(j==1){
		this->removeAtIndex(i);
		this->save_data_films();
		film t;
		this->updatedata_sheet(-1,t);
		cout<<"Da xoa thanh cong!!!"<<endl<<endl;
	}
}
void list_film::save_data_films(){
	ofstream f1;
	f1.open("./database/data_film.txt", ios_base::out);
	f1.close();
    fstream f;
	f.open("./database/data_film.txt");
	this->get(0).save_data_film(f);
	for(int i=1; i<this->length();i++){
		f<<endl;
		this->get(i).save_data_film(f);
	}
	f.close();
}

void list_film::edit_infor_film(){
	int i;
	cout<<"Chon phim muon thay doi thong tin: "; cin>>i;
	i=i-1;
	film t;
	t = this->get(i);
	t.outfilm();
	t.edit_infor_film();
	t.outfilm();
    cout<<"Xac nhan thay doi!"<<endl;
	cout<<" - 1. Xac nhan"<<endl;
	cout<<" - 2. Huy."<<endl;
	int j;
	cout<<"---->"; cin>>j;
	if(j==1){
		this->removeAtIndex(i);
		this->addAtIndex(i, t);
		this->save_data_films();
	}
}

void list_film::check_sheet(){
	system("cls");
	this->outlist_film();
	cout<<"Ban muon xem tinh trang dat cho cua phim nao?"<<endl;
	int i;
	cout<<"--->";cin>>i;
	i=i-1;
	this->get(i).outdata_sheet();
    cout<<"Xem phim khac?"<<endl;
	cout<<"1. Co"<<endl;
	cout<<"2. Thoat"<<endl;
	cout<<"---->"; cin>>i;
	if(i==1) check_sheet();
	else{
		system("cls");
		return;
	}
}
