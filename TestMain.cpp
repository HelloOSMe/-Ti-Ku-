#include<bits/stdc++.h>
#include<unistd.h>
#include<windows.h>
#include<conio.h>
#define cls system("cls")
#define Utc 8
#define GT_YEA 0x000000
#define GT_MON 0x000001
#define GT_DAY 0x000002
#define GT_HOU 0x000003
#define GT_MIN 0x000004
#define GT_SEC 0x000005
using namespace std;
int fenshu=0;
bool ti15=0;
string name;
ofstream fout;
ifstream fin;
ofstream fdat;
void GotoXY(SHORT x,SHORT y){
	COORD pos={x,y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}
void hideCursor(){
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = 0;
	cursor.dwSize = 1;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hOut, &cursor);
}
void clp(auto output,int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
	cout<<output;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
int GetTimes(int lei){
	time_t now_time;
	now_time = time(NULL);
	tm* timer=gmtime(&now_time);
	if(lei==0){
		return 1900+timer->tm_year;
	}else if(lei==1){
		return 1+timer->tm_mon;
	}else if(lei==2){
		return timer->tm_mday;
	}else if(lei==3){
		return timer->tm_hour+Utc;
	}else if(lei==4){
		return timer->tm_min;
	}else if(lei==5){
		return timer->tm_sec;
	}else{
		return now_time;
	}
}
void start(){
	clp("        气象学题库系统-单机版        \n",15*16);
	clp("-------------------------------------\n",15*16);
	clp("                                     \n",15*16);
	clp("      Copyright (c) 2022 HelloOS     \n",15*16+3);
	clp("                                     \n",15*16);
	clp("         Build by Cplusplus          \n",15*16+12);
	clp("                                     \n",15*16);
	clp("-------------------------------------\n",15*16);
	cout<<"      ";
	clp(" [S] 开始 ",3*16+15);
	cout<<"     ";
	clp(" [E] 退出 ",7*16);
	cout<<endl;
	while(true){
		char ch=getch();
		if(ch=='S'||ch=='s'||ch=='\r'||ch=='\n'){
			return;
		}else if(ch=='e'||ch=='E'){
			exit(0);
		}
	}
}
void get_ti(int hang){
	string str;
	int num=0;
	while(getline(fin,str)&&num<hang){
		num++;
	}
	int i=str.size();
	clp(str,15*16);
	while(i<=36){
		clp(' ',15*16);
		i++;
	}
	cout<<endl;
	clp("-------------------------------------",15*16);
	cout<<endl;
}
void get_xuanxiang(int hang,char choose){
	string str;
	int num=0;
	while(getline(fin,str)&&num<hang){
		num++;
	}
	int i;
	clp("[",3*16);clp(choose,3*16);clp("]",3*16);
	for(i=0;i<str.size();i++){
		clp(str[i],15*16);
		if(i==33){
			cout<<endl;
		}
	}
	while(i<=33){
		clp(' ',15*16);
		i++;
	}
	cout<<endl;
	clp("                                     ",7*16);
	cout<<endl;
}
char get_ans(int hang){
	int n;
	int num=0;
	while(num<=hang){
		fin>>n;
		//cout<<n;
		num++;
	}
	return (char)('a'+n-1);
}
void get_choose_correct(int hang,char choose,bool correct){
	string str;
	int num=0,colors;
	if(correct){
		colors=160;
	}else{
		colors=4*16+15;
	}
	while(getline(fin,str)&&num<hang){
		num++;
	}
	int i;
	clp("[",6*16);clp(choose,6*16);clp("]",6*16);
	for(i=0;i<str.size();i++){
		clp(str[i],colors);
		if(i==33){
			cout<<endl;
		}
	}
	while(i<=33){
		clp(' ',colors);
		i++;
	}
}
void Err_Save(int hang,char myans){
	fin.open("./Test1/ti.txt");
	string str;
	int num=0;
	while(getline(fin,str)&&num<hang){
		num++;
	}
	if(hang<=50){
		fout<<"行数：./原题/文件1.xlsx  "<<hang+2<<endl;
	}else{
		fout<<"行数：./原题/文件2.xlsx  "<<hang+2-50<<endl;
	}
	fout<<str<<endl;
	fin.close();
	fin.open("./Test1/choose1.txt");
	num=0;
	while(getline(fin,str)&&num<hang){
		num++;
	}
	fout<<"[A]"<<str<<endl;
	fin.close();
	fin.open("./Test1/choose2.txt");
	num=0;
	while(getline(fin,str)&&num<hang){
		num++;
	}
	fout<<"[B]"<<str<<endl;
	fin.close();
	fin.open("./Test1/choose3.txt");
	num=0;
	while(getline(fin,str)&&num<hang){
		num++;
	}
	fout<<"[C]"<<str<<endl;
	fin.close();
	fin.open("./Test1/choose4.txt");
	num=0;
	while(getline(fin,str)&&num<hang){
		num++;
	}
	fout<<"[D]"<<str<<endl;
	fin.close();
	fin.open("./Test1/ans.txt");
	num=0;
	int n;
	while(num<=hang){
		fin>>n;
		num++;
	}
	fout<<"正确答案:"<<(char)('A'+n-1)<<endl;
	fout<<"我的答案:"<<(char)(myans-32)<<endl;
	fin.close();
	fout<<"----------------------------------------"<<endl;
}
bool check(int hang,int hao){
	cout<<"题号:";
	clp(hao,11*16);
	cout<<endl;
	fin.open("./Test1/ti.txt");
	get_ti(hang);
	fin.close();
	fin.open("./Test1/choose1.txt");
	get_xuanxiang(hang,'A');
	fin.close();
	fin.open("./Test1/choose2.txt");
	get_xuanxiang(hang,'B');
	fin.close();
	fin.open("./Test1/choose3.txt");
	get_xuanxiang(hang,'C');
	fin.close();
	fin.open("./Test1/choose4.txt");
	get_xuanxiang(hang,'D');
	fin.close();
	fin.open("./Test1/ans.txt");
	char ch_ans=get_ans(hang);
	fin.close();
	char ch,filename[50];
	while(1){
		ch=getch();
		if(ch>='A'&&ch<='Z'){
			ch+=32;
		}
		if(ch=='e'){
			int an=MessageBox(GetForegroundWindow(),"                结束测试？                ","评测系统-单机版 v1.0.0",MB_YESNO);
			if(an==IDYES){
				exit(0);
			}
		}
		if(ch>='a'&&ch<='d'){
			if(ch_ans==ch){
				GotoXY(0,1+(ch_ans-'a'+1)*2);
				sprintf(filename,"./Test1/choose%d.txt",(ch_ans-'a'+1));
				fin.open(filename);
				get_choose_correct(hang,ch_ans-32,1);
				fin.close();
				//system("pause");
				Sleep(700);
				cls;
				if(ti15){
					fenshu++;
				}
				return 1;
			}else{
				GotoXY(0,1+(ch-'a'+1)*2);
				sprintf(filename,"./Test1/choose%d.txt",(ch-'a'+1));
				fin.open(filename);
				get_choose_correct(hang,ch-32,0);
				fin.close();
				
				GotoXY(0,1+(ch_ans-'a'+1)*2);
				sprintf(filename,"./Test1/choose%d.txt",(ch_ans-'a'+1));
				fin.open(filename);
				get_choose_correct(hang,ch_ans-32,1);
				fin.close();
				
				Err_Save(hang,ch);
				//system("pause");
				Sleep(700);
				cls;
				return 0;
			}
		}
	}
	return 0;
}
void maketest(){
	srand(time(NULL));
	int tihao=1;
	clp("       测试类型       \n",15*16);
	clp(" [A]15道题 ",3*16+15);
	clp("[B]自由测试\n",7*16);
	while(1){
		char ch=getch();
		if(ch=='a'||ch=='A'||ch=='\r'||ch=='\n'){
			ti15=1;
			break;
		}else if(ch=='b'||ch=='B'){
			break;
		}
	}
	cls;
	while(1){
		int a=clock();
		int c=rand()%100;
		check(c,tihao);
		int b=clock();
		fdat<<(b-a)/1000<<"s finish.\n";
		if(c<=50){
			fdat<<"lines：./原题/文件1.xlsx  "<<c+2<<endl;
		}else{
			fdat<<"lines：./原题/文件2.xlsx  "<<c+2-50<<endl;
		}
		if((b-a)/1000<=10){
			fdat<<"Time : normal"<<endl;
		}else{
			fdat<<"Time : Time Limit Exceeded"<<endl;
		}
		fdat<<"--------------------"<<endl;
		if(tihao==15){
			if(ti15){
				exit(0);
			}
			int an=MessageBox(GetForegroundWindow(),"                继续测试？                ","评测系统-单机版 v1.0.0",MB_YESNO);
			if(an==IDNO){
				exit(0);
			}
		}
		tihao++;
	}
}
void outtime(){
	char timelog[100];
	fdat<<"=============================="<<endl;
	sprintf(timelog,"Date: %04d/%02d/%02d %02d:%02d:%02d",GetTimes(GT_YEA),GetTimes(GT_MON),GetTimes(GT_DAY),GetTimes(GT_HOU),GetTimes(GT_MIN),GetTimes(GT_SEC));
	fdat<<timelog<<endl;
	fdat<<"Run at: "<<getcwd(NULL,0)<<endl;
	fdat<<"Do some exercise:"<<endl;
}
int main(){
	SetConsoleTitle("评测系统-单机版 v1.0.0");
	hideCursor();
	start();
	fdat.open("check.log",ios::ate|ios::out|ios::app);
	outtime();
	cls;
	fout.open("ERR.txt");
	maketest();
	return 0;
}
