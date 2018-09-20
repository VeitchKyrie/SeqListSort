#include"SeqList.h"
void SelectSort(SeqList* pSeq)//选择排序
{
	//1.assert
	assert(pSeq);
	//找出最大值
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz - 1; i++)//排序的趟数
	{
		int max = 0;
		for (j = 0; j < pSeq->sz - i; j++)
		{
			if (pSeq->_data[max] < pSeq->_data[j])//找出最大值得下标
			{
				max = j;
			}
		}
		if (max != pSeq->sz - i - 1)//当max == pSeq->sz-i-1时说明排序完成
		{
			Swap(&pSeq->_data[max], &pSeq->_data[pSeq->sz - i - 1]);//把最大值放在最后一个位置
		}
	}
}
void SelectSort_OP(SeqList* pSeq)//选择排序优化版
{
	assert(pSeq);
	int start = 0;
	int end = pSeq->sz - 1;
	while (start < end)
	{
		int max = start;
		//int min = pSeq->sz-1;
		int min = start;
		int i = 0;
		for (i = start; i <= end; i++)
		{
			if (pSeq->_data[max] < pSeq->_data[i])
				max = i;
			if (pSeq->_data[min]>pSeq->_data[i])
				min = i;
		}
		if (min != start)
		{
			Swap(&pSeq->_data[min], &pSeq->_data[start]);
			if (max == start)//如果最大值在右边，已经被交换了，此时最大值的下标为min
				max = min;
		}
		if (max != end)
			Swap(&pSeq->_data[max], &pSeq->_data[end]);
		start++;
		end--;
	}
}