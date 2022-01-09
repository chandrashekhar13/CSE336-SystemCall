#include<stdio.h>

int main()
{
    int r = 5000;      ///tm = number of execution
    for(int i=0;i<r;i++){          
        FILE *ptr;
        ///Note a new file isn't created if it doesn't exist.So For checking multiple times,
        /// I manually set the value of num.txt to 0.
        ptr = fopen("./num.txt", "r");          
        int a=-1;
        fscanf(ptr,"%d",&a);
        fclose(ptr);
        ptr = fopen("./num.txt","w");
        fprintf(ptr,"%d\n",a+1);
        // printf("a = %d\n",a);
        fclose(ptr);
    }
}
