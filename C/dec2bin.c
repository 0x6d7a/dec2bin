#include <stdlib.h>
#include <stdio.h>

void dec2bin(double number) {

    char *ret = malloc(16 * sizeof(char));
    char neg = 0; 

    if(number < 0) {
        number *= -1;
        neg = 1;
    }
    
    int integer = (int)number;
    double frac = number - integer;
    
    for (int i = 0; i < 16; i++)
    {
        ret[i] = (integer & (1 << (16 - i - 1))) != 0 ? 1: 0;
        printf("%d", ret[i]);
        if (i > 1 && !((i+1)%4) && i != 15)
        {
            printf(" ");
        }
    }

    if(frac != 0) {
        printf(" ");
        dec2bin((int)(frac * (1<<16)));
    }

    free(ret);
}

long double decTobin(long double fraDecimal, int precision){
   
    long double fraBinary,bFractional = 0.0,dFractional,fraFactor=0.1;
    long int dIntegral,bIntegral=0;
    long int intFactor=1,remainder,temp,i;
   
    dIntegral = fraDecimal;
    dFractional = fraDecimal - dIntegral;

    while(dIntegral!=0){
         remainder=dIntegral%2;
         bIntegral=bIntegral+remainder*intFactor;
         dIntegral=dIntegral/2;
         intFactor=intFactor*10;
    }

   for(i=1; i<= precision;i++){
      
       dFractional = dFractional * 2;
       temp =  dFractional;
        
       bFractional = bFractional + fraFactor* temp;
       if(temp ==1)
             dFractional = dFractional - temp;

       fraFactor=fraFactor/10;
   }
  
   fraBinary =  bIntegral +  bFractional;
   
   return fraBinary;
}

int main(int argc, char const *argv[])
{
    double number;
    printf("Decimal input: ");
    scanf ("%lf", &number);
    printf("\nDouble: %f;\nQ16 Binary: ", number);
    dec2bin(number);

    printf("\nEquivalent binary value: %LF", decTobin(number, 16));
    return 0;
}
