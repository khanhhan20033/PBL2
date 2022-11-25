#ifndef account_user_h
#define account_user_h
#include "account.cpp"
#include <string>

class account_user: public account{
	private:
	    int sophimdaxem;
	    char loai_khach_hang;
	public:
		void getdata_sophim(ifstream &f);
		void outaccount();
		void outaccount_ticket();
		string getID();
		void setaccount(string ID, string pwd, string name);
		account_user fix_sophim(int n);
		void save_update_sophim(fstream &f);
};

#endif
