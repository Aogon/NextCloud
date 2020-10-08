//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//�@C����p�v���O����
//  �����^��1�F�I�C���[�@�ɂ��V�~�����[�V����
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


#include <stdio.h>

int main( void )
{

  double x, v, xb; 
  double t, dt, dti; 
  double xs, xe; 
  int i, N;
 
// N�F�J��Ԃ��� 
  N = 1000;

// ���ݕ� 
  dt = 1.0e-2;

// �����l 
  t  = 0.0e0;
  x  = 0.0e0;
  v  = 1.0e0;
  xb = 0.0e0;
  i  = 0;

// ���E�̈ʒu 
  xs = -1.0e0;
  xe = 1.0e0;
  
  printf("%d %e %e \n",i, t, x);
    
  for(i=1;i<=N;i++){
    t = t + dt;
    x = xb + dt * v;

    if( x >= xe ){
      dti = dt * (x - xe)/(x - xb);           
      x = xe;
      t = t  - dti;
      v = -v;
    }
    
    if( x <= xs ){
      dti = dt * (xs - x)/(xb - x);           
      x = xs;
      t = t - dti;
      v = -v;
    }

    xb=x;
    printf("%d %e %e \n",i, t, x); 
					
  }
   
 
  return 0;
}
  
