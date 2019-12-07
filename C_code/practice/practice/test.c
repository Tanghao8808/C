#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<assert.h>
//#######################################
//1. 打印100~200之间的素数

void prime_num()
{
	int count = 0;
	for (int i = 101; i <= 200; i+=2) 
	{
		int j = 0;
		for ( j = 2; j <= sqrt(i); j++)   
		{
			if (i%j == 0)
				break;
		}
		if (j > sqrt(i)) 
		{
			count++;
			printf("%d\t", i);

		}
	}
	printf("\n count = %d", count);
	
}
//#######################################

//2. 输出乘法口诀表
void Mul_table() 
{
	for (int i = 1; i <= 9; i++) 
	{
		for (int j = 1; j <= i; j++) 
		{
			printf("%d * %d = %-2d ", i, j, i*j);
		}
		printf("\n");
	}
}
//#######################################

//3. 判断1000年-- - 2000年之间的闰年
void leap_year()
{
	int count = 0;
	for (int year = 1000; year <= 2000; year++) 
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\n count = %d ", count);
}
//#######################################
//1. 给定两个整形变量的值，将两个值的内容进行交换。
void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//#######################################

//2. 不允许创建临时变量，交换两个数的内容（附加题）

//方式一：用a+b的和,缺点是a,b的和有可能存不下
void swap_UseSum(int *a, int *b) 
{
	long long tmp = *a + *b;
	*b = (int)tmp - *b;
	*a = (int)tmp - *b;
}
//方式二：异或,缺点可读性差
void swap_xor(int *a, int *b)
{
	int tmp = *a ^ *b;
	*a = tmp ^ *a;
	*b = tmp ^ *a;

}
void test_swap()
{
	int a = 10, b = 20;
	swap_xor(&a, &b);
	printf("a = %d ,b = %d ", a, b);

}
//#######################################


//3.求10 个整数中最大值。
int max_arr(int *p)
{
	int max_index = 0;
	for (int index = 1; index < 10; index++)
	{
		if (*(p + index) > *(p + max_index)) 
		{
			max_index = index;
		}
	}
	return max_index;
}
void test_max()
{
	int arr[] = { 1,2,3,9,5,6,7,8,4,0 };
	int ret = max_arr(arr);
	printf("%d\n", ret);
}
//#######################################

//4.将三个数按从大到小输出。
void three_max()
{
	int a = 10, b = 30, c = 20;
	int one = a, two = b, three = c;
	if (one < two) 
	{
		swap(&one, &two);
	}
	if (one < three)
	{
		swap(&one, &three);
	}
	if (two < three)
	{
		swap(&two, &three);
	}
	printf("%d %d %d \n", one, two, three);
	
}
//#######################################

//5.求两个数的最大公约数。

//辗转相除法 
//最小公倍数 = (a*b)/最大公约数
int Max_common_divisor(int a, int b)
{
	int tmp = 0;
	while (tmp = a % b)
	{
		a = b;
		b = tmp;
	}
	return b;
}
void test_max_common_divisor()
{
	printf("please enter number:\n");
	int a, b;
	scanf("%d %d", &a, &b);
	int ret = Max_common_divisor(a, b);
	printf("%d\n", ret);
}
//#######################################
//1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）

void swap_arr(int *arr1,int *arr2,int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(&arr1[i], &arr2[i]);
	}
}
void printf_arr(int *arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
void test_swap_arr()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 6,7,8,9,10 };
	int size = sizeof(arr1) / sizeof(arr1[0]);
	printf_arr(arr1,size);
	printf_arr(arr2,size);
	swap_arr(arr1, arr2, size);
	printf_arr(arr1, size);
	printf_arr(arr2, size);

}
//#######################################

//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
void sum()
{
	double sum = 0;
	int flag = 1;
	for (int i = 1; i <= 100; i++)
	{
		sum += 1.0 / i * flag;
		flag = -flag;     //注意一下正负数交替的写法
	}
	printf("%lf\n", sum);
}
//#######################################

//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
void count_nine()
{
	int count = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 10 == 9) //个位数为9
		{
			count++;
		}
		if (i / 10 == 9) //十位数为9
		{
			count++;
		}
	}
	printf("%d\n", count);
}
//#######################################
//计算n 的阶乘
//循环
void fac(int n)
{
	long long res = 1;
	for (int i = 2; i <= n; i++)
	{
		res *= i;
	}
	printf("%lld\n", res);
}

//递归
int fac_R(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fac_R(n - 1);
}
void Test_fac()
{
	int ret = fac_R(5);
	printf("%d\n", ret);
}
//计算 1! + 2! + 3! ... + n!
//1! + 2! +3! = 9
void fac_sum(int n)
{
	long long sum = 0;
	for (int j = 1; j <= n; j++)
	{
		long long res = 1;   //注意每次的阶乘结果开始都要初始化为1
		for (int i = 2; i <= j; i++)
		{
			res *= i;
		}
		sum += res;
	}
	printf("%lld\n", sum);
}
//优化版：3！就是在2！的结果上*3
void fac_sum_OP(int n)
{
	long long sum = 0;
	int res = 1;
	for (int j = 1; j <= n; j++)
	{
		res *= j;
		sum += res;
	}
	printf("%lld\n", sum);
}
//#######################################

