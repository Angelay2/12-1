#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// ָ����ʷ�ʽ��������ʷ�ʽ����һ��,��Ϊ���ڸ�������������ά,
// ���û��ں����ڲ�ʹ��ָ��ʱ,��������������һ��,�չ��û�
// ��Ȼ�ں������ô�ָ���������,�ɱ���,��һ��ָ��һ�������,���׸���
int main1(){
	int a[5] = { 1, 2, 3, 4, 5 };
	int num = sizeof(a) / sizeof(a[0]);

	int* p = a;//һ��ָ��pָ��a

	int i = 0;
	for (; i < num; i++){
		printf("%d\n", a[i]);
		printf("%d\n", *(a + i));
		//ָ���������Ԫ�ط���������
		printf("%d\n", *(p + i));
		printf("%d\n", p[i]);
	}
	system("pause");
	return 0;

}

// ָ�봫��,ֻҪ���ξ�Ҫ��������,������������,pָ��main�������arr����
// ͨ��ָ�봫�δ�ӡ����
void print(int* p, int sz){  // pָ������arr, szΪ�����Ԫ�ظ���
	int i = 0;
	for (i = 0; i < sz; i++){
		printf("%d ", *(p + i));
	}
}
int main2(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* p = arr;// ������Ԫ�صĵ�ַ
	int sz = sizeof(arr) / sizeof(arr[0]);
	// һ��ָ��p������Ԫ�ظ���, ��������
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
// ���Խ��� int* p, int a = 10; &a, int a[10],
// void test2(char* p){} ���Խ��� char* p, char ch = 'a'; &ch, "hello world"

void show(char* p, int sz){
	for (int i = 0; i < sz; i++){
		printf("%c ", *(p + i)); // ��ӡ�ַ����ʹ�ӡ���鷽ʽһ��
	}
	printf("\n");
}
void show1(char* p){
	printf("%s\n", p);  // ��ָ���ӡ�ַ��� ͨ���ַ����׵�ַ�ҵ��ַ��� 
}
void show2(char* p){
	printf("%c\n", *p); // ֻ�ܴ�ӡһ���ַ� *p������p��ָ������ 
}
int main(){

	char arr[] = { "hello world!" };
	// �����ֽ����һ�� ǰ����p������Ԫ�ص�ַ ֻ�����һ��p�������ַ����ĵ�ַ ������ֵ��һ����
	char* p = arr;
	//char* p = &arr[0];
	//char* p = &arr;

	int sz = sizeof(arr) / sizeof(arr[0]);

	// ������� hello world
	show(p, sz);

	// ���ֶ����Դ��ַ���
	show1(p);
	show1("hello world!");
	show1(&arr);  


	char ch = 'a'; 
	show2(&ch);  // ��ӡ�ַ���ʱҪ�����ַ����������ַ����� �Ҵ�ӡ*(p+i)

	system("pause");
	return 0;
}
