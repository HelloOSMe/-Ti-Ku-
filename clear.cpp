#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	ShowWindow(GetConsoleWindow(),SW_HIDE);
	ofstream fout;
	fout.open("check.log");
	fout.close();
	fout.open("ERR.txt");
	fout.close();
	MessageBox(GetForegroundWindow(),"                清理完成                 ","评测系统-日志清理器-单机版",MB_OK);
	return 0;
}
