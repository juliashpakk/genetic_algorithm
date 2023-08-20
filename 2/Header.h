#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <string.h>
#include <list>
#include <iterator>
#include <map>

class discipline;
class teacher;

class object {
	//std::string category;
	int time;
public:
	object(); 
	int get_time(); 
	void set_time(int a);
	//std::string get_category();
	//void set_category(std::string a);
};



struct dt {
	std::string type;//вид(лекция, лаб, пз)
	discipline *d;//дисциплина set_teach
	int t;//время
};

class teacher : public object {
	std::string name;
	std::string position;//должность
	int size;
	std::string* Type; 
	std::map<std::string, double> map1;// map<string, double> string = category; double = weigth 
	int min;
	int max;
	std::list<dt> teach;
public:
	int size_teach();
	teacher(); 
	dt* get_list();
	int ssize();
	double map11(std::string a);
	void set_map1(int size1, std::string *b, double *s);
	void set_teach(std::string c, discipline* a, int b);
	std::string get_name();
	std::string get_position();
	int get_min();
	int get_max();
	void set_name(std::string a);
	void set_position(std::string a);
	void set_min(int a);
	void set_max(int a);
};



struct nt {
	teacher* n;
	std::string ttype;
	int tim;
};
struct y {
	std::string Type;
	int Tim;
};

class discipline : public object {
	std::string title;//название
	std::string ccategory;//категория(А,В,С)
	std::list<nt> discip;
	std::list<y> d;
public:
	void set_discip(std::string c, teacher* a, int b);
	y* get_d();
	void set_d(int a1, int a2, int a3);
	discipline();
	//std::string ccategory();
	std::string get_title();
	void set_title(std::string a);
	std::string get_ccategory();
	void set_ccategory(std::string a);
};



void function1(teacher* mass1, discipline* mass2, int size1, int size2);

template <class Type>
Type* find_category(Type* mass, int n, std::string kat);

int random(int a);

void spread(teacher* mass1, discipline* mass2, int size1, int size2);

double result(teacher* mass, int size);


//КРИТЕРИИ
class criterion {
public:
	virtual double function()=0;
};


//max min
class criterion1 : public criterion {
	teacher t;
public:
	criterion1(teacher t);
	criterion1();
	double function();
};

//Может ли преподаватель работать в этой категории
class criterion2 : public criterion {
	teacher* t;
public:
	criterion2(teacher* t);
	double function();
};
#endif