#include<iostream>
using namespace std;
void Test()
{
	int a = 10;
	int& ra = a;// ra��һ�����ã���a�ı�����ָ���a��ͬ��ʵ��
	printf("%p\n", &a);
	printf("%p\n", &ra);
}
//1.�ó�ʼ��
//2.һ����������ӵ�ж������
//3.һ�����ã�������ָ������ʵ��

//������ ����ָ���ʵ�壨��const�����ܱ��޸� 
void test()
{
	const int a = 10;

	const int& ra = a;
	const int& ra1 = 100;

	double d = 2.0;
	const int& ra3 = d;

	//��ʱ d�ᴴ��һ�����ε���ʱ���� d���Ž�ȥ ra3Ҳָ����ʱ����
	//�鿴��ַ d�ĵ�ַ��ra3�ĵ�ַ�ǲ�ͬ��
	//��ʱ�������г���
}

//ʹ��
//1.������
//2.������ֵ ��֤����ֵ���������ڴ��ں�����������

//���õĵײ�ʵ�� ����ͨ��ָ��ʵ�ֵ� ���������þ���ָ��
//���ñ������ɿռ�ģ��ռ�Ĵ�С��ָ���С��ͬ������ȥ����ָ��ʵ��Ŀռ�
//�����������õ�ʱ�򣬱������ڵײ��Զ�������

//1. �����ڶ���ʱ�����ʼ����ָ��û��Ҫ��
//2. �����ڳ�ʼ��ʱ����һ��ʵ��󣬾Ͳ�������������ʵ�壬��ָ��������κ�ʱ��ָ���κ�һ��ͬ����
//ʵ��
//3. û��NULL���ã�����NULLָ��
//4. ��sizeof�к��岻ͬ�����ý��Ϊ�������͵Ĵ�С����ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ���(32λƽ̨��ռ
//	4���ֽ�)
//5. �����ԼӼ����õ�ʵ������1��ָ���ԼӼ�ָ�����ƫ��һ�����͵Ĵ�С
//6. �ж༶ָ�룬����û�ж༶����
//7. ����ʵ�巽ʽ��ͬ��ָ����Ҫ��ʽ�����ã����ñ������Լ�����
//8. ���ñ�ָ��ʹ��������Ը���ȫ

//inline ��������
//�����̫���ӵĺ��� �Ͳ���������
//nline�����������Ͷ�����룬����ᵼ�����Ӵ�����Ϊinline��չ������û�к�����ַ�ˣ����Ӿͻ��Ҳ���

//�����ȱ�㣿
//�ŵ㣺
//1.��ǿ����ĸ����ԡ�
//2.������ܡ�
//ȱ�㣺
//1.��������Ժꡣ����ΪԤ����׶ν������滻��
//2.���´���ɶ��Բ��ά���Բ�������á�
//3.û�����Ͱ�ȫ�ļ�� ��
//C++����Щ��������ꣿ
//1. �������� ����const
//2. �������� ������������

//auto 
//��auto����ָ������ʱ����auto��auto*û���κ����𣬵���auto������������ʱ������&
//�Զ������Ƶ�
//����ͬһ�������������ʱ����Щ������������ͬ�����ͣ�������������ᱨ������Ϊ������ʵ��ֻ��
//��һ�����ͽ����Ƶ���Ȼ�����Ƶ����������Ͷ�������������
void test()
{
	auto a = 10;//�����ڱ����ʱ���Զ�ȷ����Ҫʲô����
	 
}

//��Χfor ��ǰ������ �� ѭ���ķ�Χ
//����ȫ

void test2()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	for (const auto& e : arr)//��ֹ���޸�
	{
		cout << e << " ";
		cout << endl;
	}
}

//ע���ں������д��������� ��������

//ָ���ֵ
void test()
{
	int* p = NULL;//Ԥ���������滻 ����˵��0 ����������ָ��ĳ��� �������ָ�뷽ʽ��ʹ�� ǿת��void*)0
	int* p2 = 0;
	//����ʹ��nullptr
}
//��C++11�У�sizeof(nullptr) �� sizeof((void*)0)��ռ���ֽ�����ͬ��