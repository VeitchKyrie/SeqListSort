#include"SeqList.h"
void SelectSort(SeqList* pSeq)//ѡ������
{
	//1.assert
	assert(pSeq);
	//�ҳ����ֵ
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz - 1; i++)//���������
	{
		int max = 0;
		for (j = 0; j < pSeq->sz - i; j++)
		{
			if (pSeq->_data[max] < pSeq->_data[j])//�ҳ����ֵ���±�
			{
				max = j;
			}
		}
		if (max != pSeq->sz - i - 1)//��max == pSeq->sz-i-1ʱ˵���������
		{
			Swap(&pSeq->_data[max], &pSeq->_data[pSeq->sz - i - 1]);//�����ֵ�������һ��λ��
		}
	}
}
void SelectSort_OP(SeqList* pSeq)//ѡ�������Ż���
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
			if (max == start)//������ֵ���ұߣ��Ѿ��������ˣ���ʱ���ֵ���±�Ϊmin
				max = min;
		}
		if (max != end)
			Swap(&pSeq->_data[max], &pSeq->_data[end]);
		start++;
		end--;
	}
}