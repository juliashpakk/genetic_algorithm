// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <sstream>
#include "Header.h"

using namespace std;


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "");

	ifstream iy("test2.txt");
	string sss;
	int ir = 0;
	while (iy.peek() != EOF) {
		getline(iy, sss);
		ir++;
	}
	iy.close();

	discipline *array2=new discipline[ir];
	ifstream iin("test2.txt");
	for (int z = 0; z < ir; z++) {
		string name;
		iin >> name;
		array2[z].set_title(name);
		string kat;
		iin >> kat;
		array2[z].set_ccategory(kat);
		int a, b, c;
		iin >> a;
		iin >> b;
		iin >> c;
		array2[z].set_d(a, b, c);
	}


	ifstream ip("test1.txt");
	string ssw;
	int io = 0;
	while (ip.peek() != EOF) {
		getline(ip, ssw);
		io++;
	}
	ip.close();
	
	teacher *array1=new teacher[io];
	ifstream in("test1.txt");
	for (int i = 0; i < io; i++) {
		string a;
		in >> a;
		array1[i].set_name(a);
		string b;
		in >> b;
		if (b == "старший") {
			string c;
			in >> c;
			b += " ";
			b += c;
		}
		array1[i].set_position(b);
		

		string m1[5];
		double m2[5];
		for (int x = 0; x < 5; x++) {
			string p;
			in >> p;
			m1[x] = p;
			double r;
			in >> r;
			m2[x] = r;
		}
		array1[i].set_map1(5, m1, m2);
		
	}
	in.close();
	iin.close();

	ofstream hh("test3.txt");
	//hh << array1[0].get_name() << " " << array1[0].get_position() << " " << array1[0].get_max() << endl;
	spread(array1, array2, ir, io);

	for (int u = 0; u < ir; u++) {
		hh << "Фамилия преподавателя-" << array1[u].get_name() << endl;
		hh << "Размер листа:" << array1[u].size_teach() << endl;
		dt* aaa = new dt[array1[u].size_teach()];
		aaa = array1[u].get_list();
		for (int ee = 0; ee < array1[u].size_teach(); ee++) {
			hh <<"Время-"<< aaa[ee].t << " " <<"Вид занятия-"<< aaa[ee].type<<" ";
			discipline* rr = new  discipline;
			rr = aaa[ee].d;
			string dg = rr->get_title();
			hh << "Название предмета-" << dg << endl;
		}
		hh << endl;
		hh << endl;
	}
	
	for (int hkl = 0; hkl < ir; hkl++) {
		hh << hkl + 1 << ")";
		criterion1 element1(array1[hkl]);
		hh << element1.function() << endl;
	}
	hh << endl;
	hh << endl;
	for (int kl = 0; kl < ir; kl++) {
		hh << kl + 1 << ")";
		criterion2 element2(&array1[kl]);
		hh << element2.function() << endl;
	}
	hh.close();
	Sleep(9999);
	return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
