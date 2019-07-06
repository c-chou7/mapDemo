/*
1. ��ӡ�������з�����Ŀ��
2. ��ӡ���ȵ��λ�á��ٶ��ȵ���һ�����ڽӵ㺣�ζ�Ҫ�͵ĵ㡣��дһ����Ϊ isValley ��
��������ĳ������ ��
3. �ҳ�����ӡ������������ߵ����͵��λ�ü��亣�Ρ���дһ����Ϊ extremes �ĺ���
����ĳ�����á�
4. �޸ĺ��� isPeak(), ʹ�� 8 ���ڽӵ����жϷ�㣬��������ֻʹ�� 4 ���ڽ����жϡ�
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
	int map[MAXSIZE][MAXSIZE] = { 0 };						//��ʼ����������
	ifstream file;																//�ļ���
	string filename;														//�洢�ļ���
	string choice;															//ѡ���ֵ���ǹȵ�
	int rowsCount = 0;													//�洢�ļ�����
	int colsCount = 0;													//�洢�ļ�����

	cout << "������Ҫ�򿪵��ļ�����:";
	cin >> filename;

	file.open(filename.c_str());
	if (file.fail()) {
		cout << "���ļ�ʧ��!" << endl;
		return 1;
	}

	file >> rowsCount >> colsCount;								//��������������

	if (rowsCount > MAXSIZE || colsCount > MAXSIZE) {
		cout << "�ļ����ݴ�,���������С" << endl;
		return 1;
	}

	for (int i = 0; i < rowsCount; i++) {								//�ļ�������������
		for (int j = 0; j < colsCount; j++) {
			file >> map[i][j];
		}
	}

	int n = 0;																		//�˳�ѭ����ʾ��

	

	while (n == 0) {
		system("cls");
		cout << "��ѡ���ֵor�ȵ�:";
		cin >> choice;
		
		if (choice == "��ֵ") {
			isPeak(map, rowsCount, colsCount);
			system("pause");
		}
		else if (choice == "�ȵ�") {
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
				cout << "��ֵ������Ϊ " << i << "�� " << j << endl;
				cout << "��ֵΪ" << grid[i][j]<<endl;
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
				cout << "�ȵ�������Ϊ " << i << "�� " << j << endl;
				cout << "�ȵ�Ϊ" << grid[i][j] << endl;
			}
		}
	}
}