//二分查找
int Binary_Search(int *arr, int size, int key)
{
	int left_index = 0;
	int right_index = size - 1;
	while (left_index <= right_index)
	{
		int middle_index = left_index+(right_index -left_index ) / 2;
		if (arr[middle_index] < key)
		{
			left_index = middle_index + 1;
		}
		else if (arr[middle_index] > key)
		{
			right_index = middle_index - 1;
		}
		else
		{
			printf("找到的元素下标为 %d\n", middle_index);
			return middle_index;
		}
	}
	printf("未找到元素\n");
	return -1;
}
void test_Binary_Search()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key = 1;
	int res = Binary_Search(arr, size, key);
	printf("%d\n", res);
}
//#######################################
/*1.在屏幕上输出以下图案：
      *
     ***
    *****
   *******
  *********
 ***********
*************
 ***********
  *********
   *******
    *****
     ***
      *
*/
void diamind_printf()
{
	int line = 6;
	//打印上半部分的6行
	for (int i = 0; i < line; i++)
	{
		//打印空格
		for (int count = 0; count < line - i; count++)
		{
			printf(" ");
		}
		//打印*
		for (int count = 0; count < 2*i+1; count++)
		{
			printf("*");
		}
		printf("\n");
		//打印空格
	}
	//打印下半部分的7行
	for (int i = 0; i < line+1; i++)
	{
		//打印空格
		for (int count = 0; count < i; count++)
		{
			printf(" ");
		}
		//打印*
		for (int count = 0; count < 2 * (line-i) + 1; count++)
		{
			printf("*");
		}
		printf("\n");
		//打印空格
	}

}
//#######################################

//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，
//如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。

/*
在数论中，水仙花数（Narcissistic number）也称为自恋数、
自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，
其各个数之N次方和等于该数。
例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
153 = 1^3 + 5^3 + 3^3。
370 = 3^3 + 7^3 + 0^3。
371 = 3^3 + 7^3 + 1^3。
407 = 4^3 + 0^3 + 7^3。
*/
//演变一下：几位数都可以计算
// 1.统计位数  2.计算每位数的次方和
void Aemstrong_Number()
{
	for (int i = 0; i < 10000; i++)
	{
		//统计位数
		int count = 1;
		int tmp = i;
		while (tmp = tmp/10 )
		{
			count++;
		}
		//计算每位数的次方和
		int sum = 0;
		tmp = i;
		while (tmp )
		{
			int res =(int) pow((tmp % 10), count);
			tmp /= 10;
			sum += res;
		}
		if (i == sum)
		{
			printf("%d\t", i);
		}
	}
}
int Digit_Sum(int num)
{
	if (num < 10)
		return num;
	return num % 10 + Digit_Sum(num / 10);
}
//递归实现求出每一位的和
void Test_Digit_Sum()
{
	int num = 1028;
	int sum = Digit_Sum(num);
	printf("%d\n", sum);
}
//#######################################

//3.
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
//#######################################
int ItemNumberSum(int a, int n)
{
	int sum = 0;
	int tmp = a;
	for (int i = 0; i < n; i++)
	{
		sum += a;
		a = a * 10 + tmp;
	}
	return sum;
}
void Test_ItemNumberSum()
{
	int res = ItemNumberSum(2, 5);
	printf("%d\n", res);
}
//#######################################

//4.编写一个程序，它从标准输入读取C源代码，
//并验证所有的花括号都正确的成对出现。

int BacketsMatch()
{
	int count = 0;
	char ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '{')
			count++;
		if (ch == '}' && count == 0)
		{
			printf("backets not match!!\n");
			return -1;
		}
		if(ch == '}'&& count != 0 )
		{
			count--;
		}
	}
	if(count == 0)
	{
		printf("backets match\n");
		return 0;
	}
	else
	{
		printf("backets not match!!\n");
		return -1;
	}
}
//#######################################
//1.写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}
//方法一：Num%2拿到最后一位，Num/2向右移一位（但是处理不了负数, 负数/2 == 0）
int count_one_bits_1(int values)  //参数写成 unsigned int 可以处理负数
{
	int count = 0;
	while (values)
	{
		if ((values % 2) == 1)
		{
			count++;
		}
		values /= 2;
	}
	printf("count = %d\n", count);
	return count;
}
//方法二：不断的右移一位&1,
int count_one_bits_2(int values)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((values >> i) & 1) == 1)
		{
			count++;
		}

	}
	printf("count = %d\n", count);
	return count;
}
//方法三：num & num -1最会去掉最右边的一位1，能够执行几次这样的操作，就有几个1
int count_one_bits_3(int values)
{
	int count = 0;
	while (values)
	{
		values = values & (values - 1);
		count++;
	}
	printf("count = %d\n", count);
	return count;
}
//演变题：判断一个数是不是2的n次方的数
//2的次方的数，二进制中只有一个1，num & num -1 一定 == 0
//#######################################

//2.获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
void Binary_odd_even(int num)
{
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	printf("\n");

}
//#######################################

