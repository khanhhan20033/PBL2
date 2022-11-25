#ifndef film_h
#define film_h
#include <string>
using namespace std;
class film{
	private: 
		string ID_film;
		string name_film;
		string infor_film;
		float start_time;
		int cost;
		int data_sheet[10][12];
	public:
	    void getfilm(fstream &f);
	    void outfilm();
	    void outname_film();
	    void outfilm_ticket();
	    void getdata_sheet(fstream &f);
	    void outdata_sheet();
	    bool checksheet(int x, int y);
	    void savedata_sheet(fstream &f); 
	    film fixsheet(int x, int y);
	    string getID();
		int getcost();
	    void get_suggest(int x[10], int y[12]);
		bool checkid(string id);
		void setfilm(string id, string name, string infor, float t, int c);
		void save_data_film(fstream &f);
		void edit_infor_film();
};

#endif
