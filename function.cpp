#include"func.h"
#include"class.h"
extern IMAGE imag_background;
extern IMAGE Boss_face_background;
extern IMAGE all_job;
extern IMAGE Worker_face_background;
extern IMAGE User_face_background;
extern int all_width;
extern int all_height;
extern RECT Rboss ;
extern RECT Rworker ;
extern RECT Ruser ;
extern RECT R_INF_boss;
extern RECT R_INF_worker ;
extern RECT R_INF_worker_own ;
extern RECT R_worker_flight;
extern RECT Rreturn ;
extern RECT R_boss_INF_change ;
extern RECT R_worker_INF_change ;
extern RECT R_add_worker;
extern RECT R_del_worker;
extern RECT R_add_fly;
extern RECT R_change_fly;
extern RECT R_del_fly;
extern RECT R_INF_user;
extern RECT R_user_booking;
extern RECT R_booking_add ;
extern RECT R_booking_del;
extern RECT R_my_booking;
extern int worker_num;
extern int user_num;
extern int flight_num ;
extern int boat_num = 0;
extern Worker a[];
extern User b[];
extern Flight c[];
extern Boat d[100];
const char Boss_password_path[] = "C:\\ticket_booking_INF\\Boss_Password.txt";
template<typename T>
void outputArray(const T* array, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << endl;
	}
}
int if_is_boss(char tag[])
{
	ifstream tagfile(Boss_password_path);
	char a[10];
	tagfile >> a;
	if (strcmp(a, tag) == 0)
	{
		return 1;
	}
	else
		return 0;
}
int Boss_log()
{
	int error_count = 0;
	while (error_count <= 3)
	{
		char tag_password[10];
		if (error_count == 0)
		{
			InputBox(tag_password, 10, "请输入老板密码");
			if (if_is_boss(tag_password) == 1)
				return 1;
			else
				error_count++;
		}
		else if (error_count != 0)
		{
			InputBox(tag_password, 10, "密码错误，请重新输入");
			if (if_is_boss(tag_password) == 1)
				return 1;
			else
				error_count++;
		}
	}
}
void Boss_face()
{
	loadimage(&Boss_face_background, "C:\\ticket_booking_photo\\boss_class.png", all_width, all_height);
	putimage(0, 0, &Boss_face_background);
	drawtext(_T("老板个人信息"), &R_INF_boss, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("管理员工"), &R_INF_worker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &imag_background);
			drawtext(_T("老板"), &Rboss, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("员工"), &Rworker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("用户"), &Ruser, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			Boss_show_INF();
		}

		else if (n.x >= 750 && n.x <= 850 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			manage_Worker();
		}

	}
}
void Boss_show_INF()
{
	loadimage(&all_job, "C:\\ticket_booking_photo\\all_job.png", all_width, all_height);
	putimage(0, 0, &all_job);

	put_boss_INF();

	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &Boss_face_background);
			drawtext(_T("老板个人信息"), &R_INF_boss, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("管理员工"), &R_INF_worker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			boss_change_INF();
			put_boss_INF();

		}
	}
}
void boss_change_INF()
{
	char choose[10];
	char done[100];
	while (1)
	{
		InputBox(choose, 10, "请输入你要修改的内容:1.密码 2.姓名 3.性别 4.收入");
		if (strcmp(choose, "1") == 0)
		{
			InputBox(done, 100, "请输入修改后的密码");
			ofstream file(Boss_password_path, ios::trunc);
			file << done;

			break;

		}
		else if (strcmp(choose, "2") == 0)
		{
			InputBox(done, 100, "请输入修改后的名称");
			char p[] = "C:\\ticket_booking_INF\\BOSS\\boss_INF.txt";
			changeLine(p, 1, done);//p文件，第一行，改成done[]
			break;
		}
		else if (strcmp(choose, "3") == 0)
		{
			InputBox(done, 100, "请输入修改后的性别");
			char p[] = "C:\\ticket_booking_INF\\BOSS\\boss_INF.txt";
			changeLine(p, 2, done);//p文件，第一行，改成done[]
			break;
		}
		else if (strcmp(choose, "4") == 0)
		{
			InputBox(done, 100, "请输入修改后的收入");
			char p[] = "C:\\ticket_booking_INF\\BOSS\\boss_INF.txt";
			changeLine(p, 3, done);//p文件，第一行，改成done[]
			break;
		}
		else
		{
			char a[10];
			InputBox(a, 10, "请按照正确输入OK？");
		}
	}

}
void put_boss_INF()
{
	clearrectangle(500, 0, 1000, 600);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("修改信息"), &R_boss_INF_change, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	ifstream infile;
	infile.open("C:\\ticket_booking_INF\\BOSS\\boss_INF.txt", ios::in);
	string temp;
	if (infile.good())
	{
		int i = 450;
		while (!infile.eof())
		{
			getline(infile, temp, '\n');
			char p[100];
			int j;
			for (j = 0; j < temp.length(); j++)
				p[j] = temp[j];//转字符数组
			p[j] = '\0';//防止烫烫烫
			RECT r = { 700,i,500,100 };
			drawtext(_T(p), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			i += 100;

		}
	}
}
void copyTxt(char srcFilename[], char dstFilename[])
{
	ifstream infile;
	ofstream outfile;
	string temp;
	infile.open(srcFilename, ios::in);
	outfile.open(dstFilename, ios::trunc | ios::out);
	if (infile.good())
	{
		while (!infile.eof())
		{
			getline(infile, temp, '\n');
			outfile << temp << '\n';
		}
	}
	infile.close();
	outfile.close();

}
int CountLines(string filename)//得到TXT文件的总行数
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename.c_str());//ios::in 表示以只读的方式读取文件
	if (ReadFile.fail())//文件打开失败:返回0
	{
		return 0;
	}
	else//文件存在
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			n++;
		}
		ReadFile.close();
		return n;
	}
}