//3. 输出一个整数的每一位。
//方法一：num%10取到最后一位用数组存起来，num/10取到最后一位，最后打印数组
//方法二：递归
void print_int_bit(int num)
{
	if (num > 9)
		print_int_bit(num / 10);
	printf("%d  ", num % 10);
}
void Test_print_int_bit()
{
	int num = 1024;
	print_int_bit(num);
}
//#######################################

//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7

//只需要判断异或之后的结果有几个1
int count_binary_different(int m, int n)
{
	int res = m ^ n;
	int count = 0;
	while (res)
	{
		res = res & (res - 1);
		count++;
	}
	printf("count = %d\n", count);
	return count;
}
//#######################################
//在屏幕上打印杨辉三角。
//      1
//     1 1
//    1 2 1
//   1 3 3 1
//  1 4 6 4 1

//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
void print_YangHuiTriangle()
{
	int arr[10][10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0 || i == j) //第一列和对角线为1
			{
				arr[i][j] = 1;
			}
			if (i > 1 && j > 0) //中间为上面两个之和
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	//打印
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
//#########################################################################################
//写一个宏：将一个数的二进制的奇数位和偶数位进行交换
#define SWAP_BIT(num) ((num&0xaaaaaaaa)>>1)|((num&0x55555555)<<1)
//注意：左移和右移操作不会改变自身的值
void Test_SWAP_BIT()
{
	int num = 10;
	int n = SWAP_BIT(num);
	printf("%d\n", num);
	printf("%d\n", n);
}
//#########################################################################################

//1.编写函数：
//unsigned int  reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。 即返回一个unsigned int
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000  
//程序结果返回：
//2550136832
unsigned int reverse_bit(int num)
{
	//思路1：将每一个拿下来，乘以这一位该有的次方，然后所有的值加起来
	//比如最低位的1，*10^31
	unsigned int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		int ret = ((num >> i) & 1);
		sum += ret * (unsigned int)pow(2, 31-i);
	}
	return sum;
}
unsigned int reverse_bit_OP(int num)
{
	//思路2：从最低位开始将每一个&1拿下来，再 | 0 ，
	//将这一位放到最后，左移一位，不断循环，最后循环到31次时， 最低位就会来到最左边
	
	unsigned int ret = 0;
	for (int i = 0; i < 32; i++)
	{
		int tmp = (num >> i) & 1;
		ret = ret | tmp;
		if (i < 31)    //注意ret应该只左移31次，
			ret = ret << 1;
	}
	return ret;
}

void Test_reverse_bit()
{
	int num = 25;
	unsigned int ret = reverse_bit_OP(num);
	printf("%u\n", ret);
}
//#########################################################################################

//2.不使用（a + b） / 2这种方式，求两个数的平均值。

int My_Average(int a, int b)
{
	//int ret = a + (b - a) / 2;
	int ret = a + ((b - a) >> 1);
	return ret;

}
int My_Average_OP(int a, int b)
{
	//a&b得到相同的二进制位/2的结果：1&1 = 1； 0 &0 = 0
	//(a^b) /2得到的是不同的二进制位/2的结果： 0^1 = 1
	int ret = (a & b) + ((a^b) >> 1);
	return ret;

}
void Test_Average()
{
	int a = 50;
	int b = 20;
	int ret = My_Average_OP(a, b);
	printf("%d\n", ret);
}

//#########################################################################################

//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//

