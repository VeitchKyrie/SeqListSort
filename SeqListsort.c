#include"SeqList.h"
void SeqListInit(SeqList* pSeq)//��ʼ��˳���
{
	//1.assert
	assert(pSeq);
	//2.//˳�������鶼��ʼ��Ϊ0
	memset(pSeq->_data, 0, MAX);
	pSeq->sz = 0;
}
void PushBack(SeqList* pSeq, DataType d)//β������
{
	//2.assert
	assert(pSeq);
	//2.����
	if (pSeq->sz == MAX)
	{
		printf("˳�������\n");
		return ;
	}
	//3.����Ԫ��
	pSeq->_data[pSeq->sz] = d;
	pSeq->sz++;
}
void PopBack(SeqList*pSeq)//β��ɾ��
{
	//1.asert
	assert(pSeq);
	//2.�ж�˳����Ƿ�Ϊ��
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	//3.ɾ��
	pSeq->sz--;
}
void SeqListPrint(SeqList *pSeq)//��ӡ˳���
{
	//1.assert
	assert(pSeq);
	//�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	//3.��ӡ
	int i; 
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->_data[i]);
	}
	printf("\n");
}
void PushFront(SeqList* pSeq, DataType d)//ͷ������
{
	//1.assert
	assert(pSeq);
	//2.����
	if (pSeq->sz == MAX)
	{
		printf("˳�������\n");
		return;
	}
	//3.����
	int i = pSeq->sz;
	while (i--)//������ĵ�һ��λ����������
	{
		pSeq->_data[i + 1] = pSeq->_data[i];
	}
	pSeq->_data[0] = d;//ͷ�巨�Ǵ��±�Ϊ0�ĵط������
	pSeq->sz++;
}
void PopFront(SeqList* pSeq)//ͷ��ɾ��
{
	//1.assert
	assert(pSeq);
	//2.�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	//3.ɾ��
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		pSeq->_data[i] = pSeq->_data[i + 1];
	}
	pSeq->sz -- ;
}
int SLFind(SeqList* pSeq, DataType d)//����Ԫ��
{
	//1.assert
	assert(pSeq);
	//2.�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return -1;
	}
	//3.����
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->_data[i] == d)
			return d;
	}
	return 0;
}
void SLInsert(SeqList* pSeq, int pos, DataType d)//֪��λ�ò���
{
	//1.assert
	assert(pSeq);
	//2.����
	if (pSeq->sz == MAX)
	{
		printf("˳�������\n");
		return;
	}
	//����
	int i =0 ;
	for (i = pSeq->sz; i >= pos; i--)//ע�⣺��Ϊ��pos֮ǰ���롣������Ҫ��˳������һλ��������ƶ�һλ��������posʱֹͣ
	{
		pSeq->_data[i + 1] = pSeq->_data[i];
	}
	pSeq->_data[pos] = d;//�Ѳ����ֵ����pos��λ��
	pSeq->sz++;
}
void Erase(SeqList* pSeq, int pos)//ָ��λ�õ�ɾ��
{
	//1.assert
	assert(pSeq);
	//�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	//ɾ��,ֱ��ɾ�������ú�ߵ�ֱ�Ӹ���ǰ�ߵ�Ԫ��
	int i = 0;
	for (i = pos; i < pSeq->sz; i++)
	{
		pSeq->_data[i] = pSeq->_data[i + 1];
	}
	pSeq->sz--;
}
void Remove(SeqList*pSeq, DataType d)//ɾ��ָ��Ԫ��
{
	//1.assert
	assert(pSeq);
	//�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	//ɾ��
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->_data[i] == d)
		{
			for (j = i; j <=pSeq->sz; j++)
			{
				pSeq->_data[j] = pSeq->_data[j + 1];
			}
			pSeq->sz--;
			return;
		}
	}
	printf("Ҫɾ����Ԫ�ز�����\n");
}
void FRemoveAll(SeqList* pSeq, DataType d)//����һ��ɾ�����е�ָ��Ԫ�أ�ί�񸲸Ƿ�
{
	//1.assert
	assert(pSeq);
	//2.�п�
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	//3.ɾ��,����Ҫɾ�������ú�ߵ���ֱ��������ǰ�ƶ�һλ������return�Ϳ��԰���ͬ����ɾ����
	int i = pSeq->sz;
	int j = 0;
	while (i--)
	{
		if (pSeq->_data[i] == d)
		{
			for (j = i; j < pSeq->sz; j++)
			{
				pSeq->_data[j] = pSeq->_data[j + 1];
			}
			pSeq->sz--;
		}
	}
}
void SRemoveAll(SeqList* pSeq, DataType d)//��������ɾ�����е�ָ��Ԫ�أ�ֱ�ӱ���ɾ����������Ҫɾ����ֱ�Ӹ��ǣ�
{
	assert(pSeq);
	int i = 0;
	int count = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->_data[i] != d)//�ҵ���ɾ��������
		{
			pSeq->_data[count++] = pSeq->_data[i];//ֱ����ԭ���ı��Ͻ���
		}
	}
	pSeq->sz = count;//����˳����Ԫ�ظ���
}

