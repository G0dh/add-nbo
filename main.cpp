#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int agrc, char **agrv )
{
    FILE *fp1, *fp2;                            
    fp1 = fopen("thousand.bin", "rb");      // LOAD thousand.bin
    fp2 = fopen("five-hundred.bin","rb");    // LOAD five-hundred.bin
    
    uint32_t a1,a2,b1,b2,sum;

    fread(&a1,sizeof(int),4,fp1);
    fread(&a2,sizeof(int),4,fp2);

    b1 = ntohl(a1);
    b2 = ntohl(a2);

    sum = b1 + b2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",b1,b1,b2,b2,sum,sum);  // OUTPUT


    fclose(fp1);
    fclose(fp2);
    return 0;
}
