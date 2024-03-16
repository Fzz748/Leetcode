#include <stdio.h>
#include <stdlib.h>

typedef float fp32;
typedef char uint8;

void CharToFloat(uint8* pdat, fp32* pfvalue)
{
  fp32 a;
  uint8 i, *pch;
  void* pf;
  pch =  pdat;
  pf = &a;
  for(i=0; i<4; i++)
  {
    *((uint8*)pf+i) = *(pch + 3 - i);
    pch++;
  }
  *pfvalue = a;

}

void CharToFloat2(uint8* pdat, fp32* pfvalue)
{
  fp32 a;
  uint8 i, *pch;
  void* pf;
  pch =  pdat;
  pf = &a;
  for(i=0; i<4; i++)
  {
    *((uint8*)pf+i) = *(pch + i);
    pch++;
  }
  *pfvalue = a;

}

void main()
{
  double A = 99.99;
  float *pB = NULL;

  pB = (float *)malloc(sizeof(float));
  *pB = (float)A;
  *pB = 0.0;
  printf("a : %f\n", A);

}