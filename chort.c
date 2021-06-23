
//In the Name of God
 
#include <stdio.h>
#include <stdlib.h>


#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

struct pair {
    int X ;
    int Y ;
};

struct pair a[100000+10] ;
int n ;
int T ;
int Time[100000+10] ;
int En[100000+10] ;
int main () {
 
  scanf ("%d%d" , &n, &T) ;
  for ( int i = 0 ; i < n ; i ++ ) {
    int t , e ;
    scanf ("%d%d" , &t, &e) ; 
    a[i].X = t ;
    a[i].Y = e ;
  }
  Time[0] = a[0].X ;
  En[0] = a[0].Y ;
  for ( int i = 1 ; i < n ; i ++ ) {
    Time[i] = Time[i-1] + a[i].X ;
    En[i] = En[i-1] + a[i].Y ;
  }
  int i = 0 ;
  for ( i = 0 ; i < n ; i ++ ) {
    if ( Time[i] > T )
      break ;
  }
  if ( i > 0 ) {
  i -- ;
  int Max = -987654321 ;
  for ( int j = 0 ; j <= i ; j ++ ) 
    Max = max ( Max , En[j] - ( T - Time[j] ) ) ;
  printf ("%d" ,  max(Max , -T )) ;
  return 0 ;
  }
  int Max = -987654321 ;
  for ( int j = 0 ; j < n ; j ++ ) 
    Max = max ( Max , En[j] - ( T - Time[j] ) ) ;
  printf("%d" ,  max(Max , -T)) ;

  

  return 0 ;
}
