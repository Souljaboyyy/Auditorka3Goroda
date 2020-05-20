#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	char left = 8, right = 1;
	int flag = 0,flag2=0;
	int big[26] = { 0 };
	int small[26] = { 0 };
	FILE *fp;
	fopen_s(&fp, "goroda.txt", "w");
	printf("Введите города через пробел,английскими буквами,c большой буквы,чтобы выйти нажмите 0 :) \n");
	while (right != '0') {
		right = getche();
		if (right == ' ')
			printf("\n");
		fprintf(fp,"%c", right);
	}
	fclose(fp);
	fopen_s(&fp, "goroda.txt", "r");
	left = fgetc(fp);
	big[(int)left - 65] += 1;
	while (left != '0')
	{
		right = fgetc(fp);
		if ((right == ' ')|| (right == '0'))
			small[(int)left - 97] += 1;
		if (left == ' ')
			big[(int)right - 65] += 1;
		if ((right == '0') && (left == ' '))
			small[11] -= 1;
		left = right;
	}
	for (int i = 0; i < 26; i++)
		if (big[i] != small[i])
			flag++;
	if (flag > 2)
		printf("\nНет\n");
	else
		printf("\nДа\n");
	

	system("pause");
	return 0;
}