int Find_num(int* arr, int size)
{
	int ret = arr[0];
	for (int i = 1; i < size; i++)
	{
		ret ^= arr[i];
	}
	return ret;
}
void Test_find_num()
{
	int arr[] = { 1,2,3,4,1,2,3,4,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = Find_num(arr, size);
	printf("%d\n", ret);
}
//#########################################################################################

//1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//思路：分组异或，将所有的数字异或在一起，肯定不为0，就会有个不相同的位，
//按照这个位将所有的数字分为两组，不相同的数字就分开的，每一组异或在一起，就得到了不相同的两个数字

void find_two_num(int *arr, int size)
{
	int tmp = 0;
	int sign = 0;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < size; i++)
	{
		tmp = tmp ^ arr[i];
	}
	for (int i = 0; i < 32; i++)
	{
		if (((tmp >> i) & 1) == 1)
		{
			sign = i;
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (((arr[i] >> sign) & 1) == 1)
		{
			num1 = num1 ^ arr[i];
		}
		else
			num2 = num2 ^ arr[i];
	}
	printf("%d\t%d\n", num1, num2);
}
void Test_find_two_num()
{
	int arr[] = { 1,1,2,2,3,3,8,5 };
	find_two_num(arr, sizeof(arr) / sizeof(arr[0]));
}
//#########################################################################################

//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。

//思路一：先逆序整个整个字符串，然后再逆序每个单词
//	student a am i
//	i ma a tneduts
//	i am a student
int my_strlen(const char* p);
void reverse_str(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
//字符串翻转的递归写法：
void reverse_str_R(char* str)
{
	assert(str != NULL);
	int len = strlen(str);
	if (len < 2)
		return;
	int tmp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (strlen(str+1) > 1)
	{
		reverse_str_R(str + 1);
	}
	*(str + len - 1) = tmp;
}
void Test_reverse_str_R()
{
	char arr[] = "abcdef";
	printf("%s\n", arr);
	reverse_str_R(arr);
	printf("%s\n", arr);
}
void reverse(char *str)
{
	assert(str != NULL);
	char* cur = str;
	char *left = str;
	char *right = str + my_strlen(str) - 1;
	reverse_str(left, right);    //逆序整个字符串  
	//不断的找空格，划分单词块，进行逆序
	while (*cur != '\0')
	{
		char* start = cur;
		while ((*cur != ' ') && (*cur != '\0'))
		{
			cur++;
		}
		reverse_str(start, cur-1);
		if (*cur == ' ')
		{
			cur++;
		}
	}
}
void Test_reverse()
{
	char str[] = "student a am i";
	reverse(str);
	printf("%s\n",str);

}
//#########################################################################################
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
void Adjust_Arr(int* arr, int size)
{
	int left = 0;
	int right =  size - 1;
	while (left < right)
	{
		while (arr[left] % 2 == 1 && left < right)
		{
			left++;
		}
		while (arr[right] % 2 == 0 && left < right)
		{
			right--;
		}
		if(left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}

	}
}
void Test_Adjust_Arr()

{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf_arr(arr, size);
	Adjust_Arr(arr, size);
	printf_arr(arr, size);
}
//#########################################################################################
//2.
////杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
struct pos
{
	int x;
	int y;
};
struct pos FindInYangMatrix(int arr[3][3], int row, int col, int key)
{
	//从右上角元素开始找
	int x = 0;
	int y = col - 1;
	struct pos pos = { -1,-1 };
	while (x < row && y >= 0)
	{
		if (arr[x][y] == key)
		{
			pos.x = x;
			pos.y = y;
			return pos;
		}
		else if (arr[x][y] < key)
		{
			x++;
		}
		else
		{
			y--;
		}
	}
	return pos;
}
void TestYangMatrix()
{
	//想要返回坐标可以有两种方式：
	//1.将坐标x,y设计成结构体
	//2.设计输出型参数（返回型参数）将行和列的指针作为参数带进去，函数内部用指针修改为要返回的坐标带出来
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9, };
	struct pos ret  =  FindInYangMatrix(arr, 3, 3, 3);
	if (ret.x != -1 && ret.y != -1)
		printf("杨氏矩阵中存在该元素,坐标：%d,%d\n",ret.x,ret.y);
	else
		printf("杨氏矩阵中不存在该元素\n");

}
//#########################################################################################
//旋转字符串问题：
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//思路一：abcdef\0，先将a拿出来，再将\0之前的往前移，将a放到\0之前，循环k次这个过程
void Rotate_string(char *str, int k)
{
	char tmp = 0;
	char* cur = NULL;
	while(k--)
	{
		cur = str;
		tmp = *cur;
		while (*(cur + 1) != '\0')
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = tmp;
	}
}

//思路二：三步翻转法
//abcdef->bacdef：逆序前k个字符
//bacdef->bafedc：逆序后面的字符
//bafedc->cdefab：整体逆序
void Rotate_string_OP(char *str, int k)
{
	int len = strlen(str);
	reverse_str(str, str + k - 1);
	reverse_str(str + k, str + len - 1);
	reverse_str(str, str + len - 1);
}


void Test_Rotate_string()
{
	char str[] = "abcdef";
	printf("%s\n", str);
	Rotate_string_OP(str, 3);
	printf("%s\n", str);
}

//#########################################################################################


//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC

//思路：字符串追加法
//在字符串后面追加一串一样的字符串：AABCDAABCD
//在看要判断的字符串是不是这个新字符串的字串
int Judge_Rotate_string(char* str, char* p)
{
	if (strlen(str) != strlen(p))
	{
		return -1;
	}
	//strcat(str, str); 这里自己给自己追加，会造成死循环，根本追加不完，
	strncat(str, str, strlen(str));
	char* ret = strstr(str, p);
	if (ret != NULL)
		return 1;
	else
		return -1;
}
void Test_Judge_Rotate_string()
{
	char str[20] = "AABCD";
	int ret = Judge_Rotate_string(str, "ABCDA");
	if (ret == 1)
	{
		printf("旋转可以得到该字符串\n");
	}
	else
		printf("旋转不可以得到该字符串\n");
}
//#########################################################################################
//递归实现pow函数
int my_pow_R(int num, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k > 0)
	{
		return num * my_pow_R(num, k - 1);

	}
}
void Test_my_pow()
{
	int ret = my_pow_R(5, 4);
	printf("%d\n", ret);
}


//##########################################################################################
//实现atoi

enum State
{
	vaild,
	invaild
};
enum State state = invaild;
int my_atoi(const char* str)
{
	int flag = 1;
	long long ret = 0;
	assert(str);
	if (*str == '\0')
		return;
	while (isspace(*str))  //空白字符
	{
		str++;
	}
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	while (*str)
	{
		if (isdigit(*str))
		{
			ret = ret * 10 + (*str - '0')*flag;
			if (ret > INT_MAX || ret < INT_MIN)
			{
				return 0;
			}
		}
		else
		{
			return ret;
		}
		str++;
	}
	state = vaild;
	return ret;
}
void Test_atoi()
{
	char* str = "1234";
	int ret = my_atoi(str);
	if (state == vaild)
	{
		printf("%d\n", ret);
	}
}


