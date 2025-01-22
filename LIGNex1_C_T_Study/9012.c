#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char* VPS(char* data);

int main(void)
{
	int T;
	(void)scanf("%d", &T);

	for (int i = 0;i < T;++i)
	{
		char str[51];
		(void)scanf(" %s", str);

		printf("%s\n", VPS(str));
	}	

	return 0;
}

//��ȣ �˻� ����
char* VPS(char* data)
{
	int _bracket_cnt_ = 0;
	int _len_ = strlen(data);
	//�Է� ���� ��ȣ ���� ��ŭ �ݺ�
	for (int i = 0; i < _len_; ++i)
	{
		if (data[i] == '(')
		{
			_bracket_cnt_++; // ( -> ����
		}
		else
		{
			_bracket_cnt_--; // ) -> ����
			if (_bracket_cnt_ < 0)
			{
				return "NO"; // �ٵ� (���� )�� �� ū ���� �����Ƿ� �̶��� NO ex. )( => ������ �´µ� ������ Ʋ�� �����
			}
		}
	}

	return (_bracket_cnt_ == 0) ? "YES" : "NO"; // �׷��� (�� ) ������ ������ YES �ƴϸ� NO
}