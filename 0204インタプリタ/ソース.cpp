#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10

//�O���[�o���ϐ�
int size;
int i = 0;
int k = 0;
char enzan;
char flgnum;
int variable = 0;

//�֐��錾
void push(int x);
int pop(void);
void print(void);
int atoi(char* str);
int keisan(void);

void init(void)
{
	size = 0;
}
//�\����
typedef int data_t;
data_t stack[N];

typedef struct Source {
	char input[40];
	char s1[40];
}Source;

//�\���̕ϐ��錾
Source source[50];

int main()
{
	//�t�@�C���|�C���^
	FILE* fp;
	//�ϐ��錾
	int work;
	char case1[] = "��ʕ\��";
	char case2[] = "�J��Ԃ�";
	char case3[] = "�l�����Z";
	char case4[] = "�ϐ����";
	char case5[] = "��������";
	char case6[] = "����";
	char case7[] = "����";
	char case8[] = "�v���O�����I��";
	//�t�@�C���I�[�v��
	fp = fopen("C:\\Users\\user\\Desktop\\0128�v���O���~���O�Z�@\\0204�C���^�v���^\\�\�[�X�R�[�h����.txt", "r");
	if (fp == NULL) return 1;
	while (true)
	{
		//�t�@�C���ǂݎ��
		work = fscanf(fp, "%s %s",source[i].input,source[i].s1);
		if (work == EOF)
		{
			break;
		}
		
		i++;
	}
	//�t�@�C���N���[�Y
	fclose(fp);
	i = 0;
	while (true)
	{
		//��ʕ\��
		if (strcmp(source[i].input, case1) == 0)
		{
			print();
			i++;
		}

		//�J��Ԃ�
		if (strcmp(source[i].input, case2) == 0)
		{
			char a[10];
			strcpy(a, source[i].s1);
			int num = atoi(a);
			i++;
			for (int num1 = 0; num1 < num; num1++)
			{
				//�J��Ԃ��ŉ�ʕ\��
				if (strcmp(source[i].input, case1) == 0)
				{
					print();
				}
				//
				//�J��Ԃ��ő���
				if (strcmp(source[i].input, case6) == 0)
				{
					int atai1;
					k = 0;
					while (source[i].s1[k] != NULL)
					{
						if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
						{
							atai1 = atoi(&source[i].s1[k]);
							variable += atai1;
							k++;
						}
						else
						{
							k++;
						}
					}
				}

				//�J��Ԃ��Ō���
				if (strcmp(source[i].input, case7) == 0)
				{
					int atai2;
					while (source[i].s1[k] != NULL)
					{
						if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
						{
							atai2 = atoi(&source[i].s1[k]);
							variable -= atai2;
						}
						else
						{
							k++;
						}
					}
				}

			}
			i++;
		}

		//�l�����Z
		if (strcmp(source[i].input, case3) == 0)
		{
			int ans = 0;
			int num2;
			int cnt = 0;
			int cnt2 = 0;
			char a[10];
			while (source[i].s1[k] != NULL)
			{
				if (('9'>=source[i].s1[k]) && (source[i].s1[k] >= '0'))
				{
					k++;
					cnt++;
				}
				else
				{
					if (source[i].s1[k]=='=')
					{
						strncpy(a, &source[i].s1[cnt2], cnt);
						a[cnt] = '\0';
						cnt = 0;
						num2 = atoi(a);
						push(num2);
						ans = keisan();
						printf("%d\n", ans);
						k++;
					}
					else
					{
						enzan = source[i].s1[k];
						strncpy(a, source[i].s1, cnt);
						a[cnt] = '\0';
						cnt2 = cnt + 1;
						cnt = 0;
						num2 = atoi(a);
						push(num2);
						k++;
					}
				}
			}
			i++;
			k = 0;
		}

		//�ϐ����
		if (strcmp(source[i].input, case4) == 0)
		{
			int cnt = 0;
			int cnt2 = 0;
			char a[10];
			
			while (source[i].s1[k] != NULL)
			{
				if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
				{
					k++;
					cnt2++;
				}
				else if(source[i].s1[k]=='=')
				{
					k++;
					cnt++;
				}
				else
				{
					flgnum = source[i].s1[k];
					k++;
					cnt++;
				}
			}
			cnt2 += 1;
			strncpy(a, &source[i].s1[cnt], cnt2);
			variable = atoi(a);
			k = 0;
			i++;
		}

		//��������
		if (strcmp(source[i].input, case5) == 0)
		{
			char a;
			int value = 0;
			int w = 0;
			int w2 = 0;
			while (source[i].s1[k] != NULL)
			{
				if (!(('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0')))
				{
					a= source[i].s1[k];
					k++;
					switch (a)
					{
					case '<':
						if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
						{
							value = atoi(&source[i].s1[k]);
							i++;
							w = i;
							if (variable < value)
							{
								//���������ʕ\�� 
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//����
								if (strcmp(source[i].input, case6) == 0)
								{
									k = 0;
									int atai1;
									while (source[i].s1[k] != NULL)
									{
										if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
										{
											atai1 = atoi(&source[i].s1[k]);
											variable += atai1;
											k++;
										}
										else
										{
											k++;
										}
									}
									w2 = i;
									i = w;
								}

							}
							else
							{
								printf("error");
							}
							i = w2;
							i++;
							break;
						}
						else if(source[i].s1[k]=='=')
						{
							value = atoi(&source[i].s1[k + 1]);
							i++;
							k = 0;
							w = i;
							if (variable <= value)
							{
								//���������ʕ\��
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//����
								if (strcmp(source[i].input, case6) == 0)
								{
									k = 0;
									int atai1;
									while (source[i].s1[k] != NULL)
									{
										if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
										{
											atai1 = atoi(&source[i].s1[k]);
											variable += atai1;
											k++;
										}
										else
										{
											k++;
										}
									}
									w2 = i;
									i = w;
								}

							}
							else
							{
								printf("error");
							}
							i = w2;
							i++;
							break;
						}
					case '>':
						if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
						{
							value = atoi(&source[i].s1[k]);
							i++;
							w = i;
							if (variable > value)
							{
								//���������ʕ\�� 
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//����
								if (strcmp(source[i].input, case7) == 0)
								{
									k = 0;
									int atai1;
									while (source[i].s1[k] != NULL)
									{
										if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
										{
											atai1 = atoi(&source[i].s1[k]);
											variable -= atai1;
											k++;
										}
										else
										{
											k++;
										}
									}
									w2 = i;
									i = w;
								}

							}
							else
							{
								printf("error");
							}
							i = w2;
							i++;
							break;
						}
						else if (source[i].s1[k] == '=')
						{
							value = atoi(&source[i].s1[k + 1]);
							i++;
							k = 0;
							w = i;
							if (variable >= value)
							{
								//���������ʕ\��
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//����
								if (strcmp(source[i].input, case7) == 0)
								{
									k = 0;
									int atai1;
									while (source[i].s1[k] != NULL)
									{
										if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
										{
											atai1 = atoi(&source[i].s1[k]);
											variable -= atai1;
											k++;
										}
										else
										{
											k++;
										}
									}
									w2 = i;
									i = w;
								}
							}
							else
							{
								printf("error");
							}
							i = w2;
							i++;
							break;
						}
					case'!':
						if (source[i].s1[k] == '=')
						{
							k++;
							value = atoi(&source[i].s1[k]);
							i++;
							w = i;
							while (variable != value)
							{
								//���������ʕ\�� 
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//����
								if (strcmp(source[i].input, case6) == 0)
								{
									k = 0;
									int atai1;
									while (source[i].s1[k] != NULL)
									{
										if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
										{
											atai1 = atoi(&source[i].s1[k]);
											variable += atai1;
											k++;
										}
										else
										{
											k++;
										}
									}
									w2 = i;
									i = w;
								}
								//����
								if (strcmp(source[i].input, case7) == 0)
								{
									k = 0;
									int atai1;
									while (source[i].s1[k] != NULL)
									{
										if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
										{
											atai1 = atoi(&source[i].s1[k]);
											variable -= atai1;
											k++;
										}
										else
										{
											k++;
										}
									}
									w2 = i;
									i = w;
								}
							}
							i = w2;
							i++;
							break;
						}
					default:
						break;
					}
				}
			}
		}

		//����
		if (strcmp(source[i].input, case6) == 0)
		{
			int atai1;
			while (source[i].s1[k]!=NULL)
			{
				if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
				{
					atai1 = atoi(&source[i].s1[k]);
					variable += atai1;
					k++;
					i++;
				}
				else
				{
					if (flgnum!=source[i].s1[k])
					{
						printf("�ϐ�������Ă��������B\n");
						exit(1);
					}
					k++;
				}
			}
		}

		//����
		if (strcmp(source[i].input, case7) == 0)
		{
			int atai2;
			while (source[i].s1[k] != NULL)
			{
				if (('9' >= source[i].s1[k]) && (source[i].s1[k] >= '0'))
				{
					atai2 = atoi(&source[i].s1[k]);
					variable -= atai2;
				}
				else
				{
					k++;
				}
			}
		}

		//�v���O�����I��
		if (strcmp(source[i].input, case8) == 0)
		{
			exit(0);
		}
	}
}

void print(void)
{
	if (flgnum == *source[i].s1)
	{
		printf("�ϐ���%d�ł��B\n", variable);
	}
	else
	{
		printf("%s\n", source[i].s1);
	}
}

int atoi(char *str)
{
	int num = 0;
	while (*str !='\0')
	{
		num += *str - 48;
		num *= 10;
		str++;
	}
	num /= 10;
	return num;
}

void push(int x)
{
	if (size >= N) {
		printf("stack overflow\n");
		return;
	}

	stack[size] = x;
	size++;
}

int pop(void)
{
	int x;
	if (size <= 0) {
		printf("stack underflow\n");
		return 0;
	}
	x = stack[size - 1];
	size--;
	return x;
}

int keisan(void)
{
	int n1 = 0, n2 = 0, ans = 0;
	while (size > 1)
	{
		n2 = pop();
		n1 = pop();
	}
	switch (enzan)
	{
	case '+':
		ans = n1 + n2;
		break;
	case'-':
		ans = n1 - n2;
		break;
	case'*':
		ans = n1 * n2;
		break;
	case'/':
		ans = n1 / n2;
		break;
	default:
		break;
	}
	return ans;
}