//##########################################################################################
//static  在C语言中的三种用法：
//1.修饰局部变量：改变了局部变量的存储位置，由栈上改到了 静态区，从而改变了变量的生命周期，
//2.修饰全局变量：
//3，修饰函数：
//修饰全局变量和函数时，都是改变了连接属性，
//由外部链接属性改为了内部链接属性，只能在本源文件内部使用。
//####################################################
//sizeof是操作符;sizeof算的是变量所占空间的大小，只与变量类型有关，
//所以sizeof(表达式)，表达式不会参与运算
//strlen();参数是地址，根据地址往后面找'\0'，输出字符个数，
//数组名代表数组首元素的地址
//只有两种情况例外：
//1.sizeof(数组名)：数组名单独放在sizeof内部，代表整个数组
//2.&数组名,取出的是整个数组的地址，
//地址的类型的意义在于*解引用能访问多大的权限，地址加1 能向后跳多远，
//&数组名，取出的是整个数组的地址，加1 跳过整个数组，*解引用访问整个数组
//二维数组在运算的时候，思想上一定要想象成一维数组，二维数组的每个元素都是一个一维数组
//####################################################
//冒泡排序：
//核心思想：两两相邻的元素进行比较，不满足顺序就交换，
//一趟冒泡排序完了之后，第一个数已经出现了在他最终该出现的位置
//所以10个数，应该需要进行9 趟冒泡
void Bubble_Sort(int *arr, int size);
void Test_Bubble_Sort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf_arr(arr, size);
	Bubble_Sort(arr, size);
	printf_arr(arr, size);

}
//数组的形式：
void Bubble_Sort(int *arr, int size)
{
	int flag = 0;
	for (int i = 0; i < size -1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)  //注意循环范围
		{
			flag = 1;
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
		if (flag == 0)
			return ;
	}
}
void Bubble_Sort_Use_Point(int *arr, int size)
{
	int* left = arr;
	int* right = arr + size - 1;
	while (left < right)
	{
		int* tmp = left;
		while (tmp < right)
		{
			if (*tmp > *(tmp + 1))
			{
				swap(tmp, tmp + 1);
			}
			tmp++;
		}
		right--;
	}
}
//指针的形式：
void Test_Bubble_Sort_Use_Point()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf_arr(arr, size);
	Bubble_Sort_Use_Point(arr, size);
	printf_arr(arr, size);

}
//####################################################

//strcpy注意点：
//1.dest目标地址一定要可以进行修改，不能传入一个常量字符串的地址，常量字符串不能够修改
//2.src源字符串一定要有'\0'结尾，
//3.strcpy会将源字符串加上'\0'都拷贝到目标地址，并返回目标空间的地址
//strcpy返回目标空间的起始地址，为了实现链式访问
//链式访问：将一个函数的返回值作为另外一个函数的参数
//源地址类型为const char* ，地址不能进行*解引用修改，
//调用函数的时候将目标和地址传反了，这样在编译期间就会报错
char* my_strcpy(char* dest,const char* src)  //注意返回值和参数加上const,不能修改，
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;         //注意最后要把目标空间返回回去,为了实现链式访问，就一定要先把目标空间记住
	while (*dest++ = *src++) //'\0'拷贝过去了，然后跳出循环
	{
		;
	}
	/*while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src; //将'\0'拷贝过去
	*/
	return ret;
}
void Test_My_Strcpy()
{
	char arr[20] = {0};
	char* p = "test my_strcpy";
	char* ret = my_strcpy(arr, p);
	printf("%s\n", ret);
}
//####################################################
//strncpy：拷贝size个字符，源不够的话后面就全补'\0'

char* my_strncpy(char* dest, const char* src,int size)  //注意返回值和参数加上const,不能修改，
{
	assert(dest != NULL);
	assert(src != NULL);
	int tmp = size - strlen(src);
	char* ret = dest;         //注意最后要把目标空间返回回去,为了实现链式访问，就一定要先把目标空间记住
	while (size--)
	{
		if (*src != '\0')
		{
			*dest = *src;

			src++;
			dest++;
		}
		else
		{
			while (tmp--)
			{
				*dest = 0;
				dest++;
			}
			break;
			
		}

	}
	return ret;
}
void Test_strncpy()
{
	char arr[5] = {'a','a','a','a','a'};
	char* p = "bbb";
	char* ret = my_strncpy(arr, p, 3);
	printf("%s\n", ret);
}
//####################################################

//一：创建一个计数器
int my_strlen(const char* p)
{
	assert(p != NULL);
	int count = 0;
	/*while (*p != '\0')
	{
		count++;
		p++;
	}*/
	while(*p++ )
	{
		count++;
	}
	return count;
}
//二：递归
int my_strlen_R(const char* p)
{
	assert(p);
	if (*p == '\0')
		return 0;
	else
		return 1 + my_strlen_R(p + 1);
}

