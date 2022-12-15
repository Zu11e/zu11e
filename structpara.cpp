#include <stdio.h>
#include <conio.h>
 
struct product
{
    float first;
    int second;
};
 
int main()
{
    product tov;
    printf("Enter cost -> ");
    scanf("%f",&tov.first);
    printf("Enter number -> ");
    scanf("%d",&tov.second);
    printf("Result -> %.4f",(tov.first*tov.second));
    getch();
    return 0;
 
}