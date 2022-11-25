#include <iostream>
#include <winbgim.h>
#include <windows.h>
using namespace std;

void setcolor(int backgound_color, int text_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void Menu_infor(){
 	int i;
 	setcolor(0,9);
 	printf("\n%9c",201);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c",187);
 	printf("\n        %c %86c",186,186);
 	printf("\n        %c                           BPL2: DU AN CO SO LAP TRINH                                %c",186,186);
 	printf("\n        %c               DE TAI: XAY DUNG UNG DUNG DAT VE XEM PHIM TAI RAP PHIM                 %c",186,186);
 	printf("\n        %c %86c",186,186);
 	printf("\n        %c       Sinh vien thuc hien:                       Giao vien huong dan:                %c",186,186);
 	printf("\n        %c           %c Le Huu Minh Vu                            %c Tran Ho Thuy Tien            %c",186,45,45,186);
 	printf("\n        %c           %c Le Viet Thanh  %59c",186,45,186);
 	printf("\n        %c %86c",186,186);
 	printf("\n        %c",200);
 	for (i=0;i<=85;i++) printf("%c",205);
 	printf("%c\n",188);
}
void Menu_signup(int &i){
	setcolor(0,14);
	cout<< "Ban muon ?"<<endl;
	cout<< "- Nhan 1 de dang ki tai khoan moi."<<endl;
	cout<< "- Nhan 2 de dang nhap neu da co tai khoan."<<endl;
	cout<< "- Nhan 3 de tro lai"<<endl;
	cout<<">>>>";
	cin>>i;
	string e;
	getline(cin, e);
	setcolor(0,15);
}

void Menu_confirm(int &i){
	cout<<endl<<"Xac nhan lai don hang!"<<endl;
	cout<<"1. Xac nhan!"<<endl;
	cout<<"2. Huy!"<<endl;
	cout<<"3. Dang xuat"<<endl;
	cout<<"---> "; cin>>i;
}

void Menu_home(int &i){
	setcolor(0,14);
    cout<<"         >>>>>CHAO MUNG BAN DEN VOI UNG DUNG DAT VE XEM PHIM <<<<<"<<endl<<endl;
	setcolor(0,15);
	cout<<"                    1. Dang nhap/dang ki voi tu cach khach."<<endl;
	cout<<"                    2. Dang nhap Quan li."<<endl;
	cout<<"                    3. De tat ung dung."<<endl;
    cout<<"                    ---->"; cin>>i;
}

void Menu_host_login(int &i){
	setcolor(0,14);
	cout<< "Ban muon ?"<<endl;
	cout<< "- Nhan 1 de Dang nhap."<<endl;
	cout<< "- Nhan 2 de tro lai"<<endl;
	cout<<">>>>";
	cin>>i;
	string e;
	getline(cin, e);
	setcolor(0,15);
}

void Menu_host_chance(int &l){
    cout<<"Ban muon ?"<<endl;
	cout<<"1 - Kiem tra ve."<<endl;
	cout<<"2 - Them, xoa hoac chinh sua Phim."<<endl;
	cout<<"3 - Xem, xoa tai khoan nguoi dung."<<endl;
	cout<<"4 - Xem tinh trang dat cho."<<endl;
	cout<<"5 - Thoat"<<endl;
    cout<<"---->"; cin>>l;
}