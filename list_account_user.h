#ifndef list_account_user_h
#define list_account_user_h
#include "./single/account_user.h"
#include "../LinkedList/LinkedList.cpp"
#include <string>

class list_account_user :public LinkedList<account_user>{
	public:
		void getlist_account();
		void outlist_account();
		void login(account_user &a);
		int checklogin(string id, string pwd, account_user &a);
		void signup(account_user &a);
		void update_sophim(int n, account_user a);
		void chance_list_account();
		void find_account(string e, account_user &a, int &index);
		void remove_account();
		void update_list_account();
		void add_account();
		bool checkid(string id);
		void add_ID(string &id);
};

#endif
