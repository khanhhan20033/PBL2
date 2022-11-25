#ifndef ticket_h 
#define ticket_h
#include "./single/account_user.cpp"
#include "./single/film.cpp"
#include <string>
 
class ticket{
	private:
		account_user a;
		film f;
		int so_ve;
		int hang[120];
		int cot[120]; 
		int cost;
	public:
		void setticket(account_user a, film f,int n, int x[], int y[]);
		void outticket();
		void savedata();
};

#endif