//三：一个指针指向字符串首地址，一个指针指向'\0'，指针-指针得到的是两个指针中间有几个值
int my_strlen_use_point(const char* p)
{
	assert(p);
	const char* start = p;
	while (*start != '\0')
	{
		start++;
	}
	return start - p;
}
void Test_My_strlen()
{
	char *p = "Test strlen";
	int ret = my_strlen_use_point(p);
	printf("%d\n", ret);
}
//####################################################
//字符串追加：strcat
char* my_strcat(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* cur = dest;
	while (*cur != '\0')
	{
		cur++;
	} //找到目标字符串的'\0'
	while (*cur++ = *src++)
	{
		;
	}  //从目标的'\0'开始拷贝，直到将源字符串的'\0'拷贝过去
	return dest;
}
void Test_my_strcat()
{
	char arr[20] = "hello ";
	char* str = "world";
	printf("%s\n", arr);
	my_strcat(arr, str);
	printf("%s\n", arr);
}

//####################################################

//strncat:
char* my_strncat(char* dest, const char* src,int size)
{
	assert(dest);
	assert(src);
	char* cur = dest;
	int tmp = size - strlen(src);
	while (*dest != '\0')
	{
		dest++;
	} //找到目标字符串的'\0'
	while (size--)
	{
		if (*src != '\0')
		{
			*dest = *src;

			src++;
			dest++;
		}
		else
		{
			while (tmp--)
			{
				*dest = 0;
				dest++;
			}
			break;

		}

	}
	*dest = '\0';  //追加完之后会放'\0'
	return cur;
}

void Test_my_strncat()
{
	char arr[20] = "hello \0aaaaaaaaaaa";
	char* str = "world";
	printf("%s\n", arr);
	my_strncat(arr, str, 10);
	printf("%s\n", arr);
}
//####################################################
//字符串比较：strcmp
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	while (*str1 == *str2 )  //其中一个先遇到'\0'，就会不相等跳出循环
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
void Test_my_strcmp()
{
	char* str1 = "abbbc";
	char* str2 = "abbbc";
	int ret = my_strcmp(str1, str2);
	if (ret > 0)
		printf("str1 > str2");
	else if (ret == 0)
		printf("str1 == str2");
	else
		printf("str1 < str2");
}

//####################################################
//字符串比较：strncmp
int my_strncmp(const char* str1, const char* str2,int size)
{
	assert(str1);
	assert(str2);
	while (*str1 == *str2 && size >0)  //其中一个先遇到'\0'，就会不相等跳出循环
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
		size--;
	}
	return *str1 - *str2;
}
void Test_my_strncmp()
{
	char* str1 = "abbbcdd";
	char* str2 = "abbbc";
	int ret = my_strncmp(str1, str2,3);
	if (ret > 0)
		printf("str1 > str2");
	else if (ret == 0)
		printf("str1 == str2");
	else
		printf("str1 < str2");
}

//####################################################
//找子字符串：strstr
char* my_strstr(const char* str, const char* substr)
{
	assert(str);
	assert(substr);
	const char* str1 = NULL;
	const char* substr1 = NULL;//这两个指针由于长字符串和子字符串的不断比较
	const char* cur = str; //记录长字符串的开始比较位置
	if (*substr == '\0')
	{
		return (char*)str;
	}
	while (*cur)
	{
		str1 = cur;
		substr1 = substr;
		while (*str1 == *substr1 && *str1 && *substr1)
		{
			str1++;
			substr1++;
		}
		if (*substr1 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}
void Test_strstr()
{
	char* str = "abbbbbcdef";
	char* p = "bbc";
	char* ret = my_strstr(str, p);
	printf("%s\n", ret);
}

//这里还可以使用kmp算法
//
//####################################################
//strtok函数的使用：字符串切分
void Test_strtok()
{
	char *str = "tanghao@gmail.com";
	char *seq = "@.";
	char *arr[20] = {0};
	strcpy(arr, str);
	char* ret = NULL;
	for (ret = strtok(arr, seq); ret != NULL; ret = strtok(NULL, seq))
	{
		printf("%s\n", ret);
	}
}


//####################################################

//内存拷贝：memcpy
//memcpy完成的是不相干内存的拷贝，有内存重叠的拷贝是让memmove来完成的
void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
void Test_memcpy()
{
	int dest[10] = {0};
	int src[] = { 1,2,3,4,5,6,7 };
	printf_arr(dest, sizeof(dest) / sizeof(dest[0]));
	my_memcpy(dest, src, 5 * sizeof(src[0]));
	printf_arr(dest, sizeof(dest) / sizeof(dest[0]));
}
//####################################################
//memmove
//一定要考虑内存重叠的部分是从前向后拷贝，还是从后向前拷贝，才不会被覆盖
//目标指针<源指针：从前向后拷贝
void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	if (dest < src)
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else 
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
			//注意count进来已经-1了，就不需要再减一了
			//count自己会不断-1，dest和src就会不断向前走
		}
	}
	return ret;
}
void Test_memmove()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	printf_arr(arr, sizeof(arr) / sizeof(arr[0]));
	my_memmove(arr+2, arr, 4 * sizeof(arr[0])); 
	printf_arr(arr, sizeof(arr) / sizeof(arr[0]));
}
//####################################################

