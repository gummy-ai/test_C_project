#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("info.txt","w");

    if (fp == NULL)
    {
        perror("file opening fail");
        return 1;
    }

    int input;
    printf("이름과 나이를 순서대로 입력하세요:");
    while ((input = getchar()) != '\n')
    {
        fputc(input,fp);
    }
    fputc('\n',fp);
    printf("\n");
    fclose(fp);

    FILE *fp2 = fopen("info.txt","r");

    if (fp2 == NULL)
    {
        perror("file opening fail");
        return 1;
    }

    int ch;
    while(1)
    {
        ch = fgetc(fp2);
        if (ch == EOF)
            break;
        printf("%c",ch);
    }
    fclose(fp2);

    return 0;
}

// 1. 모드쓸 때 ''인지 ""인지 헷갈림 - > "" 이다
// 2. while((ch=getchar()) != \n) 와 비슷한 표현을 본거 같은데... -> 맞음 단지 ''빼먹음
// 3. NULL 대비 하기
// 4. 쓰기모드 까먹어서 기억 잘 안 남 (1. fputc 2. fprintf)
// -> 4.1 fputc 하겠다 ch를 fp스트림에 fputc(ch,fp) -> (getchar()랑 연계)
// -> 4.2 이건 그냥 fprintf(fp,"%s","text"); 이렇게 쓰면 됨

/* 피드백 1. 마지막에 널문자 넣어서 읽을 때 혹시 모를 오류 방지
    while ((input = getchar()) != '\n')
    {
        fputc(input,fp);
    }
    fputc('\n',fp);
*/