string ReadLine(string filename, int line)//读出指定行内容
{
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(filename.c_str());
	lines = CountLines(filename);

	if (line <= 0)
	{
		return "Erro1";
	}
	if (file.fail())
	{
		return "Erro2";
	}
	if (line > lines)
	{
		return "Error3";
	}
	while (getline(file, temp) && i < line - 1)
	{
		i++;
	}
	file.close();
	return temp;
}
void changeLine(char file[], int line, char change_tag[])//修改特定行
{

	char temp[100] = "C:\\ticket_booking_INF\\temp.txt";
	int i = 1;
	ofstream wfile;
	string str;
	ifstream rfile;
	copyTxt(file, temp);
	wfile.open(file, ios::out | ios::trunc);
	rfile.open(temp, ios::in);
	int count = CountLines(temp);//总行数
	do
	{
		if (i == line)
		{
			for (int j = 0; j < strlen(change_tag); j++)
			{
				wfile << change_tag[j];
			}
			wfile << endl;
			getline(rfile, str, '\n');
		}
		else
		{
			getline(rfile, str, '\n');
			wfile << str << endl;
		}

		i++;
	} while (--count);
	wfile.close();
	rfile.close();
}

string Readtxt(string filename, int line)
{
	//line行数限制 1 - lines
	ifstream text;
	text.open(filename, ios::in);
	int i = 0;
	string strVec;
	while (!text.eof())
	{
		i++;
		if (i == line)
		{
			getline(text, strVec, '\n');
			break;
		}
		string inbuf;
		getline(text, inbuf, '\n');

	}
	return strVec;
}
void manage_Worker()
{
	loadimage(&all_job, "C:\\ticket_booking_photo\\all_job.png", all_width, all_height);
	putimage(0, 0, &all_job);

	put_worker_INF();

	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &Boss_face_background);
			drawtext(_T("老板个人信息"), &R_INF_boss, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("管理员工"), &R_INF_worker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			worker_change_INF();
			put_worker_INF();

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 200 && n.y <= 250 && n.uMsg == WM_LBUTTONDOWN)
		{
			add_worker();
			put_worker_INF();

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 300 && n.y <= 350 && n.uMsg == WM_LBUTTONDOWN)
		{
			delete_worker();
			put_worker_INF();

		}
	}
}
void put_worker_INF()
{
	clearrectangle(300, 0, 1000, 600);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("修改员工信息"), &R_worker_INF_change, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("增加员工"), &R_add_worker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("减少员工"), &R_del_worker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	int high = 50;
	for (int i = 0; i < worker_num; i++)
	{
		if (a[i].if_del() == 0)
		{
			RECT r = { 650,high,50,50 };
			RECT e = { 750,high,50,50 };
			RECT c = { 850,high,50,50 };
			RECT t = { 950,high,50,50 };
			RECT k = { 1050,high,50,50 };
			drawtext(_T(a[i].show_id()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(a[i].show_password()), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(a[i].show_income()), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(a[i].show_name()), &t, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(a[i].show_sex()), &k, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			high += 50;
		}
	}
}
void worker_change_INF()
{
	int if_find = 0;
	char worker_id[100];
	InputBox(worker_id, 10, "请输入您要修改的员工ID");
	char _tail[10] = ".txt";
	char worker_id_f[100];
	strcpy(worker_id_f, worker_id);
	strcat(worker_id_f, _tail);
	char p[100] = "C:\\ticket_booking_INF\\Worker\\";
	strcat(p, worker_id_f);//绝对位置
	int find = 0;
	for (int i = 0; i < worker_num; i++)
	{

		if (strcmp(worker_id, a[i].show_id()) == 0)
		{
			find = 1;
			while (1)
			{
				char choose[10];
				InputBox(choose, 10, "请输入要修改的内容：1.账号，2.密码，3.收入");
				if (strcmp(choose, "1") == 0)
				{
					char id_c[100];
					InputBox(id_c, 100, "请输入修改后的id");
					changeLine(p, 1, id_c);
					a[i].getID(id_c);
					char p2[100] = "C:\\ticket_booking_INF\\Worker\\";
					char id_c_p[100];
					strcpy(id_c_p, id_c);
					strcat(id_c_p, _tail);//2022.txt
					strcat(p2, id_c_p);//绝对位置
					rename(p, p2);//重命名
					break;
				}
				else if (strcmp(choose, "1") == 0)
				{
					char p_c[100];
					InputBox(p_c, 100, "请输入修改后的密码");
					changeLine(p, 2, p_c);
					a[i].get_password(p_c);
					break;
				}
				else if (strcmp(choose, "3") == 0)
				{
					char income_c[100];
					InputBox(income_c, 100, "请输入修改后的收入");
					changeLine(p, 3, income_c);
					a[i].get_income(income_c);
					break;
				}
				else {
					char s[10];
					InputBox(s, 10, "请正确输入...");
				}

			}
		}
	}
	if (find == 0)
	{
		char s[10];
		InputBox(s, 10, "未找到...");
	}
}
void add_worker()
{
	char add_id[100];
	char add_password[100];
	char add_income[100];
	char add_name[100];
	char add_sex[100];
	InputBox(add_id, 100, "请输入新添加员工账号id");
	InputBox(add_password, 100, "请输入新添加员工密码");
	InputBox(add_income, 100, "请输入新添加员工收入");
	InputBox(add_name, 100, "请输入新添加员工名字");
	InputBox(add_sex, 100, "请输入新添加成员性别");
	a[worker_num].getID(add_id);
	a[worker_num].get_password(add_password);
	a[worker_num].get_income(add_income);
	a[worker_num].get_name(add_name);
	a[worker_num].get_sex(add_sex);
	char path[100] = "C:\\ticket_booking_INF\\Worker\\";
	char _tail[10] = ".txt";
	char add_id_p[100];
	strcpy(add_id_p, add_id);
	strcat(add_id_p, _tail);
	strcat(path, add_id_p);

	ofstream file(path, ios::_Noreplace);
	file << add_id << endl;
	file << add_password << endl;
	file << add_income << endl;
	file << add_name << endl;
	file << add_sex << endl;
	worker_num++;
}
void delete_worker()
{
	char tag_id[100];
	InputBox(tag_id, 100, "请输入要删除的员工账号");
	int find = 0;
	for (int i = 0; i < worker_num; i++)
	{
		if (strcmp(a[i].show_id(), tag_id) == 0)
		{
			find = 1;
			char path[100] = "C:\\ticket_booking_INF\\Worker\\";
			char _tail[10] = ".txt";
			char tag_p[100];
			strcpy(tag_p, tag_id);
			strcat(tag_p, _tail);
			strcat(path, tag_p);
			remove(path);//删除
			a[i].del_it();

		}
	}
	if (find == 0)
	{
		char s[10];
		InputBox(s, 10, "未找到...");
	}
}
void Worker_face(int i)
{
	loadimage(&Worker_face_background, "C:\\ticket_booking_photo\\worker_class.png", all_width, all_height);
	putimage(0, 0, &Worker_face_background);
	drawtext(_T("员工个人信息"), &R_INF_worker_own, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("管理航班"), &R_worker_flight, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &imag_background);
			drawtext(_T("老板"), &Rboss, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("员工"), &Rworker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("用户"), &Ruser, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			show_worker_own_INF(i);
		}

		else if (n.x >= 750 && n.x <= 850 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			worker_flight();
		}

	}
}
void show_worker_own_INF(int i)
{
	loadimage(&all_job, "C:\\ticket_booking_photo\\all_job.png", all_width, all_height);
	putimage(0, 0, &all_job);
	clearrectangle(500, 0, 1000, 600);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("修改信息"), &R_worker_INF_change, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	int high = 400;
	RECT r = { 1050,high,50,50 };
	RECT e = { 1150,high,50,50 };
	RECT c = { 1250,high,50,50 };
	RECT t = { 1350,high,50,50 };
	RECT k = { 1450,high,50,50 };
	drawtext(_T(a[i].show_id()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T(a[i].show_password()), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T(a[i].show_income()), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T(a[i].show_name()), &t, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T(a[i].show_sex()), &k, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &Worker_face_background);
			drawtext(_T("员工个人信息"), &R_INF_worker_own, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("管理航班"), &R_worker_flight, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			worker_INF_change_own(i);
			clearrectangle(500, 0, 1000, 600);
			RECT r = { 1050,high,50,50 };
			RECT e = { 1150,high,50,50 };
			RECT c = { 1250,high,50,50 };
			RECT t = { 1350,high,50,50 };
			RECT k = { 1450,high,50,50 };
			drawtext(_T(a[i].show_id()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(a[i].show_password()), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(a[i].show_income()), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(a[i].show_name()), &t, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(a[i].show_sex()), &k, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}

	}
}
void worker_INF_change_own(int i)
{
	char tag_id[100];
	strcpy(tag_id, a[i].show_id());
	char _tail[100] = ".txt";
	char w_path[100] = "C:\\ticket_booking_INF\\Worker\\";
	char tag_id_path[100];
	strcpy(tag_id_path, tag_id);
	strcat(tag_id_path, _tail);
	strcat(w_path, tag_id_path);//找到了绝对路径
	char choose[10];
	char done[100];
	while (1)
	{
		InputBox(choose, 10, "请输入你要修改的内容:1.姓名 2.性别 ");
		if (strcmp(choose, "1") == 0)
		{
			InputBox(done, 100, "请输入修改后的姓名");
			changeLine(w_path, 4, done);
			a[i].get_name(done);
			break;

		}
		else if (strcmp(choose, "2") == 0)
		{
			InputBox(done, 100, "请输入修改后的性别");
			changeLine(w_path, 5, done);//p文件，第一行，改成done[]
			a[i].get_sex(done);
			break;
		}
		else
		{
			char a[10];
			InputBox(a, 10, "请按照正确输入OK？");
		}
	}
}
void worker_flight()
{
	loadimage(&all_job, "C:\\ticket_booking_photo\\all_job.png", all_width, all_height);
	putimage(0, 0, &all_job);

	show_flight();

	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &Worker_face_background);
			drawtext(_T("员工个人信息"), &R_INF_worker_own, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("管理航班"), &R_worker_flight, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			add_flight();
			show_flight();

		}
		else if (n.x >= 450 && n.x <= 550 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			del_flight();
			show_flight();
		}
		else if (n.x >= 750 && n.x <= 850 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{

			change_flight();
			show_flight();
		}
	}
}
void show_flight()
{
	clearrectangle(0, 0, 1000, 600);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("增加航班"), &R_add_fly, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("去除航班"), &R_del_fly, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("修改航班信息"), &R_change_fly, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	int high = 200;
	RECT m1 = { 0,150,50,50 };
	RECT r1 = { 100,150,50,50 };
	RECT e1 = { 200,150,50,50 };
	RECT q1 = { 400,150,50,50 };
	RECT t1 = { 600,150,50,50 };
	RECT k1 = { 900,150,50,50 };
	RECT z1 = { 1000,150,50,50 };
	RECT p1 = { 1100,150,50,50 };
	RECT o1 = { 1200,150,50,50 };
	RECT u1 = { 1300,150,50,50 };
	RECT y1 = { 1400,150,50,50 };
	RECT l1 = { 1500,150,50,50 };
	RECT n1 = { 1600,150,50,50 };
	RECT b1 = { 1700,150,50,50 };
	drawtext(_T("id"), &m1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("begin"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("to"), &e1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("B_time"), &q1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("E_time"), &t1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("first"), &k1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("second"), &z1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("third"), &p1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("F_price"), &o1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("S_price"), &u1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("T_price"), &y1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	/*drawtext(_T("F_num"), &l1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("S_num"), &n1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("T_num"), &b1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);*/
	for (int i = 0; i < flight_num; i++)
	{
		if (c[i].get_del() == 0)
		{

			RECT m = { 0,high,50,50 };
			RECT r = { 100,high,50,50 };
			RECT e = { 200,high,50,50 };
			RECT q = { 400,high,50,50 };
			RECT t = { 600,high,50,50 };
			RECT k = { 900,high,50,50 };
			RECT z = { 1000,high,50,50 };
			RECT p = { 1100,high,50,50 };
			RECT o = { 1200,high,50,50 };
			RECT u = { 1300,high,50,50 };
			RECT y = { 1400,high,50,50 };
			RECT l = { 1500,high,50,50 };
			RECT n = { 1600,high,50,50 };
			RECT b = { 1700,high,50,50 };

			drawtext(_T(c[i].show_id()), &m, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_pb()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_pe()), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_tb()), &q, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_te()), &t, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_fn()), &k, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_sn()), &z, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_tn()), &p, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_fp()), &o, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_sp()), &u, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_tp()), &y, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			/*drawtext(_T(c[i].show_fre()), &l, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_sre()), &n, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_tre()), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);*/
			high += 50;
		}
	}
}
void add_flight()
{
	char tag_id[100];
	InputBox(tag_id, 100, "请输入航班号");
	char tag_pb[100];
	InputBox(tag_pb, 100, "请输入起始地");
	char tag_pe[100];
	InputBox(tag_pe, 100, "请输入终点地");
	char tag_tb[100];
	InputBox(tag_tb, 100, "请输入起始时间");
	char tag_te[100];
	InputBox(tag_te, 100, "请输入到达时间");
	char tag_fn[10];
	InputBox(tag_fn, 10, "请输入一等舱数");
	char tag_sn[10];
	InputBox(tag_sn, 10, "请输入二等舱数");
	char tag_tn[10];
	InputBox(tag_tn, 10, "请输入三等舱数");
	char tag_fp[10];
	InputBox(tag_fp, 10, "请输入一等舱票价");
	char tag_sp[10];
	InputBox(tag_sp, 10, "请输入二等舱票价");
	char tag_tp[10];
	InputBox(tag_tp, 10, "请输入三等舱票价");
	char tag_frn[10];
	strcpy(tag_frn, tag_fn);
	//InputBox(tag_frn, 10, "请输入一等舱剩余数");
	char tag_srn[10];
	strcpy(tag_srn, tag_sn);
	//InputBox(tag_srn, 10, "请输入二等舱剩余数");
	char tag_trn[10];
	strcpy(tag_srn, tag_sn);
	//InputBox(tag_trn, 10, "请输入三等舱剩余数");
	Flight new_one(tag_id, tag_pb, tag_pe, tag_tb, tag_te, tag_fn, tag_sn, tag_tn, tag_fp, tag_sp, tag_tp, tag_frn, tag_srn, tag_trn);
	c[flight_num] = new_one;
	flight_num++;
	char path[100] = "C:\\ticket_booking_INF\\Flight\\";
	char _tail[10] = ".txt";
	char add_id_p[100];
	strcpy(add_id_p, tag_id);
	strcat(add_id_p, _tail);
	strcat(path, add_id_p);
	ofstream file(path, ios::_Noreplace);
	file << tag_id << endl;
	file << tag_pb << endl;
	file << tag_pe << endl;
	file << tag_tb << endl;
	file << tag_te << endl;
	file << tag_fn << endl;
	file << tag_sn << endl;
	file << tag_tn << endl;
	file << tag_fp << endl;
	file << tag_sp << endl;
	file << tag_tp << endl;
	file << tag_frn << endl;
	file << tag_srn << endl;
	file << tag_trn << endl;
}
void add_boat()
{
	char tag_id[100];
	InputBox(tag_id, 100, "请输入航班号");
	char tag_pb[100];
	InputBox(tag_pb, 100, "请输入起始地");
	char tag_pe[100];
	InputBox(tag_pe, 100, "请输入终点地");
	char tag_tb[100];
	InputBox(tag_tb, 100, "请输入起始时间");
	char tag_te[100];
	InputBox(tag_te, 100, "请输入到达时间");
	char tag_fn[10];
	InputBox(tag_fn, 10, "请输入一等舱数");
	char tag_sn[10];
	InputBox(tag_sn, 10, "请输入二等舱数");
	char tag_tn[10];
	InputBox(tag_tn, 10, "请输入三等舱数");
	char tag_fp[10];
	InputBox(tag_fp, 10, "请输入一等舱票价");
	char tag_sp[10];
	InputBox(tag_sp, 10, "请输入二等舱票价");
	char tag_tp[10];
	InputBox(tag_tp, 10, "请输入三等舱票价");
	char tag_frn[10];
	strcpy(tag_frn, tag_fn);
	//InputBox(tag_frn, 10, "请输入一等舱剩余数");
	char tag_srn[10];
	strcpy(tag_srn, tag_sn);
	//InputBox(tag_srn, 10, "请输入二等舱剩余数");
	char tag_trn[10];
	strcpy(tag_srn, tag_sn);
	//InputBox(tag_trn, 10, "请输入三等舱剩余数");
	Boat new_one(tag_id, tag_pb, tag_pe, tag_tb, tag_te, tag_fn, tag_sn, tag_tn, tag_fp, tag_sp, tag_tp, tag_frn, tag_srn, tag_trn);
	d[boat_num] = new_one;
	boat_num++;
	char path[100] = "C:\\ticket_booking_INF\\Boat\\";
	char _tail[10] = ".txt";
	char add_id_p[100];
	strcpy(add_id_p, tag_id);
	strcat(add_id_p, _tail);
	strcat(path, add_id_p);
	ofstream file(path, ios::_Noreplace);
	file << tag_id << endl;
	file << tag_pb << endl;
	file << tag_pe << endl;
	file << tag_tb << endl;
	file << tag_te << endl;
	file << tag_fn << endl;
	file << tag_sn << endl;
	file << tag_tn << endl;
	file << tag_fp << endl;
	file << tag_sp << endl;
	file << tag_tp << endl;
	file << tag_frn << endl;
	file << tag_srn << endl;
	file << tag_trn << endl;
}
void del_flight()
{
	int find = 0;
	char tag_id[100];
	InputBox(tag_id, 100, "请输入要删除的航班号");
	char path[100] = "C:\\ticket_booking_INF\\Flight\\";
	char _tail[10] = ".txt";
	char del_id_p[100];
	strcpy(del_id_p, tag_id);
	strcat(del_id_p, _tail);
	strcat(path, del_id_p);
	for (int i = 0; i < flight_num; i++)
	{
		if (strcmp(c[i].show_id(), tag_id) == 0)
		{
			find = 1;
			c[i].if_del();
			remove(path);
			break;
		}
	}
	if (find == 0)
	{
		char s[100];
		InputBox(s, 100, "未找到...");
	}
}
void del_boat()
{
	int find = 0;
	char tag_id[100];
	InputBox(tag_id, 100, "请输入要删除的航班号");
	char path[100] = "C:\\ticket_booking_INF\\Boat\\";
	char _tail[10] = ".txt";
	char del_id_p[100];
	strcpy(del_id_p, tag_id);
	strcat(del_id_p, _tail);
	strcat(path, del_id_p);
	for (int i = 0; i < boat_num; i++)
	{
		if (strcmp(d[i].show_id(), tag_id) == 0)
		{
			find = 1;
			d[i].if_del();
			remove(path);
			break;
		}
	}
	if (find == 0)
	{
		char s[100];
		InputBox(s, 100, "未找到...");
	}
}
void change_flight()
{
	char tag_id[100];
	InputBox(tag_id, 100, "请输入要修改的航班号");
	int find = 0;
	for (int i = 0; i < flight_num; i++)
	{
		if (strcmp(tag_id, c[i].show_id()) == 0)
		{
			find = 1;
			char choose1[10];
			InputBox(choose1, 10, "请输入要修改的内容:1.id 2.地点 3.时间 4.票数 5.单价");
			if (strcmp(choose1, "1") == 0)
			{
				char id_h[100];
				InputBox(id_h, 100, "请输入修改后的id");
				c[i].get_id(id_h);
				char path[100] = "C:\\ticket_booking_INF\\Flight\\";
				char _tail[10] = ".txt";
				char id_p[100];
				strcpy(id_p, tag_id);
				strcat(id_p, _tail);
				strcat(path, id_p);
				char path2[100] = "C:\\ticket_booking_INF\\Flight\\";
				char id_p2[100];
				strcpy(id_p2, id_h);
				strcat(id_p2, _tail);
				strcat(path2, id_p2);
				rename(path, path2);
			}
			else if (strcmp(choose1, "2") == 0)
			{
				char choose2[10];
				InputBox(choose2, 10, "请输入要修改的具体内容：1.起始地 2.终点地");
				if (strcmp(choose2, "1") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的起始地");
					c[i].get_pb(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 2, done);
				}
				else if (strcmp(choose2, "2") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的终点地");
					c[i].get_pe(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 3, done);
				}
			}
			else if (strcmp(choose1, "3") == 0)
			{
				char choose2[10];
				InputBox(choose2, 10, "请输入要修改的具体内容：1.起始时间 2.终点时间");
				if (strcmp(choose2, "1") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的起始时间");
					c[i].get_tb(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 4, done);
				}
				else if (strcmp(choose2, "2") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的到站时间");
					c[i].get_te(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 5, done);
				}
			}
			else if (strcmp(choose1, "4") == 0)
			{
				char choose2[10];
				InputBox(choose2, 10, "请输入要修改的具体内容：1.一等舱 2.二等舱 3.三等舱");
				if (strcmp(choose2, "1") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的一等舱票数");
					c[i].get_fn(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 6, done);
				}
				else if (strcmp(choose2, "2") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的二等舱票数");
					c[i].get_sn(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 7, done);
				}
				else if (strcmp(choose2, "3") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的三等舱票数");
					c[i].get_tn(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 8, done);
				}
			}
			else if (strcmp(choose1, "5") == 0)
			{
				char choose2[10];
				InputBox(choose2, 10, "请输入要修改的具体内容：1.一等舱 2.二等舱 3.三等舱");
				if (strcmp(choose2, "1") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的一等舱票数");
					c[i].get_fp(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 9, done);
				}
				else if (strcmp(choose2, "2") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的二等舱票数");
					c[i].get_sp(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 10, done);
				}
				else if (strcmp(choose2, "3") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的三等舱票数");
					c[i].get_tp(done);
					char path[100] = "C:\\ticket_booking_INF\\Flight\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 11, done);
				}
			}
		}
	}
	if (find == 0)
	{
		char s[100];
		InputBox(s, 100, "未找到...");
	}
}
void change_boat()
{
	char tag_id[100];
	InputBox(tag_id, 100, "请输入要修改的航班号");
	int find = 0;
	for (int i = 0; i < boat_num; i++)
	{
		if (strcmp(tag_id, d[i].show_id()) == 0)
		{
			find = 1;
			char choose1[10];
			InputBox(choose1, 10, "请输入要修改的内容:1.id 2.地点 3.时间 4.票数 5.单价");
			if (strcmp(choose1, "1") == 0)
			{
				char id_h[100];
				InputBox(id_h, 100, "请输入修改后的id");
				d[i].get_id(id_h);
				char path[100] = "C:\\ticket_booking_INF\\Boat\\";
				char _tail[10] = ".txt";
				char id_p[100];
				strcpy(id_p, tag_id);
				strcat(id_p, _tail);
				strcat(path, id_p);
				char path2[100] = "C:\\ticket_booking_INF\\Boat\\";
				char id_p2[100];
				strcpy(id_p2, id_h);
				strcat(id_p2, _tail);
				strcat(path2, id_p2);
				rename(path, path2);
			}
			else if (strcmp(choose1, "2") == 0)
			{
				char choose2[10];
				InputBox(choose2, 10, "请输入要修改的具体内容：1.起始地 2.终点地");
				if (strcmp(choose2, "1") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的起始地");
					d[i].get_pb(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 2, done);
				}
				else if (strcmp(choose2, "2") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的终点地");
					d[i].get_pe(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 3, done);
				}
			}
			else if (strcmp(choose1, "3") == 0)
			{
				char choose2[10];
				InputBox(choose2, 10, "请输入要修改的具体内容：1.起始时间 2.终点时间");
				if (strcmp(choose2, "1") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的起始时间");
					d[i].get_tb(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 4, done);
				}
				else if (strcmp(choose2, "2") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的到站时间");
					d[i].get_te(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 5, done);
				}
			}
			else if (strcmp(choose1, "4") == 0)
			{
				char choose2[10];
				InputBox(choose2, 10, "请输入要修改的具体内容：1.一等舱 2.二等舱 3.三等舱");
				if (strcmp(choose2, "1") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的一等舱票数");
					d[i].get_fn(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 6, done);
				}
				else if (strcmp(choose2, "2") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的二等舱票数");
					d[i].get_sn(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 7, done);
				}
				else if (strcmp(choose2, "3") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的三等舱票数");
					c[i].get_tn(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 8, done);
				}
			}
			else if (strcmp(choose1, "5") == 0)
			{
				char choose2[10];
				InputBox(choose2, 10, "请输入要修改的具体内容：1.一等舱 2.二等舱 3.三等舱");
				if (strcmp(choose2, "1") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的一等舱票数");
					d[i].get_fp(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 9, done);
				}
				else if (strcmp(choose2, "2") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的二等舱票数");
					d[i].get_sp(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 10, done);
				}
				else if (strcmp(choose2, "3") == 0)
				{
					char done[100];
					InputBox(done, 100, "请输入修改后的三等舱票数");
					d[i].get_tp(done);
					char path[100] = "C:\\ticket_booking_INF\\Boat\\";
					char _tail[10] = ".txt";
					char id_p[100];
					strcpy(id_p, tag_id);
					strcat(id_p, _tail);
					strcat(path, id_p);
					changeLine(path, 11, done);
				}
			}
		}
	}
	if (find == 0)
	{
		char s[100];
		InputBox(s, 100, "未找到...");
	}
}

