#include <stdio.h>

#define MAX 10000
int main(void)
{
    // 파일 입출력
    // 파일에 어떤 데이터를 저장
    // 파일에 저장된 데이터 불러오기

    // fputs, fgets
    char line[MAX]; //char line[10000];
    // 파일에 쓰기
    FILE * file = fopen("c:\\test1.txt","rb"); // r w a 각각 읽기,쓰기,업앤드(이어쓰기)
    // t b 텍스트,바이너리 데이터를 의미
    if (file == NULL)
    {
        printf("파일 열기 실패\n");
        return 1;
    }
    // fputs("fputs 를 이용해서 글을 적어볼게요:\n",file);
    // fputs("잘 적히는지 확인해주세요\n",file);

    while (fgets(line,MAX,file) != NULL)
    {
        printf("%s",line);
    }
    // fclose(file);

    // fprintf fscanf
    int num[6] = {0};
    int bonus = 0;
    char str1[MAX];
    char str2[MAX];
    FILE * file = fopen("c:\\test2.txt","wb");
    if (file==NULL)
    {
        printf("파일 열기 실패\n");
    }
    fprintf(file,"%s %d %d %d %d %d %d\n","추첨 번호",1,2,3,4,5,6);
    fprintf(file,"%s %d\n","보너스번호",7);

    fclose(file);
    return 0;
}