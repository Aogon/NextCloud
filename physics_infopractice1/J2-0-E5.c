//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//�@C�����p�v���O����
//  �P�U��: Euler�@���p�����V�~�����[�V����
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <stdio.h>

int main( void )
{

  double x, v, xb, vb;
  double dt, t;
  double E;
  int i,N;

// N�F�J���Ԃ�����
  N = 10000;

// ���ݕ�
  dt = 1.0e-2;

// �����l
  i = 0;
  t = 0.0e0;
  x = 1.0e0;
  v = 0.0e0;

  xb = 1.0e0;
  vb = 0.0e0;

  printf("%d %e %e %e \n", i, t, x, v );

  for(i=0;i<=N;i++){
    t = dt * i;
    x = xb + dt * vb;
    v = vb - dt * xb; 
//  v = vb - dt * x;

    xb = x;
    vb = v;
    printf("%d %e %e %e \n", i, t, x, v );

      }


  return 0;
}
