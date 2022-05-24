#pragma once
#ifndef FUNC_H
#define FUNC_H
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
#endif // !FUNC_H
