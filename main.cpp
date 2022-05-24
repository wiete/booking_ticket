#pragma once
#include"class.h"
#include<iostream>
#include<iomanip>
#include<process.h>
#include <windows.h>   
#include <stdio.h> 
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<easyx.h>
#include<fstream>
#include<io.h>
#include<assert.h>
#include<vector>
#include<string.h>
#include<string>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;
int Boss_log();
int User_log();
int User_sign();
int if_is_boss(char a[]);
void Boss_face();
void Boss_show_INF();
void boss_change_INF();
void put_boss_INF();
void manage_Worker();
void put_worker_INF();
void worker_change_INF();
void add_worker();
void delete_worker();
void Worker_face(int i);
void show_worker_own_INF(int i);
void worker_flight();
void worker_INF_change_own(int i);
void show_flight();
void add_flight();
void del_flight();
void change_flight();

void User_face(int i);
void User_INF_show(int i);
void User_INF_change(int i);
void User_booking_show(int i);
void show_flight_user();
void booking_add(int i);
void booking_del(int i);
void my_booking(int i);
void booking_del_it(char file[], int cout);

void copyTxt(char srcFilename[], char dstFilename[]);
int CountLines(string filename);//得到TXT文件的总行数
string ReadLine(string filename, int line);
string Readtxt(string filename, int line);
void changeLine(char file[], int line, char change_tag[]);
const char Boss_password_path[] = "C:\\ticket_booking_INF\\Boss_Password.txt";
IMAGE imag_background;
IMAGE Boss_face_background;
IMAGE all_job;
IMAGE Worker_face_background;
IMAGE User_face_background;
int all_width = 1000;
int all_height = 600;
RECT Rboss = { 150,400,250,450 };
RECT Rworker = { 450,400,550,450 };
RECT Ruser = { 750,400,850,450 };
RECT R_INF_boss = { 150,400,250,450 };
RECT R_INF_worker = { 750,400,850,450 };
RECT R_INF_worker_own = { 150,400,250,450 };
RECT R_worker_flight = { 750,400,850,450 };
RECT Rreturn = { 50,40,150,90 };
RECT R_boss_INF_change = { 150,400,250,450 };
RECT R_worker_INF_change = { 150,400,250,450 };
RECT R_add_worker = { 150,200,250,250 };
RECT R_del_worker = { 150,300,250,350 };
RECT R_add_fly = { 150,400,250,450 };
RECT R_change_fly = { 750,400,850,450 };
RECT R_del_fly = { 450,400,550,450 };
RECT R_INF_user = { 150,400,250,450 };
RECT R_user_booking = { 750,400,850,450 };
RECT R_booking_add = { 150,400,250,450 };
RECT R_booking_del = { 750,400,850,450 };
RECT R_my_booking = { 450,400,550,450 };
int worker_num = 0;
int user_num = 0;
int flight_num = 0;
int boat_num = 0;
Worker a[100];
User b[100];
Flight c[100];
Boat d[100];
int main()
{
	system("DIR /B C:\\ticket_booking_INF\\Worker\\*.txt > C:\\ticket_booking_INF\\worker_id.txt");
	ifstream file("C:\\ticket_booking_INF\\worker_id.txt", ios::in);
	string s;

	int i = 0;
	while (getline(file, s))//直到worker_id.txt中没有了名字
	{
		char p[100] = "C:\\ticket_booking_INF\\Worker\\";
		char p_id[100];
		strcpy(p_id, p);
		strcat(p_id, s.c_str());//得到位置
		a[i].getID(Readtxt(p_id, 1).c_str());
		a[i].get_password(Readtxt(p_id, 2).c_str());
		a[i].get_income(Readtxt(p_id, 3).c_str());
		a[i].get_name(Readtxt(p_id, 4).c_str());
		a[i].get_sex(Readtxt(p_id, 5).c_str());
		i++;
		worker_num++;
	}
	file.close();
	system("DIR /B C:\\ticket_booking_INF\\Flight\\*.txt > C:\\ticket_booking_INF\\flight_id.txt");
	ifstream fly("C:\\ticket_booking_INF\\flight_id.txt", ios::in);
	string k;
	i = 0;
	while (getline(fly, k))//直到worker_id.txt中没有了名字
	{
		char p[100] = "C:\\ticket_booking_INF\\Flight\\";
		char p_id[100];
		strcpy(p_id, p);
		strcat(p_id, k.c_str());//得到位置
		c[i].get_id(Readtxt(p_id, 1).c_str());
		c[i].get_pb(Readtxt(p_id, 2).c_str());
		c[i].get_pe(Readtxt(p_id, 3).c_str());
		c[i].get_tb(Readtxt(p_id, 4).c_str());
		c[i].get_te(Readtxt(p_id, 5).c_str());
		c[i].get_fn(Readtxt(p_id, 6).c_str());
		c[i].get_sn(Readtxt(p_id, 7).c_str());
		c[i].get_tn(Readtxt(p_id, 8).c_str());
		c[i].get_fp(Readtxt(p_id, 9).c_str());
		c[i].get_sp(Readtxt(p_id, 10).c_str());
		c[i].get_tp(Readtxt(p_id, 11).c_str());
		c[i].get_frn(Readtxt(p_id, 12).c_str());
		c[i].get_srn(Readtxt(p_id, 13).c_str());
		c[i].get_trn(Readtxt(p_id, 14).c_str());
		i++;
		flight_num++;
	}
	fly.close();

	system("DIR /B C:\\ticket_booking_INF\\User\\*.txt > C:\\ticket_booking_INF\\user_id.txt");
	ifstream file3("C:\\ticket_booking_INF\\user_id.txt", ios::in);
	string s2;

	 i = 0;
	while (getline(file3, s2))//直到user_id.txt中没有了名字
	{
		char p[100] = "C:\\ticket_booking_INF\\User\\";
		char p_id[100];
		strcpy(p_id, p);
		strcat(p_id, s2.c_str());//得到位置
		b[i].get_id(Readtxt(p_id, 1).c_str());
		b[i].get_password(Readtxt(p_id, 2).c_str());
		b[i].get_name(Readtxt(p_id, 3).c_str());
		b[i].get_sex(Readtxt(p_id, 4).c_str());
		
		i++;
		user_num++;
	}
	file3.close();

	ifstream file4("C:\\ticket_booking_INF\\user_id.txt", ios::in);
	string m;
	i = 0;
	while (getline(file4, m))//直到user_id.txt中没有了名字
	{
		char p[100] = "C:\\ticket_booking_INF\\User_booking\\";
		char p_id[100];
		strcpy(p_id, p);
		strcat(p_id, m.c_str());//得到位置
		string n;
		ifstream file5(p_id, ios::in);//打开id对应的txt文件
		while (getline(file5, n))
		{
			char id[100], num[10];
			strcpy(id, n.c_str());
			getline(file5, n);
			strcpy(num, n.c_str());
			b[i].get_booking(id, num);
			
		}
		file5.close();
		i++;
	/*	user_num++;*/ // 因为已经增加过一次了
	}
	file4.close();
	initgraph(all_width, all_height);
	loadimage(&imag_background, "C:\\ticket_booking_photo\\background2.png", all_width, all_height);//斜杠要两个！！！！
	putimage(0, 0, &imag_background);
	setbkmode(TRANSPARENT);//透明字体;
	settextcolor(WHITE);//颜色

	
	drawtext(_T("老板"), &Rboss, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	drawtext(_T("员工"), &Rworker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	drawtext(_T("用户"), &Ruser, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	while (1) {
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.x >= 150 && m.x <= 250 && m.y >= 400 && m.y <= 450)
		{

			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (Boss_log() == 1)
				{
					Boss_face();
				}
			}
		}
		else if (m.x >= 450 && m.x <= 550 && m.y >= 400 && m.y <= 450)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				int find = 0;
				char tag_id[100];
				InputBox(tag_id, 100, "请输入员工账号");

				for (int i = 0; i < worker_num; i++)
				{
					if (strcmp(a[i].show_id(), tag_id) == 0)
					{
						find = 1;
						char tag_password[100];
						InputBox(tag_password, 100, "请输入密码");
						if (strcmp(tag_password, a[i].show_password()) == 0)
						{
							Worker_face(i);
						}
					}
				}
				if (find == 0)
				{
					char s[10];
					InputBox(s, 10, "登陆失败，点击确认退出...");
				}
			}
		}
		else if (m.x >= 750 && m.x <= 850 && m.y >= 400 && m.y <= 450)
		{
			if (m.uMsg == WM_LBUTTONDOWN) 
			{
				char choose0[10];
				InputBox(choose0, 10, "请选择：1.登录 2.注册");
				if (strcmp(choose0, "1") == 0)
				{
					int i = User_log();
					if (i != 0)
					{
						User_face(i - 1);
					}

				}
				else if (strcmp(choose0, "2") == 0)
				{
					int i = User_sign();
					User_face(i);
				}
				
			}
		}
	}
	_getch();
	closegraph();
	return 0;
}
