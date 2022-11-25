#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "ticket.h"

void ticket::setticket(account_user a, film f,int n, int x[], int y[]){
	this->so_ve=n;
	for(int i=0;i<n;i++){
		this->hang[i] = x[i];
	    this->cot[i] = y[i];	
	}
	this->a = a;
	this->f = f; 
	this->cost=n*f.getcost();
}

void pr_chance(int x, int y){
	cout<<char(x+65)<<y+1;
}

void ticket::outticket(){
	cout<<endl<<"---Hoa don mua ve xem phim---"<<endl;
	this->a.outaccount_ticket();
	this->f.outfilm_ticket();
	cout<<"So luong: "<<this->so_ve<<endl;
	cout<<"Vi tri: ";
	for(int i=0; i<this->so_ve;i++){
		pr_chance(this->hang[i],this->cot[i]);
		cout<<" ";
	}
	cout<<endl<<"Thanh tien: "<<this->cost<<" VND"<<endl;
	cout<<"--------------"<<endl;
}

void ticket::savedata(){
	fstream f;
	f.open("./database/data_output.txt");
	f.seekg(0,ios_base::end);
	f<<this->a.getID()<<"-"<<this->f.getID()<<"-";
	for(int i=0;i<this->so_ve;i++){
		f<<"("<<this->hang[i]<<"-"<<this->cot[i]<<")"<<"-";
	}
	f<<":"<<this->cost<<endl;
	f.close(); 
} 