void CRemoveAll(SeqList* pSeq, DataType d)//��������ɾ�����е�ָ��Ԫ�أ���̬���ٷ����Ѳ����ɵ����ݸ��Ƶ����ٵ������
{
	assert(pSeq);
	DataType *tmp=0;
	int i = 0;
	int count = 0;
	tmp = (DataType*)malloc(sizeof(DataType)*pSeq->sz);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->_data[i] != d)//�Ѳ�ɾ�������ݿ��������ٵ�������
		{
			tmp[count++] = pSeq->_data[i];
		}
	}
	memcpy(pSeq->_data, tmp, sizeof(DataType)*count);//��tmp�е�Ԫ�ؿ�����pSeq��
	pSeq->sz = count;//��Ԫ�ظ�����pSeq
	free(tmp);//��̬�����Ժ�һ��Ҫ�ͷ�
	tmp = NULL;//��ֹ����Ұָ��
}
int Size(SeqList* pSeq)//����˳���Ĵ�С
{
	assert(pSeq);
	return pSeq->sz;//ֱ�ӷ���˳���Ĵ�С
}
int Empty(SeqList* pSeq)//˳����Ƿ�Ϊ��
{
	assert(pSeq);
	return pSeq->sz == 0 ? 0 : 1;//�շ���0���ǿշ���1
}


void Swap(DataType *x1, DataType *x2)
{
	DataType tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}
void BubbleSort(SeqList* pSeq)//ð������
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz - 1; i++)//�ⲿѭ�������������
	{
		for (j = 0; j < pSeq->sz - 1 - i; j++)//ÿһ������Ĵ���
		{
			if (pSeq->_data[j]>pSeq->_data[j + 1])//��ǰһ�����Ⱥ�һ������ʱ
			{
				Swap(&pSeq->_data[j], &pSeq->_data[j + 1]);
			}
		}
	}
}
void BubbleSort_OP(SeqList* pSeq)//ð�������Ż���
{
	assert(pSeq);
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < pSeq->sz - 1; i++)//�ⲿѭ�������������
	{
		flag = 0;//���Ϊ0
		for (j = 0; j < pSeq->sz - 1 - i; j++)//ÿһ������Ĵ���
		{
			if (pSeq->_data[j]>pSeq->_data[j + 1])//��ǰһ�����Ⱥ�һ������ʱ
			{
				Swap(&pSeq->_data[j], &pSeq->_data[j + 1]);
				flag = 1;//��������ˣ��ڱ��Ϊ1
			}
		}
		if (flag == 0)//���flag==0˵���������
			return;
	}
}
void SelectSort(SeqList* pSeq)//ѡ������
{
	//1.assert
	assert(pSeq);
	//�ҳ����ֵ
	int i = 0;
	int j = 0;
	for (i = 0; i < pSeq->sz-1; i++)//���������
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
			Swap(&pSeq->_data[max], &pSeq->_data[pSeq->sz-i-1]);//�����ֵ�������һ��λ��
		}
	}
}
void SelectSort_OP(SeqList* pSeq)//ѡ�������Ż���
{
	assert(pSeq);
	int start = 0;
	int end = pSeq->sz - 1;
	while (start <= end)
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
			if (max == end)//������ֵ���ұߣ��϶�Ҫ�����ߣ���ʱҪת�Ƶ��µ���Ӧ��λ��
				max = min;
		}
		if (max != end)
			Swap(&pSeq->_data[max], &pSeq->_data[end]);
		start++;
		end--;
	}
}


int BinarySearch(SeqList *pSeq, DataType d)//���ֲ��Һ���
{
	int left = 0;
	int right = pSeq->sz - 1;//���ұ�Ԫ�ص��±�
	while (left < right)//ѭ������
	{
		int mid = left + (right - left) / 2;//ȷ���м�Ԫ�ص��±�

		if (pSeq->_data[mid]>d)//���м�Ԫ�ش���d
		{
			right = mid - 1;
		}
		else if (pSeq->_data[mid] < d)//���м�Ԫ��С��d
		{
			left = mid + 1;
		}
		else
		{
			return mid;//�ҵ��˷���mid
		}
	}
	return -1;//�Ҳ���
}

int BinarySearch_R(SeqList *pSeq, int left, int right, DataType d)//���ֲ��ҵ��ĵݹ�д��
{
	assert(pSeq);
	int mid = left + (right - left) >> 1;//����һλ�൱�ڳ���
	while (left < right)
	{
		if (pSeq->_data[mid] < d)
			return BinarySearch_R(&pSeq, mid + 1, right, d);
		else if (pSeq->_data[mid]>d)
			return BinarySearch_R(&pSeq, left, mid - 1, d);
		else
			return mid;
	}
}