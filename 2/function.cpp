#include <iostream>
#include <windows.h>
#include <math.h>
#include <deque>
#include <iterator>
#include<map>
#include <string.h>
#include "Header.h"

using namespace std;


object::object() {
	//category = "";//nullptr
	time = 0;
}

/*string object::get_category() {
	return category;
}*/


/*void object::set_category(string a) {
	category = a;
}*/


int object::get_time() {
	return time;
}


void object::set_time(int a) {
	time = a;
}


teacher:: teacher() :object() {
	name = "";
	position = "";
	//weight = 0;
	min = 0;
	max = 0;
}


void  teacher::set_teach(string c, discipline* a, int b) {
	dt *w=new dt;
	w->d = new discipline();
	w->d = a;
	w->type = c;
	w->t = b;
	teach.push_back(*w);
	/*for (int i = 0; i < size; i++) {
		if (c == Type[i]) {
			//w.d = a;
			w.t = b;
			teach.push_back(w);
		}
	}*/
}


void teacher:: set_map1(int size1, std::string* b, double* s) {
	for (int i = 0; i < size1; i++) {
		map1[b[i]] = s[i];
	}
}

int teacher::size_teach() {
	return teach.size();
}


dt* teacher::get_list() {
	dt *array=new dt[teach.size()];
	list <dt> ::iterator it;
	int d = 0;
	for (it = teach.begin(); it != teach.end(); it++) {
		array[d] = *it;
		d++;
	}
	return array;
}


double teacher::map11(string a) {
	map<string, double>::iterator iter;
	for (iter = map1.begin(); iter != map1.end(); iter++) {
		if (iter->first == a) {
			return iter->second;
		}
	}


	map<string, double>::iterator i = map1.find(a);
	if (i == map1.end()) {
		return false;
	}
	else
		return true;
}

int teacher::ssize() {
	return teach.size();
}


string teacher::get_name() {
	return name;
}

string teacher::get_position() {
	return position;
}


/*double teacher::get_weight() {
	return weight;
}*/


int teacher::get_min() {
	return min;
}

int teacher::get_max() {
	return max;
}

void teacher::set_name(string a) {
	name = a;
}

void teacher::set_position(string a) {
	if (a == "преподаватель") {
		min = 852;
		max = 1000;
	}
	if (a == "старший преподаватель") {
		min = 833;
		max = 1000;
	}
	if (a == "доцент") {
		min = 785;
		max = 1000;
	}
	if (a == "профессор") {
		min = 550;
		max = 1000;
	}
	if (position == "преподаватель") {
		size = 1;
		string *Type= new string[size];
		Type[0] = "лабораторная работа";
	}
	if (position == "старший преподаватель") {
		size = 3;
		string* Type = new string[size];
		Type[0] = "лабораторная работа";
		Type[1] = "практика";
		Type[2] = "лекция";
	}
	if (position == "доцент") {
		size = 2;
		string* Type = new string[size];
		Type[0] = "практика";
		Type[1] = "лекция";
	}
	if (position == "профессор") {
		size = 2;
		string* Type = new string[size];
		Type[0] = "практика";
		Type[1] = "лекция";
	}
	position = a;
}


/*void teacher::set_weight(double a) {
	weight = a;
}*/


void teacher::set_min(int a) {
	min = a;
}


void teacher::set_max(int a) {
	max = a;
}


discipline::discipline() :object() {
	title = "";
	//type = "";
}

string discipline :: get_title() {
	return title;
}


/*string discipline::get_type() {
	return type;
}*/




void discipline :: set_title(string a) {
	title = a;
}


/*void discipline::set_type(string a) {
	type = a;
}*/


/*void discipline::set_discip(string a, string c, int b) {
	nt w;
	w.n = c;
	w.tim = b;
	w.ttype = a;
	discip.push_back(w);
}*/

string discipline::get_ccategory() {
	return ccategory;
}


void discipline::set_ccategory(string a) {
	ccategory = a;
}

