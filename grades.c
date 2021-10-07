#include<stdio.h>
void main(void)
{
    float grade = 0.0;
    float total = 0.0;
    char ch;
    int countg = 0;
    int temp;
    printf("Compute the average grades.");
    Loop:
        printf("\nEnter grade (Esc to terminate): ");
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
    L1:     case 8:
                if(counter-- >= 0)
                {
                    if(counter == 1) i_num = 0;
                    else temp = i_num % 10;
                    putch('\b');
                    putch(' ');
                    putch('\b');
                }
                i_num = (i_num-temp)/10;
                break;
    L2:     case '.':
                putch(ch);
                while((ch=getch()))
            {
            switch(ch)
            {
            case '0'...'9':
                putch(ch);
                i_num = i_num*10+ch-'0';
                countf++; counter++; break;
            case 8:
                goto L1;
    L3:     case '\r':
                grade = i_num;
                while(countf-- > 0){grade /= 10;}
                countg++;
                total += grade;
                goto Loop; break;
            case 27: goto Res; break;
            case '.': goto L2;
    L4:     default:
                putch(ch);
                printf("\nInvalid input");
                goto Loop; break;
            }
        }
            case '\r': goto L3;
            default: goto L4;
    }
    }
    Res:
        printf("\n%.2f\n",total / countg);
}
