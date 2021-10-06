#include<stdio.h>
void main(void)
{
    float grade = 0.0;
    float total = 0.0;
    float average = 0.0;
    char ch;
    int countg = 0;
    float f_num = 0.0;
    int temp;
    printf("Compute the average grades.\n");
    Loop:
        printf("Enter grade (Esc to terminate): ");
        int counter  = 0;
        int countf = 0;
        int i_num = 0;
    while((ch=getch()) != 27)
    {
            switch(ch)
            {
            case '0'...'9':
                putch(ch);
                i_num = i_num*10+ch-'0';
                counter++;
                break;
            case 8:
                if(counter > 0)
                {
                    if(counter == 1) i_num = 0;
                    else temp = i_num % 10;
                    putch('\b');
                    putch(' ');
                    putch('\b');
                    counter--;
                }
                i_num = (i_num-temp)/10;
                break;
            case '.':
                putch(ch);
                while((ch=getch()))
            {
            switch(ch)
            {
            case '0'...'9':
                putch(ch);
                i_num = i_num*10+ch-'0';
                countf++;
                break;
            case 8:
                if(counter > 0)
                {
                    if(counter == 1) i_num = 0;
                    else temp = i_num % 10;
                    putch('\b');
                    putch(' ');
                    putch('\b');
                    countf--;
                }
                i_num = (i_num-temp)/10;
                break;
            case '\r':
                f_num = i_num;
                while(countf > 0)
                {
                f_num /= 10;
                countf--;
                }
                grade = f_num;
                countg++;
                total += grade;
                printf("\n");
                goto Loop;
                break;
            case 27:
                goto Res;
                break;
            default:
                putch(ch);
                printf("\nInvalid input\n");
                goto Loop;
                break;
            }
        }
            case '\r':
                f_num = i_num;
                while(countf > 0)
                {
                f_num /= 10;
                countf--;
                }
                grade = f_num;
                countg++;
                total += grade;
                printf("\n");
                goto Loop;
                break;
            default:
                putch(ch);
                printf("\nInvalid input\n");
                goto Loop;
                break;
    }
    }
    Res:
        average = total / countg;
        printf("\n");
        printf("%.2f\n",average);
}