//源文件到可执行程序的过程：（翻译环境）
//每个源文件都会经过：预处理，编译，汇编，变成目标文件（二进制文件）
//最后所有的源文件加上 链接库 经过链接 变成 可执行程序
//预处理：gcc -E test.c -o test.i 进行的是文本操作：头文件的包含，注释的删除，#define定义的符号(常量和宏)的替换
//编译：gcc -s test.i -o test.s 将预处理完成的.i文件变成汇编代码，语法分析，词法分析，语义分析，符号汇总
//其中符号汇总是重点操作:将每个源文件的全局函数，全局变量，都进行汇总，提供给后续的使用
//汇编：gcc -c test.s -o test.o 将编译完成的汇编代码变成二进制指令，
//其中操作有：生成符号表，将编译阶段进行的符号汇总的符号和地址关联起来形成符号表，其中像是函数的声明，
//就会给一个无效的地址，在哪个源文件中定义的时候，这个函数符号才会有一个有效的地址
//目标文件都是elf格式的，查看符号表：readelf -s test.o
//
//所有的源文件都生成了自己的目标文件，链接器会将他们和链接库进行链接，
//其中操作有：合并段表，符号表的合并与重定位
//每个目标文件都会有自己的符号表，有的的无效的地址，
//链接的时候就会将每个目标文件的符号表合并，并且将函数声明这种无效的地址进行重定位，
//也就是找到这个函数定义的源文件中的符号表进行重定位，如果没找到，就会爆出链接错误。

//经过上面这一系列的过程，已经生成了可执行程序，
//可执行程序的运行环境：
//装入内存
//调用main函数（main函数之前还有函数已经执行了，并且调用了main函数，__mainCRTstart__函数）
//执行程序代码，调用运行时堆栈，栈里面存函数的局部变量和返回地址，
//堆给程序的多态内存申请提供空间，静态区存的是static 的静态变量，
//终止程序，可能正常终止，也可能异常终止（收到信号，或者断电）
//####################################################
//#define可以定义标识符常量和宏
//#define定义宏：将参数直接替换，宏就是把参数直接替换到文本当中
//  #：将宏的参数变成对应的字符串
//  ## ：把两边的符号合成一个符号
#define PRINT(value,format) printf("the value of " #value " is " format "\n",value)
#define SHOW(x,y) x##y
void Test_define()
{
	int a = 10;
	float f = 3.14f;
	printf("the value of a is %d\n", a);
	int Test_Show = 1024;
	int ret = SHOW(Test, _Show);
	printf("%d\n", ret);
	PRINT(f,"%f");
}


//宏的优点：
//1.宏是在预处理阶段直接进行参数的替换，执行的时候没有函数栈帧的开销,所以相比函数来说，效率高
//2.宏的参数没有类型的检查，使用的时候各种类型的数据都可以传，也可以传类型过去，使用灵活，解决了C语言没有函数模板的问题
//宏的缺点：
//1.宏没法调试，宏在预处理阶段就已经完成了替换，而调试是要在运行起来的环境下
//2.宏的参数与类型无关，既是可以灵活使用的优点，但同时也是缺点，不会严谨，容易出现问题
//所以宏适用于逻辑简单，代码短的逻辑实现。
//C++里面使用可以规避掉使用宏的时候，都可以使用inline内联函数来替代宏的使用
//#define定义标识符常量的时候，C++里面用const定义的常量可以代替使用
//#########################################################################################
//求第n个斐波拉且数：1 1 2 3 5 8 13 21
//递归：
int fib_R(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib_R(n - 1) + fib_R(n - 2);
	}
}

//循环：
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
void Test_fib()
{
	int ret_R = fib_R(8);
	int ret = fib(8);;
	printf("%d\n", ret_R);
	printf("%d\n", ret);

}
//#########################################################################################
//可变参数列表解析：
//写一个函数，实现传入的几个数求平均值
#include<stdarg.h>
int average(int n, ...)  //至少要有一个有名字的参数
{
	va_list arg;  //typedef char* va_list
	//char* arg;  //声明变量arg，用于访问参数列表的未确定部分
	va_start(arg, n);    //传入arg变量和未知参数列表的前面第一个有名字的参数
	//arg = (char*)&n + 4; //初始化arg，指向了未知参数的第一个
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);  //传入arg变量和下一个未知参数的类型，
		//sum += *(int*)((arg += 4) - 4);  //arg指向了下一个未知参数，但是返回的是这个未知参数
	}
	va_end(arg);  //将arg置为0
	//arg = (char*)0;

	return sum / n;
}
void Test_Average_use_variable_parameter()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int avg1 = average(2, a, b);
	int avg2 = average(3, a, b,c);
	printf("%d\n%d\n", avg1, avg2);
}

int Max_use_variable_parameter(int n, ...)
{
	va_list arg;
	va_start(arg, n);
	int max = va_arg(arg, int);
	for (int i = 0; i < n - 1; i++)
	{
		int tmp = va_arg(arg, int);
		if (max < tmp)
		{
			max = tmp;
		}
	}
	va_end(arg);

	return max;
}
void Test_Max_use_variable_parameter()
{
	int max = Max_use_variable_parameter(4, 1, 2, 3,5);
	printf("%d\n", max);
}