void discipline::set_d(int a1, int a2, int a3) {
	y a;
	a.Tim = a1;
	a.Type = "лабораторная работа";
	d.push_back(a);
	y b;
	b.Tim = a2;
	b.Type = "практика";
	d.push_back(b);
	y c;
	c.Tim = a2;
	c.Type = "лекция";
	d.push_back(c);

}

y* discipline::get_d() {
	int s = d.size();
	y* arr = new y[s];
	int r = 0;
	for (list<y>::iterator i = d.begin(); i != d.end(); i++) {
		arr[r] = *i;
		r++;
	}
	return arr;
}


void discipline ::set_discip(string c, teacher *a, int b) {
	nt* w = new nt;
	w->n = new teacher();
	w->n = a;
	w->ttype = c;
	//w.n = a;
	w->tim = b;
	discip.push_back(*w);
}




void function1(teacher* mass1, discipline* mass2, int size1, int size2) {
	int TIME = 0;
	for (int i = 0; i < size2; i++) {
		TIME += mass2[i].get_time();
	}
	int r = 0;
	while (TIME > 0) {

	}
}


template <class Type>
Type* find_category(Type* mass, int n, string kat) {
	int g = 0;
	for (int i = 0; i < n; i++) {
		if (mass[i].get_category() == kat)
			g++;
	}
	Type* mas = new Type[g]();
	int y = 0;
	for (int i = 0; i < n; i++) {
		if (mass[i].get_category() == kat)
			mas[y] = mass[i];
		y++;
	}
	return mas;
}



//РАНДОМНОЕ ЧИСЛО [1,n]
int random(int a) {
	return rand() % a + 1;
}



//КРИТЕРИИ

criterion1::criterion1(teacher t) {
	this -> t = t;
}
criterion1::criterion1() {

}
criterion2::criterion2(teacher* t) {
	this->t = t;
}

double criterion1::function() {
	int TIME = 0;
	dt* arr = new dt[t.ssize()];
	arr = t.get_list();
	for (int i = 0; i < t.ssize(); i++) {
		TIME += arr[i].t;
	}
	if (TIME < t.get_min()) {
		return abs((double(TIME) /double( t.get_min()) * 100) - 100);
	}
	if (TIME > t.get_max()) {
		return abs((double(t.get_max())/ double(TIME) * 100) - 100);
	}
	return 0;
}


double criterion2::function() {
	dt* arr = new dt[t->ssize()];
	arr = t->get_list();
	int pos = 0, neg = 0;
	for (int i = 0; i < t->ssize(); i++) {
		discipline *buf = arr[i].d;
		string B = buf->get_ccategory();
		double k = t->map11(B);
		if (k !=0)
			pos++;
		else
			neg++;
	}  
	return double(double(pos) * 100 /double(neg + pos));
}



void spread(teacher* mass1, discipline* mass2, int size1, int size2) {
	int v = 0;
	for (int i = 0; i < size2; i++) {
		if (v == size1) {
			v = 0;
		}
		y* mas = mass2[i].get_d();
		for (int j = 0; j < 3; j++) {
			int TIME = 0;
			y e = mas[j];
			TIME = e.Tim;
			while (TIME > 50) {
				int ttt = random(TIME);
				mass1[v].set_teach(e.Type, &mass2[i],ttt);
				mass2[i].set_discip(e.Type, &mass1[v],ttt);
				v++;
				if (v == size1) {
					v = 0;
				}
				TIME -= ttt;
			}
			mass1[v].set_teach(e.Type, &mass2[i],TIME);
			mass2[i].set_discip(e.Type, &mass1[v], TIME);
			v++;
			if (v == size1) {
				v = 0;
			}
		}
	}
}



double result(teacher* mass, int size) {
	double RESULT = 0;
	for (int i = 0; i < size; i++) {
		criterion1 sd(mass[i]);
		RESULT += sd.function();
	}
	return RESULT / size;
}