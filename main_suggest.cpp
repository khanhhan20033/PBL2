#include <iostream>
using namespace std;
#include <fstream>
#include "suggest_sheets.cpp"
#include "../management/list_film.h"

void print_suggest(list_film &li, int &i){
    fstream fsug3;
    fsug3.open("./suggest_sheets/data_suggest.txt");
	char a;
	fsug3>>a;
	if(a==NULL){
		cout<<"Khong co goi y nao! Hay nhap tu ban phim!"<<endl;
		i=1;
		return;
	}
	fsug3.seekp(0,ios_base::beg);
    while(!fsug3.eof()){
    	film t;
    	t.getdata_sheet(fsug3);
    	li.addLast(t);
	}
	int count=1;
    for(int i=0;i<li.length()&&i<3;i++){
    	cout<<endl<<"---> Goi y "<<count<<" <---";count++;
    	li.get(i).outdata_sheet();
	}
	fsug3.close();
}

void main_suggest(list_film &l, film f, int so_ve, int &i){
    ofstream fsug1;
    fsug1.open("./suggest_sheets/data_film_sheet.txt",std::ofstream::out); fsug1.close();
	fstream fsug3;
	fsug3.open("./suggest_sheets/data_film_sheet.txt");
    f.savedata_sheet(fsug3);
	fsug3.close();
    ofstream fsug2;
    fsug2.open("./suggest_sheets/data_suggest.txt",std::ofstream::out); fsug2.close();
	i=0;
    suggest_sheets(so_ve);
    print_suggest(l, i);
}

void menu_suggest(int &c){
	cout<<"Ban muon chon theo goi y khong?"<<endl;
	cout<<"- Nhap 1: Co!"<<endl;
	cout<<"- Nhap 2: Khong!"<<endl;
	cout<<"- Nhap 3: Chon phim khac."<<endl;
	cout<<"----->";cin>>c;
} 

void get_suggest(list_film sug, int so_ve, int x[], int y[]){
	cout<<endl<<"Ban muon chon goi y nao?"<<endl;
	int c = sug.length();
	switch (c){
		case 3: cout<<"Nhap 3: Goi y 3"; cout<<endl;
		case 2: cout<<"Nhap 2: Goi y 2"; cout<<endl;
		case 1: cout<<"Nhap 1: Goi y 1"; cout<<endl;
	}
	int t;
	cout<<"----> "; cin>>t;
    sug.get(t-1).get_suggest(x,y);
}