int User_log()
{
	char tag_id[100];
	InputBox(tag_id, 100, "请输入用户账号");
	int find = 0;
	for (int i = 0; i < user_num; i++)
	{
		if (strcmp(b[i].show_id(), tag_id) == 0)
		{
			find = 1;
			char pd[100];
			InputBox(pd, 100, "请输入密码");
			if (strcmp(pd, b[i].show_pd()) == 0)
				return i + 1;//返回i+1是为了防止爆0
		}
	}
	if (find == 0)
	{
		char s[10];
		InputBox(s, 10, "未找到");
		return 0;
	}
}
int User_sign()
{
	char tag_id[100];
	InputBox(tag_id, 100, "请输入要创建的账号id");
	char password[100];
	InputBox(password, 100, "请输入密码");
	char name[100];
	InputBox(name, 100, "请输入姓名");
	char sex[100];
	InputBox(sex, 100, "请输入性别");
	b[user_num].get_id(tag_id);
	b[user_num].get_password(password);
	b[user_num].get_name(name);
	b[user_num].get_sex(sex);
	user_num++;
	char path[100] = "C:\\ticket_booking_INF\\User\\";
	char _tail[10] = ".txt";
	char add_id_p[100];
	strcpy(add_id_p, tag_id);
	strcat(add_id_p, _tail);
	strcat(path, add_id_p);
	ofstream file(path, ios::_Noreplace);
	file << tag_id << endl;
	file << password << endl;
	file << name << endl;
	file << sex << endl;

	char path2[100] = "C:\\ticket_booking_INF\\User_booking\\";
	strcat(path2, add_id_p);
	ofstream file2(path2, ios::_Noreplace);
	file2 << " " << endl;
	return user_num - 1;

}
void User_face(int i)
{
	loadimage(&User_face_background, "C:\\ticket_booking_photo\\user_class.png", all_width, all_height);
	putimage(0, 0, &User_face_background);
	drawtext(_T("用户个人信息"), &R_INF_user, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("订票平台"), &R_user_booking, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &imag_background);
			drawtext(_T("老板"), &Rboss, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("员工"), &Rworker, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("用户"), &Ruser, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			User_INF_show(i);
		}

		else if (n.x >= 750 && n.x <= 850 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			User_booking_show(i);
		}

	}
}
void put_user_INF(int i)
{
	int high = 400;
	clearrectangle(500, 0, 1000, 600);
	RECT r = { 1050,high,50,50 };
	RECT e = { 1150,high,50,50 };
	RECT c = { 1250,high,50,50 };
	RECT t = { 1350,high,50,50 };
	drawtext(_T(b[i].show_id()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T(b[i].show_pd()), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T(b[i].show_name()), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T(b[i].show_sex()), &t, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void User_INF_show(int i)
{
	loadimage(&all_job, "C:\\ticket_booking_photo\\all_job.png", all_width, all_height);
	putimage(0, 0, &all_job);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("修改信息"), &R_worker_INF_change, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	put_user_INF(i);
	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &User_face_background);
			drawtext(_T("用户个人信息"), &R_INF_user, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("订票平台"), &R_user_booking, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{
			User_INF_change(i);
			put_user_INF(i);
		}

	}
}
void User_INF_change(int i)
{
	char choose[10];
	InputBox(choose, 10, "请输入要修改的内容:1.id 2.密码 3.姓名 4.性别");
	if (strcmp(choose, "1") == 0)
	{
		char done[100];
		InputBox(done, 100, "请输入修改后的id");
		char p2[100] = "C:\\ticket_booking_INF\\User\\";
		char p[100] = "C:\\ticket_booking_INF\\User\\";
		char _tail[100] = ".txt";
		char id_c_p[100];
		strcpy(id_c_p, done);
		strcat(id_c_p, _tail);//2022.txt
		strcat(p2, id_c_p);//绝对位置
		char id0[100];
		strcpy(id0, b[i].show_id());
		strcat(id0, _tail);
		strcat(p, id0);
		changeLine(p, 1, done);
		rename(p, p2);//重命名
		char p3[100] = "C:\\ticket_booking_INF\\User_booking\\";
		char p4[100] = "C:\\ticket_booking_INF\\User_booking\\";
		strcat(p4, id_c_p);//绝对位置
		strcat(p3, id0);//绝对位置
		rename(p3, p4);

		b[i].get_id(done);
	}
	else if (strcmp(choose, "2") == 0)
	{
		char done[100];
		InputBox(done, 100, "请输入修改后的密码");
		b[i].get_password(done);
		char p[100] = "C:\\ticket_booking_INF\\User\\";
		char _tail[100] = ".txt";
		char id_c_p[100];
		strcpy(id_c_p, b[i].show_id());
		strcat(id_c_p, _tail);
		strcat(p, id_c_p);
		changeLine(p, 2, done);
	}
	else if (strcmp(choose, "3") == 0)
	{
		char done[100];
		InputBox(done, 100, "请输入修改后的姓名");
		b[i].get_name(done);
		char p[100] = "C:\\ticket_booking_INF\\User\\";
		char _tail[100] = ".txt";
		char id_c_p[100];
		strcpy(id_c_p, b[i].show_id());
		strcat(id_c_p, _tail);
		strcat(p, id_c_p);
		changeLine(p, 3, done);
	}
	else if (strcmp(choose, "4") == 0)
	{
		char done[100];
		InputBox(done, 100, "请输入修改后的性别");
		b[i].get_sex(done);
		char p[100] = "C:\\ticket_booking_INF\\User\\";
		char _tail[100] = ".txt";
		char id_c_p[100];
		strcpy(id_c_p, b[i].show_id());
		strcat(id_c_p, _tail);
		strcat(p, id_c_p);
		changeLine(p, 4, done);
	}
}
void User_booking_show(int i)
{

	show_flight_user();
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	while (1) {
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			putimage(0, 0, &User_face_background);
			drawtext(_T("用户个人信息"), &R_INF_user, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("订票平台"), &R_user_booking, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
		else if (n.x >= 150 && n.x <= 250 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{

			booking_add(i);


		}
		else if (n.x >= 750 && n.x <= 850 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{

			booking_del(i);

		}
		else if (n.x >= 450 && n.x <= 550 && n.y >= 400 && n.y <= 450 && n.uMsg == WM_LBUTTONDOWN)
		{


			my_booking(i);
		}
	}
}
void show_flight_user()
{
	clearrectangle(0, 0, 1000, 600);
	drawtext(_T("选票"), &R_booking_add, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("退票"), &R_booking_del, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("我的订票"), &R_my_booking, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	int high = 200;
	RECT m1 = { 0,150,50,50 };
	RECT r1 = { 100,150,50,50 };
	RECT e1 = { 200,150,50,50 };
	RECT q1 = { 400,150,50,50 };
	RECT t1 = { 600,150,50,50 };
	RECT k1 = { 900,150,50,50 };
	RECT z1 = { 1000,150,50,50 };
	RECT p1 = { 1100,150,50,50 };
	RECT o1 = { 1200,150,50,50 };
	RECT u1 = { 1300,150,50,50 };
	RECT y1 = { 1400,150,50,50 };
	RECT l1 = { 1500,150,50,50 };
	RECT n1 = { 1600,150,50,50 };
	RECT b1 = { 1700,150,50,50 };
	drawtext(_T("id"), &m1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("begin"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("to"), &e1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("B_time"), &q1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("E_time"), &t1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("first"), &k1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("second"), &z1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("third"), &p1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("F_price"), &o1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("S_price"), &u1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("T_price"), &y1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	/*drawtext(_T("F_num"), &l1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("S_num"), &n1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("T_num"), &b1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);*/
	for (int i = 0; i < flight_num; i++)
	{
		if (c[i].get_del() == 0)
		{

			RECT m = { 0,high,50,50 };
			RECT r = { 100,high,50,50 };
			RECT e = { 200,high,50,50 };
			RECT q = { 400,high,50,50 };
			RECT t = { 600,high,50,50 };
			RECT k = { 900,high,50,50 };
			RECT z = { 1000,high,50,50 };
			RECT p = { 1100,high,50,50 };
			RECT o = { 1200,high,50,50 };
			RECT u = { 1300,high,50,50 };
			RECT y = { 1400,high,50,50 };
			RECT l = { 1500,high,50,50 };
			RECT n = { 1600,high,50,50 };
			RECT b = { 1700,high,50,50 };

			drawtext(_T(c[i].show_id()), &m, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_pb()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_pe()), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_tb()), &q, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_te()), &t, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_fn()), &k, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_sn()), &z, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_tn()), &p, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_fp()), &o, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_sp()), &u, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T(c[i].show_tp()), &y, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			high += 50;
		}
	}
}
void booking_add(int i)
{
	char tag_id[100];
	InputBox(tag_id, 100, "请输入要订购的航班号");
	char tag_t[10];
	InputBox(tag_t, 10, "请输入要订购的舱号：1.一等舱 2.二等舱 3.三等舱");
	char tag_n[10];
	InputBox(tag_n, 10, "请输入要订购的票数");
	b[i].get_booking(tag_id, tag_n);
	char p[100] = "C:\\ticket_booking_INF\\User_booking\\";
	char _tail[100] = ".txt";
	char id_c_p[100];
	strcpy(id_c_p, b[i].show_id());
	strcat(id_c_p, _tail);
	strcat(p, id_c_p);
	ofstream file(p, ios::app);
	file << tag_id << endl;
	file << tag_n << endl;
	file.close();
}
void booking_del(int i)
{
	char id[100];
	strcpy(id, b[i].show_id());
	char p[100] = "C:\\ticket_booking_INF\\User_booking\\";
	char _tail[10] = ".txt";
	strcat(id, _tail);
	strcat(p, id);
	ifstream file(p, ios::in);
	string s;
	int cout = 1;
	char del_id[100];
	InputBox(del_id, 100, "请输入要退订的航班号");
	while (getline(file, s))
	{
		if (strcmp(s.c_str(), del_id) == 0)
		{
			break;
		}
		cout++;
	}
	file.close();
	booking_del_it(p, cout);

}
void booking_del_it(char file[], int line)
{
	char temp[100] = "C:\\ticket_booking_INF\\temp.txt";
	int i = 1;
	ofstream wfile;
	string str;
	ifstream rfile;
	copyTxt(file, temp);
	wfile.open(file, ios::out | ios::trunc);
	rfile.open(temp, ios::in);
	int count = CountLines(temp);//总行数
	do
	{
		if (i == line)
		{
			getline(rfile, str, '\n');
			getline(rfile, str, '\n');
		}
		else
		{
			getline(rfile, str, '\n');
			wfile << str << endl;
		}

		i++;
	} while (--count);
	wfile.close();
	rfile.close();
}
void my_booking(int i)
{
	clearrectangle(0, 0, 1000, 600);
	drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	ifstream file4("C:\\ticket_booking_INF\\user_id.txt", ios::in);
	string m;
	int j = 0;
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
			if (n.size() != 0)//防止空行
			{
				char id[100], num[10];
				strcpy(id, n.c_str());
				getline(file5, n);
				strcpy(num, n.c_str());
				b[j].get_booking(id, num);
			}

		}
		file5.close();
		j++;
		/*	user_num++;*/ // 因为已经增加过一次了
	}
	char id[100];
	strcpy(id, b[i].show_id());
	char p[100] = "C:\\ticket_booking_INF\\User_booking\\";
	char _tail[10] = ".txt";
	strcat(id, _tail);
	strcat(p, id);
	string s;
	ifstream file2(p, ios::in);
	int high = 100;
	while (getline(file2, s))
	{
		if (s.size() != 0)
		{
			RECT r = { 300,high,100,50 };
			RECT e = { 400,high,100,50 };
			drawtext(_T(s.c_str()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			getline(file2, s);
			drawtext(_T(s.c_str()), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			high += 100;
		}
	}

	while (1)
	{
		MOUSEMSG n;
		n = GetMouseMsg();
		if (n.x > 50 && n.x < 150 && n.y>40 && n.y < 90 && n.uMsg == WM_LBUTTONDOWN)
		{
			setbkmode(TRANSPARENT);//透明字体;
			settextcolor(WHITE);//颜色
			show_flight_user();
			drawtext(_T("返回"), &Rreturn, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("选票"), &R_booking_add, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("退票"), &R_booking_del, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			drawtext(_T("我的订票"), &R_my_booking, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			break;

		}
	}
}

