#include<stdio.h>
#include<math.h>

void main()
{
    double A, B, C;
    printf("enter A B C of pulinum");
    scanf("%lf %lf %lf",&A,&B,&C);// 5 -9 -7
    //printf("%lf %lf %lf",A,B,C); debug
    double AC = 4*A*C; //-140
    //printf("%lf\n",AC); debug
    double B_scr = B*B; //81
    //printf("%lf\n",B_scr); debug
    B_scr = B_scr - AC; //221
    //printf("%lf\n",B_scr); debug
    if (B_scr<0)
    {
        printf("NO REAL SOLUTIONS\n");
    }else{
        B_scr = sqrt(B_scr); //14.866
        //printf("%lf\n",B_scr); debug
        B *= -1;
        //printf("%lf\n",B); debug
        if (B_scr == 0)
        {
            printf("ONE REAL SOLUTION\n");
            double ans1;
            ans1 = B / 2*A;
            printf("ans1 = %f",ans1);
        }else
        {
            printf("TWO REAL SOLUTIONS\n");
            double ans1,ans2; 
            ans1 = (B - B_scr);
            ans2 = (B + B_scr);
            ans1 = ans1 / (2*A);
            ans2 = ans2 / (2*A);
            printf("ans1 = %f\nans2 = %f",ans1,ans2);
        }
    }
}