//可变参数实现类似printf的功能
// print("s ccc d \n","hello",'w','o','r','l','d',100);
void print_int(int num)
{
	if (num > 9)
	{
		print_int(num / 10);
	}
	putchar(num % 10 + '0');
}
void my_print(const char* format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		switch (*format)
		{
		case's':
		{
			char* str = va_arg(arg, char*);
			while (*str)
			{
				putchar(*str);
				str++;
			}
		}
		break;
		case'c':
		{
			char ch = va_arg(arg, char);
			putchar(ch);
		}
		break; 
		case'd':
		{
			int num = va_arg(arg, int);
			print_int(num);
		}
		break;
		default:
		{
			putchar(*format);
		}
		break;

		}
		format++;
	}
	va_end(arg);
}
void Test_my_printf()
{
	my_print("s ccccc d .\n", "hello", 'w', 'o', 'r', 'l', 'd', 100);
}

//#########################################################################################
//指针和数组的转换：

//test.c
//数组的定义
//char arr[] = "abcdef";
//main.c
//extern char* arr;
//int main()
//{
//	printf("%s\n", arr);//输出什什么？    
//	return 0;
//}
//定义的是一个数组，声明成指针
//数组arr的内容为："abcdef"
//指针arr是将前四个字节"abcd"理解为一个地址，%s输出是将这个地址解引用输出，会造成非法的地址访问
//如何解决：(char*)&(arr)
//现在的需求就是abcd被当成了一个地址，我需要找到a的地址，然后当成指针字符串%s输出


//char* p = "abcdef";
////main.c
////
//extern char p[];
//int main()
//{
//	printf("%s\n", p);//输出什什么？
//	return 0;
//}
//定义成为指针，声明为数组
//指针p的存的是字符串的首元素的地址，假设地址为0x0012ff44
//小端存储，内存里面存的就是44ff1200
//而这块空间被声明为数组，数组名p就是首元素的地址，也即是44的地址，从这块地址开始往后解引用找‘\0’输出（也就是以44的ASCII码值的字符，ff为ASCII码值的字符...直到找到‘\0’的ASCII码值才会停下来）
//如何解决：(char*)*(int*)p
//或者：*(char**)p

//#########################################################################################
//使用回调函数来实现通用的冒泡排序
struct info
{
	char name[20];
	int age;

};
void generic_swap(char* p1, char* p2,int width)
{
	while (width--)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;

	}
}

int cmp_info_age(const void* e1, const void* e2)
{
	return ((struct info*)e1)->age - ((struct info*)e2)->age;
}

int cmp_info_name(const void* e1, const void* e2)
{
	return strcmp(((struct info*)e2)->name, ((struct info*)e1)->name);
}
void generic_bubble_sort(void* base, int size, int width, int(*cmp)(const void* e1, const void* e2))
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (cmp((char*)base + j * width , (char*)base + (j + 1) * width ) > 0)
			{
				generic_swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void Test_generic_bubble_sort()
{
	struct info info[] = { {"zhangsan",20},{"lisi", 30},{"wangwu",40} };
	int size = sizeof(info) / sizeof(info[0]);
	generic_bubble_sort(info, size, sizeof(info[0]), cmp_info_name);
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void Test_qsort()
{
	int arr[] = { 1,4,7,2,6,5,8,3,9 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	struct info info[] = { {"zhangsan",20},{"lisi", 30},{"wangwu",40} };
	int info_size = sizeof(info) / sizeof(info[0]);
	//printf_arr(arr, arr_size);
	qsort(info, info_size, sizeof(info[0]), cmp_info_name);
	//printf_arr(arr, arr_size);
}

//#########################################################################################

int main()
{
	//prime_num();
	//Mul_table();
	//leap_year();
	//test_swap();
	//test_max();
	//three_max();
	//test_max_common_divisor();
	//test_swap_arr();
	//sum();
	//count_nine();
	//fac_sum_OP(4);
	//test_Binary_Search();
	//diamind_printf();
	//Aemstrong_Number();
	//Test_ItemNumberSum();
	//BacketsMatch();
	//count_one_bits_3(20);
	//Binary_odd_even(43690);
	//count_binary_different(1999, 2299);
	//Test_Bubble_Sort();
	//print_YangHuiTriangle();
	//Test_My_Strcpy();
	//Test_My_strlen();
	//Test_SWAP_BIT();
	//Test_reverse_bit();
	//Test_Average();
	//Test_find_num();
	//Test_reverse();
	//Test_define();
	//Test_Adjust_Arr();
	//TestYangMatrix();
	//Test_Rotate_string();
	//Test_Judge_Rotate_string();
	//Test_print_int_bit();
	//Test_My_strlen();
	//Test_fac();
	//Test_fib();
	//Test_Average_use_variable_parameter();
	//Test_Max_use_variable_parameter();
	//Test_My_strlen();
	//Test_Bubble_Sort_Use_Point();
	//Test_my_strcat();
	//Test_my_strcmp();
	//Test_strstr();
	//Test_memcpy();
	//Test_memmove();
	//Test_my_pow();
	//Test_Digit_Sum();
	//Test_reverse_str_R();
	//Test_my_printf();
	//Test_find_two_num();
	//Test_generic_bubble_sort();
	//Test_qsort();
	//Test_strncpy();
	//Test_my_strncat();
	//Test_my_strncmp();
	//Test_strtok();
	Test_atoi();
	system("pause");
	return 0;
}
//##########################################################################################