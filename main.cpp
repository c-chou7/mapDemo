/*
1. 打印出网格中峰点的数目。
2. 打印出谷点的位置。假定谷点是一个比邻接点海拔都要低的点。编写一个名为 isValley 的
函数供你的程序调用 。
3. 找出并打印海拔数据中最高点和最低点的位置及其海拔。编写一个名为 extremes 的函数
供你的程序调用。
4. 修改函数 isPeak(), 使用 8 个邻接点来判断峰点，而不再是只使用 4 个邻近点判断。
*/

#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>

#define MAXSIZE 64

void isPeak(int grid[MAXSIZE][MAXSIZE], int r, int c);
void isValley(int grid[MAXSIZE][MAXSIZE], int r, int c);

using namespace std;

int main(void) {
	int map[MAXSIZE][MAXSIZE] = { 0 };						//初始化坐标数组
	ifstream file;																//文件流
	string filename;														//存储文件名
	string choice;															//选择峰值还是谷点
	int rowsCount = 0;													//存储文件行数
	int colsCount = 0;													//存储文件列数

	cout << "请输入要打开的文件名字:";
	cin >> filename;

	file.open(filename.c_str());
	if (file.fail()) {
		cout << "打开文件失败!" << endl;
		return 1;
	}

	file >> rowsCount >> colsCount;								//输入行数和列数

	if (rowsCount > MAXSIZE || colsCount > MAXSIZE) {
		cout << "文件数据大,调整数组大小" << endl;
		return 1;
	}

	for (int i = 0; i < rowsCount; i++) {								//文件内容输入数组
		for (int j = 0; j < colsCount; j++) {
			file >> map[i][j];
		}
	}

	int n = 0;																		//退出循环表示符

	

	while (n == 0) {
		system("cls");
		cout << "请选择峰值or谷点:";
		cin >> choice;
		
		if (choice == "峰值") {
			isPeak(map, rowsCount, colsCount);
			system("pause");
		}
		else if (choice == "谷点") {
			isValley(map, rowsCount, colsCount);
			system("pause");
		}else {
			n = 1;
		}
	}

	system("pause");
	return 0;
}

void isPeak(int grid[MAXSIZE][MAXSIZE], int r, int c){
	for (int i = 1; i < r - 1; i++) {
		for (int j = 1; j < c - 1; j++) {
			if(grid[i][j] > grid[i - 1][j]&&
				grid[i][j] > grid[i + 1][j] &&
				grid[i][j] > grid[i][j - 1] &&
				grid[i][j] > grid[i][j + 1]) {
				cout << "峰值坐标行为 " << i << "列 " << j << endl;
				cout << "峰值为" << grid[i][j]<<endl;
			}
		}
	}
}

void isValley(int grid[MAXSIZE][MAXSIZE], int r, int c){
	for (int i = 1; i < r - 1; i++) {
		for (int j = 1; j < c - 1; j++) {
			if (grid[i][j] < grid[i - 1][j] &&
				grid[i][j] < grid[i + 1][j] &&
				grid[i][j] < grid[i][j - 1] &&
				grid[i][j] < grid[i][j + 1]) {
				cout << "谷点坐标行为 " << i << "列 " << j << endl;
				cout << "谷点为" << grid[i][j] << endl;
			}
		}
	}
}
