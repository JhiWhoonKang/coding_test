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

//괄호 검사 로직
char* VPS(char* data)
{
	int _bracket_cnt_ = 0;
	int _len_ = strlen(data);
	//입력 받은 괄호 길이 만큼 반복
	for (int i = 0; i < _len_; ++i)
	{
		if (data[i] == '(')
		{
			_bracket_cnt_++; // ( -> 증가
		}
		else
		{
			_bracket_cnt_--; // ) -> 증가
			if (_bracket_cnt_ < 0)
			{
				return "NO"; // 근데 (보다 )가 더 큰 경우는 없으므로 이때는 NO ex. )( => 군형은 맞는데 순서가 틀린 경우임
			}
		}
	}

	return (_bracket_cnt_ == 0) ? "YES" : "NO"; // 그래서 (와 ) 균형이 맞으면 YES 아니면 NO
}