
//In the Name of God
 
#include <stdio.h>
#include <stdlib.h>


#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

int c[6000];
int n ;
int k ;

int findMx ( int x ) {
  int Max1 = 0 ;
  int Max2 = 0 ;
  for ( int i = 0 ; i < x ; i ++ )
    Max1 = max ( Max1 , c[i] ) ;
  for ( int i = x ; i < n ; i ++ )
    Max2 = max ( Max2 , c[i] ) ;

  
  return min ( Max1 , Max2 ) ;



}
int main () {
 
  scanf ("%d%d" , &n , &k ) ;
  for ( int i = 0 ; i < n ; i ++ )
    scanf ( "%d" , &c[i] ) ;
  int Min = 1e5 ;
  int Max = 0 ;
  for ( int i = 0 ; i < n ; i ++ ) {
    Min = min ( Min , c[i] ) ;
    Max = max ( Max , c[i] ) ;
  }

  if ( k == 1 ) {
    printf ("%d" , Max ) ;
    return 0 ;
  }

  if ( k >= 3 ) {
    printf ("%d" , Min ) ;
    return 0 ;
  }

  Min = 1e5 ;

  for ( int i = 1 ; i < n ; i ++ )
    Min = min ( Min , findMx(i) ) ;

  printf ("%d" ,  Min ) ;
  


  
  return 0 ;
}
