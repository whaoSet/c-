#include<iostream>
#include<string>
#include<ctime>
using namespace std;
//定义学生结构体
struct student {
	string s_name;
	float score;
};
//定义老师结构体
struct teacher {
	string t_name;
	struct student sArray[5];
};
void allocateSpace(teacher tArray[], int len);
void printTeachers(teacher tArray[], int len);
int main() {
	//创建随时间改变的随机数种子
	srand((unsigned int)time(NULL));
	teacher tArray[3];
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray,len);
	printTeachers(tArray,len);
	system("pause");

	return 0;

}
//分配资源
void allocateSpace(teacher tArray[], int len) {
	string t_name = "老师";
	string s_name = "学生";
	string nameSeed = "ABCDE";//分配名称
	for (int i = 0; i < len; i++) {
		tArray[i].t_name = t_name + nameSeed[i];//分配老师名称
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].s_name = s_name + nameSeed[j];//分配学生名称
			tArray[i].sArray[j].score = rand() % 100 + 1;//分配学生成绩
		}
		
	}
}
//打印信息
void printTeachers(teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << tArray[i].t_name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名： " << tArray[i].sArray[j].s_name <<
				"\t学生分数："<<tArray[i].sArray[j].score<<endl ;
		}
	}
}
