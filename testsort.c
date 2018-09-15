#include"SeqList.h"

void TsetBack()
{
	SeqList arr;
	SeqListInit(&arr);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		PushBack(&arr, i);
	}
	SeqListPrint(&arr);
	PopBack(&arr);
	SeqListPrint(&arr);

}
void TestFront()
{
	SeqList arr;
	SeqListInit(&arr);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		PushFront(&arr, i);
	}
	SeqListPrint(&arr);
	PopFront(&arr);
	SeqListPrint(&arr);
}
void TestRemoe()
{
	SeqList arr;
	int pos = 0;
	SeqListInit(&arr);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		PushFront(&arr, i);
	}
	SeqListPrint(&arr);
	//PopFront(&arr);
	SLInsert(&arr, 5, 99);
	SLInsert(&arr, 5, 99);
	SLInsert(&arr, 5, 99);
	SLInsert(&arr, 5, 99);
	SeqListPrint(&arr);
	//Erase(&arr, 2);
	//Remove(&arr,99);
	//FRemoveAll(&arr, 99);
	//SRemoveAll(&arr, 99);
	//CRemoveAll(&arr, 99);

	SeqListPrint(&arr);

	//pos = SLFind(&arr, 8);
	pos = SLFind(&arr, 989);

	if (pos != -1)
		printf("找到了 %d\n", pos);
	else
		printf("没有找到\n");
}
int main()
{
	SeqList arr;
	int pos = 0;
	SeqListInit(&arr);

	PushBack(&arr, 69);
	PushBack(&arr, 32);
	PushBack(&arr, 98);
	PushBack(&arr, 75);
	PushBack(&arr, 188);
	PushBack(&arr, 15);
	PushBack(&arr, 65);
	PushBack(&arr, 11);
	PushBack(&arr, 52);
	SeqListPrint(&arr);

	//SeqListPrint(&arr);

	//pos = BinarySearch_R(&arr, 0,9,5);
	//if (pos != -1)
	//{
	//	printf("找到了%d \n",pos);
	//}


	//BubbleSort(&arr);
	//SelectSort(&arr);
	//SelectSort_OP(&arr);
	//SelectSort_OP(&arr);
	SelectSort_OP(&arr);
	SeqListPrint(&arr);

	system("pause");
	return 0;
}