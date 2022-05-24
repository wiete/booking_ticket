#pragma once
#ifndef __CLASS_H__
#define __CLASS_H__
#include<iostream>
#include<iomanip>
#include<process.h>
#include <windows.h>   
#include <stdio.h> 
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<fstream>
#include<io.h>
#include<assert.h>
#include<vector>
#include<string.h>
#include<cmath>
#include"func.h"
using namespace std;
#pragma warning(disable:4996)
class Worker
{
private:
	char worker_ID[100];//主页面点击员工按钮，弹出窗口输入账号，然后因为账号是TXT文件名称，在指定目录查找员工对应的TXT文件，
						 //然后是输入密码，把输入的密码和TXT对应那一行的密码进行比对，如果成功，那么就创建一个worker类的对象，把这个TXT文件内容逐行赋值给对象，
						  // 复制完成后，这个对象的私有成员就已经获得了TXT文件的内容了，下一步就是把easyx图像和类对象进行整合配对。
	char worker_password[100];
	char worker_income[10];
	char worker_name[100];
	char worker_sex[10];
	int worker_income_int = 0;
	int have_del = 0;
public:
	Worker() {

	}
	Worker(char a[], char b[],char c[],char d[],char e[])
	{
		strcpy(worker_ID, a);
		strcpy(worker_password, b);
		strcpy(worker_income, c);
		strcpy(worker_name, d);
		strcpy(worker_sex, e);
	}
	void worker_face();
	void getID(const char a[]) {
		strcpy(worker_ID, a);
	}
	void get_password(const char b[]) {
		strcpy(worker_password, b);
	}
	void get_income(const char c[]) {
		strcpy(worker_income, c);
	}
	void get_name(const char d[]) {
		strcpy(worker_name, d);
	}
	void get_sex(const char e[]) {
		strcpy(worker_sex, e);
	}
	char* show_id() {
		return worker_ID;
	}
	char* show_password()
	{
		return worker_password;
	}
	char* show_income()
	{
		return worker_income;
	}
	char* show_name()
	{
		return worker_name;
	}
	char* show_sex()
	{
		return worker_sex;
	}
	void del_it()
	{
		have_del = 1;
	}
	int if_del()
	{
		return have_del;
	}
	void charToint()
	{
		for (int i = 0; i < strlen(worker_income); i++)
		{
			int temp = worker_income[i] - '0';
			worker_income_int += temp * pow(10, strlen(worker_income) - i - 1);

		}
	}
	friend bool operator>(Worker& a, Worker& b)
	{
		if (a.worker_income_int > b.worker_income_int)
			return true;
		else
		{
			return false;
		}
	}
};
class vehicle
{
public:
	char ID[20];
};
class massage1
{
public:
	char P_begin[100];
	char P_end[100];
	char T_begin[100];
	char T_end[100];
};
class massage2
{
public:
	char first_remain_ticket[10];
	char second_remain_ticket[10];
	char third_remain_ticket[10];
	char set_first_num[10];
	char set_second_num[10];
	char set_third_num[10];
	char first_price[10];
	char second_price[10];
	char third_price[10];
};
class Flight:virtual private vehicle,protected massage1,protected massage2
{
private:
	int del_it = 0;
public:
	Flight()
	{

	}
	Flight(char id[], char pbegin[], char pend[], char Tbegin[], char Tend[],char f_num[], char s_num[], char t_num[], char f_p[], char s_p[], char t_p[], char frt[], char srt[], char trt[]) {
		strcpy(ID, id);//复制
		strcpy(P_begin, pbegin);
		strcpy(P_end, pend);
		strcpy(T_begin, Tbegin);
		strcpy(T_end, Tend);
		strcpy(set_first_num, f_num);
		strcpy(set_second_num, s_num);
		strcpy(set_third_num, t_num);
		strcpy(first_price, f_p);
		strcpy(second_price, s_p);
		strcpy(third_price, t_p);
		strcpy(first_remain_ticket, frt);
		strcpy(second_remain_ticket, srt);
		strcpy(third_remain_ticket, trt);
		
	}
	Flight(Flight& f)
	{
		strcpy(ID, f.ID);//复制
		strcpy(P_begin, f.P_begin);
		strcpy(P_end, f.P_end);
		strcpy(T_begin, f.T_begin);
		strcpy(T_end, f.T_end);
		strcpy(set_first_num, f.set_first_num);
		strcpy(set_second_num, f.set_second_num);
		strcpy(set_third_num, f.set_third_num);
		strcpy(first_price, f.first_price);
		strcpy(second_price, f.second_price);
		strcpy(third_price, f.third_price);
		strcpy(first_remain_ticket, f.third_remain_ticket);
		strcpy(second_remain_ticket, f.second_remain_ticket);
		strcpy(third_remain_ticket, f.third_remain_ticket);
	}
	char* show_id()
	{
		return ID;
	}
	char* show_pb()
	{
		return P_begin;
	}
	char* show_pe()
	{
		return P_end;
	}
	char* show_tb()
	{
		return T_begin;
	}
	char* show_te()
	{
		return T_end;
	}
	char* show_fn()
	{
		return set_first_num;
	}
	char* show_sn()
	{
		return set_second_num;
	}
	char* show_tn()
	{
		return set_third_num;
	}
	char* show_fp()
	{
		return first_price;
	}
	char* show_sp()
	{
		return second_price;
	}
	char* show_tp()
	{
		return third_price;
	}
	char* show_fre()
	{
		return first_remain_ticket;
	}
	char* show_sre()
	{
		return second_remain_ticket;
	}
	char* show_tre()
	{
		return third_remain_ticket;
	}
	void if_del()
	{
		del_it = 1;
	}
	int get_del()
	{
		return del_it;
	}
	void get_id(const char a[])
	{
		strcpy(ID, a);
	}
	void get_pb(const char a[])
	{
		strcpy(P_begin, a);
	}
	void get_pe(const char a[])
	{
		strcpy(P_end, a);
	}
	void get_tb(const char a[])
	{
		strcpy(T_begin, a);
	}
	void get_te(const char a[])
	{
		strcpy(T_end, a);
	}
	void get_fn(const char a[])
	{
		strcpy(set_first_num, a);
	}
	void get_sn(const char a[])
	{
		strcpy(set_second_num, a);
	}
	void get_tn(const char a[])
	{
		strcpy(set_third_num, a);
	}
	void get_fp(const char a[])
	{
		strcpy(first_price, a);
	}
	void get_sp(const char a[])
	{
		strcpy(second_price, a);
	}
	void get_tp(const char a[])
	{
		strcpy(third_price, a);
	}
	void get_frn(const char a[])
	{
		strcpy(first_remain_ticket, a);
	}
	void get_srn(const char a[])
	{
		strcpy(second_remain_ticket, a);
	}
	void get_trn(const char a[])
	{
		strcpy(third_remain_ticket, a);
	}

};
class Boat :virtual private vehicle, protected massage1, protected massage2
{
private:
	int del_it = 0;
public:
	Boat()
	{

	}
	Boat(char id[], char pbegin[], char pend[], char Tbegin[], char Tend[], char f_num[], char s_num[], char t_num[], char f_p[], char s_p[], char t_p[], char frt[], char srt[], char trt[]) {
		strcpy(ID, id);//复制
		strcpy(P_begin, pbegin);
		strcpy(P_end, pend);
		strcpy(T_begin, Tbegin);
		strcpy(T_end, Tend);
		strcpy(set_first_num, f_num);
		strcpy(set_second_num, s_num);
		strcpy(set_third_num, t_num);
		strcpy(first_price, f_p);
		strcpy(second_price, s_p);
		strcpy(third_price, t_p);
		strcpy(first_remain_ticket, frt);
		strcpy(second_remain_ticket, srt);
		strcpy(third_remain_ticket, trt);

	}
	Boat(Boat& f)
	{
		strcpy(ID, f.ID);//复制
		strcpy(P_begin, f.P_begin);
		strcpy(P_end, f.P_end);
		strcpy(T_begin, f.T_begin);
		strcpy(T_end, f.T_end);
		strcpy(set_first_num, f.set_first_num);
		strcpy(set_second_num, f.set_second_num);
		strcpy(set_third_num, f.set_third_num);
		strcpy(first_price, f.first_price);
		strcpy(second_price, f.second_price);
		strcpy(third_price, f.third_price);
		strcpy(first_remain_ticket, f.third_remain_ticket);
		strcpy(second_remain_ticket, f.second_remain_ticket);
		strcpy(third_remain_ticket, f.third_remain_ticket);
	}
	char* show_id()
	{
		return ID;
	}
	char* show_pb()
	{
		return P_begin;
	}
	char* show_pe()
	{
		return P_end;
	}
	char* show_tb()
	{
		return T_begin;
	}
	char* show_te()
	{
		return T_end;
	}
	char* show_fn()
	{
		return set_first_num;
	}
	char* show_sn()
	{
		return set_second_num;
	}
	char* show_tn()
	{
		return set_third_num;
	}
	char* show_fp()
	{
		return first_price;
	}
	char* show_sp()
	{
		return second_price;
	}
	char* show_tp()
	{
		return third_price;
	}
	char* show_fre()
	{
		return first_remain_ticket;
	}
	char* show_sre()
	{
		return second_remain_ticket;
	}
	char* show_tre()
	{
		return third_remain_ticket;
	}
	void if_del()
	{
		del_it = 1;
	}
	int get_del()
	{
		return del_it;
	}
	void get_id(const char a[])
	{
		strcpy(ID, a);
	}
	void get_pb(const char a[])
	{
		strcpy(P_begin, a);
	}
	void get_pe(const char a[])
	{
		strcpy(P_end, a);
	}
	void get_tb(const char a[])
	{
		strcpy(T_begin, a);
	}
	void get_te(const char a[])
	{
		strcpy(T_end, a);
	}
	void get_fn(const char a[])
	{
		strcpy(set_first_num, a);
	}
	void get_sn(const char a[])
	{
		strcpy(set_second_num, a);
	}
	void get_tn(const char a[])
	{
		strcpy(set_third_num, a);
	}
	void get_fp(const char a[])
	{
		strcpy(first_price, a);
	}
	void get_sp(const char a[])
	{
		strcpy(second_price, a);
	}
	void get_tp(const char a[])
	{
		strcpy(third_price, a);
	}
	void get_frn(const char a[])
	{
		strcpy(first_remain_ticket, a);
	}
	void get_srn(const char a[])
	{
		strcpy(second_remain_ticket, a);
	}
	void get_trn(const char a[])
	{
		strcpy(third_remain_ticket, a);
	}

};
class User
{
private:
	char user_ID[100];
	char user_password[100];
	char sex[100];
	char name[100];
	struct my_booking
	{
		char booking_id[10];
		char num[10];
	}kind[100];
	struct my_booking_boat
	{
		char booking_id[10];
		char num[10];
		
	}kind2[100];
	int booking_num = 0;
	int Boat_booking_num = 0;
public:
	User()
	{

	}
	User(char a[], char b[], char c[], char d[])
	{
		strcpy(user_ID, a);
		strcpy(user_password, b);
		strcpy(sex, c);
		strcpy(name, d);
	}
	void get_id(const char a[])
	{
		strcpy(user_ID, a);
	}
	void get_password(const char a[])
	{
		strcpy(user_password, a);
	}
	void get_sex(const char a[])
	{
		strcpy(sex, a);
	}
	void get_name(const char a[])
	{
		strcpy(name, a);
	}
	void get_booking(const char a[],const char b[])
	{
		strcpy(kind[booking_num].booking_id, a);
		strcpy(kind[booking_num].num, b);
		booking_num++;
	}
	void get_boat_booking(const char a[], const char b[])
	{
		strcpy(kind2[booking_num].booking_id, a);
		strcpy(kind2[booking_num].num, b);
		Boat_booking_num++;
	}
	char* show_id()
	{
		return user_ID;
	}
	char* show_pd()
	{
		return user_password;
	}
	char* show_name()
	{
		return name;
	}
	char* show_sex()
	{
		return sex;
	}
	int show_flight_num()
	{
		return booking_num;
	}
	int show_boat_num()
	{
		return Boat_booking_num;
	}
	
};
//汇总所有卖的票数
//int operator+(const User& a1, const User& a2)
//{
//	return a1.booking_num + a2.booking_num;
//}
#endif
