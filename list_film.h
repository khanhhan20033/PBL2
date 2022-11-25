#ifndef list_film_h
#define list_film_h
#include "./single/film.h"
#include "../LinkedList/LinkedList.cpp"

class list_film: public LinkedList<film>
{
	public:
		void getlist_film();
		void outlist_film();
		void booking(film &t,int &so_ve, int x[], int y[], int &n);
		void booking_banphim(film t, int &n, int x[], int y[]);
		void outlist();
		void updatedata_sheet(int n, film t);
		void fix_sheet(int n, int x, int y);
        void chance_list_film();
		void add_new_film();
		void add_ID(string &id);
		void remove_film();
		void save_data_films();
		void edit_infor_film();
		void check_sheet();
}; 

#endif
