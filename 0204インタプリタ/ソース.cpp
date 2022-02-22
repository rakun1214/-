#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10

//グローバル変数
int size;
int i = 0;
int k = 0;
char enzan;
char flgnum;
int variable = 0;

//関数宣言
void push(int x);
int pop(void);
void print(void);
int atoi(char* str);
int keisan(void);

void init(void)
{
	size = 0;
}
//構造体
typedef int data_t;
data_t stack[N];

typedef struct Source {
	char input[40];
	char s1[40];
}Source;

//構造体変数宣言
Source source[50];

int main()
{
	//ファイルポインタ
	FILE* fp;
	//変数宣言
	int work;
	char case1[] = "画面表示";
	char case2[] = "繰り返し";
	char case3[] = "四則演算";
	char case4[] = "変数作り";
	char case5[] = "条件分岐";
	char case6[] = "増分";
	char case7[] = "減分";
	char case8[] = "プログラム終了";
	//ファイルオープン
	fp = fopen("C:\\Users\\user\\Desktop\\0128プログラミング技法\\0204インタプリタ\\ソースコード入力.txt", "r");
	if (fp == NULL) return 1;
	while (true)
	{
		//ファイル読み取り
		work = fscanf(fp, "%s %s",source[i].input,source[i].s1);
		if (work == EOF)
		{
			break;
		}
		
		i++;
	}
	//ファイルクローズ
	fclose(fp);
	i = 0;
	while (true)
	{
		//画面表示
		if (strcmp(source[i].input, case1) == 0)
		{
			print();
			i++;
		}

		//繰り返し
		if (strcmp(source[i].input, case2) == 0)
		{
			char a[10];
			strcpy(a, source[i].s1);
			int num = atoi(a);
			i++;
			for (int num1 = 0; num1 < num; num1++)
			{
				//繰り返しで画面表示
				if (strcmp(source[i].input, case1) == 0)
				{
					print();
				}
				//
				//繰り返しで増分
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

				//繰り返しで減分
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

		//四則演算
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

		//変数作り
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

		//条件分岐
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
								//条件分岐画面表示 
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//増分
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
								//条件分岐画面表示
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//増分
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
								//条件分岐画面表示 
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//減分
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
								//条件分岐画面表示
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//減分
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
								//条件分岐画面表示 
								if (strcmp(source[i].input, case1) == 0)
								{
									print();
									i++;
								}
								//増分
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
								//減分
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

		//増分
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
						printf("変数を作ってください。\n");
						exit(1);
					}
					k++;
				}
			}
		}

		//減分
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

		//プログラム終了
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
		printf("変数は%dです。\n", variable);
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