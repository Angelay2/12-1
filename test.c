#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// 指针访问方式和数组访问方式基本一样,是为了掩盖曾经发生过降维,
// 让用户在函数内部使用指针时,依旧像在用数组一样,照顾用户
// 不然在函数内用纯指针访问数组,成本大,且一会指针一会儿数组,容易搞晕
int main1(){
	int a[5] = { 1, 2, 3, 4, 5 };
	int num = sizeof(a) / sizeof(a[0]);

	int* p = a;//一个指针p指向a

	int i = 0;
	for (; i < num; i++){
		printf("%d\n", a[i]);
		printf("%d\n", *(a + i));
		//指针和数组在元素访问上相似
		printf("%d\n", *(p + i));
		printf("%d\n", p[i]);
	}
	system("pause");
	return 0;

}

// 指针传参,只要传参就要发生拷贝,拷贝的是内容,p指向main函数里的arr数组
// 通过指针传参打印数组
void print(int* p, int sz){  // p指向数组arr, sz为数组的元素个数
	int i = 0;
	for (i = 0; i < sz; i++){
		printf("%d ", *(p + i));
	}
}
int main2(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* p = arr;// 数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	// 一级指针p和数组元素个数, 传给函数
	print(p, sz);
	system("pause");
	return 0;
}

//void test1(int* p){
//	printf("%d\n", *p);
//}
//int main(){
//	int a = 10;
//	int * p = &a;
//	test1(&a);
//	test1(p);
//	system("pause");
//	return 0;
//}
// 可以接收 int* p, int a = 10; &a, int a[10],
// void test2(char* p){} 可以接收 char* p, char ch = 'a'; &ch, "hello world"

void show(char* p, int sz){
	for (int i = 0; i < sz; i++){
		printf("%c ", *(p + i)); // 打印字符串和打印数组方式一样
	}
	printf("\n");
}
void show1(char* p){
	printf("%s\n", p);  // 传指针打印字符串 通过字符串首地址找到字符串 
}
void show2(char* p){
	printf("%c\n", *p); // 只能打印一个字符 *p解引用p所指的内容 
}
int main(){

	char arr[] = { "hello world!" };
	// 这三种结果都一样 前两个p都是首元素地址 只有最后一个p是整个字符串的地址 但是数值是一样的
	char* p = arr;
	//char* p = &arr[0];
	//char* p = &arr;

	int sz = sizeof(arr) / sizeof(arr[0]);

	// 结果都是 hello world
	show(p, sz);

	// 三种都可以传字符串
	show1(p);
	show1("hello world!");
	show1(&arr);  


	char ch = 'a'; 
	show2(&ch);  // 打印字符串时要带上字符数包括的字符个数 且打印*(p+i)

	system("pause");
	return 0;
}
