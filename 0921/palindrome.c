//ȸ��(Palindrome)
//�� �ڰ� �Ȱ��� ���� ȸ��(Palindrome) �̶�� �մϴ�.

#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int Palindrome(char str[]);
int main()
{
    char test_str[100] = "abcdedcba";
        if (Palindrome(test_str))//ȸ���� ������
        {
            printf("%s �� ȸ����\n", test_str);
        }
        else//ȸ���� �ƴϸ�
        {
            printf("%s �� ȸ���� �ƴ�\n", test_str);
        }

    return 0;
}
int Palindrome(char str[])
{
    int len = 0;
    int i = 0;
    //������ ����(�ι���)�� ���ö����� �̵�
    for (len = 0; str[len]; len++); //len = strlen(str); �� ���� �ڵ��Դϴ�.
    for (i = 0; i<(len / 2); i++)//i�� 0~len/2���� �̵��ϸ鼭 �ݺ�
    {
        if (str[i] != str[len - i - 1])//str[i]�� str[len-i-1]�� ���� �ٸ���
        {
            return 0;//ȸ���� �ƴϹǷ� 0 ��ȯ
        }
    }
    return 1;//ȸ���̹Ƿ� 1 ��ȯ

}
