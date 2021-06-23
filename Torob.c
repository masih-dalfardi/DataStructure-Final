//In the Name of God

#include <stdio.h>
#include <stdlib.h>


#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

char a[110][110] ;

void print ( int can ) {
  if ( can == 1 )
    printf ("possible") ;
  else
    printf("impossible" ) ;
}

int main () {
 
 
  int n , m , s ;

  scanf ("%d%d%d" , &n , &m , &s ) ;
  if ( s > m * n ) {
    print(0) ;
    return 0 ;
  }
  if ( (n == 1 && m % 2 == 0 && s % 2 == 1 ) || ( n % 2 == 0 && m == 1 && s % 2 == 1 ) ) {
     print(0) ;
    return 0 ;
  }

  if ( n % 2 == 0 && m == 1 && s % 2 == 0 ) {
    for ( int i = 0 ; i < (n/2)-(s/2) ; i ++ )
      a[i][0] = 'E' ;
    for ( int i = (n/2)-(s/2) ; i < (n/2)+(s/2) ; i ++ )
      a[i][0] = 'T' ;
    for ( int i = (n/2)+(s/2) ; i < n ; i ++ )
      a[i][0] = 'E' ;

     print(1) ;
     printf ("\n" );
     for ( int i = 0 ; i < n ; i ++ ) 
       printf ("%c\n" , a[i][0] ) ;
    return 0 ;
    
  }
  if ( n == 1 && m % 2 == 0 && s % 2 == 0 ) {
    for ( int i = 0 ; i < (m/2)-(s/2) ; i ++ )
      a[0][i] = 'E' ;
    for ( int i = (m/2)-(s/2) ; i < (m/2)+(s/2) ; i ++ )
      a[0][i] = 'T' ;
    for ( int i = (m/2)+(s/2) ; i < m ; i ++ )
      a[0][i] = 'E' ;

     print(1) ;
     printf("\n") ;
    for ( int i = 0 ; i < m ; i ++ )
      printf("%c" , a[0][i]) ;
    return 0 ;
    


  }
  if ( n == 1 && m % 2 == 1 && s % 2 == 1 ) {
    for ( int i = 0 ; i < (m/2)-(s/2) ; i ++ )
      a[0][i] = 'E' ;
    for ( int i = (m/2)-(s/2) ; i <= (m/2)+(s/2) ; i ++ )
      a[0][i] = 'T' ;
    for ( int i = ((m/2)+(s/2))+1 ; i < m ; i ++ )
      a[0][i] = 'E' ;

     print(1) ;
     printf("\n") ;
    for ( int i = 0 ; i < m ; i ++ )
      printf("%c" ,  a[0][i] ) ;
    return 0 ;

  }
  if ( n == 1 && m % 2 == 1 && s % 2 == 0 ) {
    for ( int i = 0 ; i < (m/2)-(s/2) ; i ++ )
      a[0][i] = 'E' ;
    for ( int i = (m/2)-(s/2) ; i < m/2 ; i ++  )
      a[0][i] = 'T' ;
    a[0][m/2] = 'E' ;
    for ( int i = (m/2)+1 ; i <= (m/2) + (s/2) ; i ++ )
      a[0][i] = 'T' ;
    for ( int i = (m/2)+(s/2)+1 ; i < m ; i ++ )
      a[0][i] = 'E' ;
    
     print(1) ;
     printf("\n") ;

    for ( int i = 0 ; i < m ; i ++ )
      printf ("%c" , a[0][i]) ;
    return 0 ;
  }



  
  if ( n % 2 == 0 && m % 2 == 0 ) {
    if ( s % 2 ) {
      print (0) ;
      return 0 ;
    }
    int t = s/2 ;
    int cut = 0 ;
    int EE = 0 ;
    for ( int i = (n/2)-1 ; i >= 0 ; i -- ) {
      for ( int j = 0 ; j < m ; j ++ ) {
  if ( cut == 0 ) {
    a[i][j] = 'T' ;
    t -- ;
  }
  if ( t == 0 && EE == 0 ) {
    cut = 1 ;
    EE = 1 ;
    continue ;
  }
  
  if ( cut == 1 && EE == 1 )
    a[i][j] = 'E' ;
      }
    }
    t = s/2 ;
    cut = 0 ;
    EE = 0 ;
    for ( int i = n/2 ; i < n ; i ++ )  {
      for ( int j = 0 ; j < m ; j ++ ) {
  if ( cut == 0 ) {
    a[i][j] = 'T' ;
    t -- ;
  }
  if ( t == 0 && EE == 0 ) {
    cut = 0 ;
    EE = 1 ;
    continue ;
  }
  
  if ( cut = 1 && EE == 1 )
    a[i][j] = 'E' ;
      }
    }
  }
  else {
    if ( n % 2 ) {
      if ( s <= m ) {
  for ( int i = 0 ; i < n ; i ++ ) {
    if ( i != n / 2 ) {
      for ( int j = 0 ; j < m ; j ++ )
        a[i][j] = 'E' ;
    }
    else {
      int j = 0 ;
      for ( j = 0 ; (j < m) && (s > 0) ; j ++ , s -- )
        a[i][j] = 'T' ;
      if ( j <= m ) {
        for ( int k = j ; k < m ; k ++ )
    a[i][k] = 'E' ;
      }
      
    }
  }
      }
      else {
  if ( (s-m) % 2 == 0 ) {
    int f = s-m ;
    for ( int i = 0 ; i < n ; i ++ ) {
      if ( i != n / 2 ) {
        for ( int j = 0 ; j < m ; j ++ )
    a[i][j] = 'E' ;
      }
      else {
        int j = 0 ;
        for ( j = 0 ; j < m ; j ++ )
    a[i][j] = 'T' ;
      }
    }
    int t = f/2 ;
    int cut = 0 ;
    int EE = 0 ;
    for ( int i = (n/2)-1 ; i >= 0 ; i -- ) {
      for ( int j = 0 ; j < m ; j ++ ) {
        if ( cut == 0 ) {
    a[i][j] = 'T' ;
    t -- ;
        }
        if ( t == 0 && EE == 0 ) {
    cut = 1 ;
    EE = 1 ;
    continue ;
        }
  
        if ( cut == 1 && EE == 1 )
    a[i][j] = 'E' ;
      }
    }
    t = f/2 ;
    cut = 0 ;
    EE = 0 ;
    for ( int i = (n/2)+1 ; i < n ; i ++ )  {
      for ( int j = 0 ; j < m ; j ++ ) {
        if ( cut == 0 ) {
    a[i][j] = 'T' ;
    t -- ;
        }
        if ( t == 0 && EE == 0 ) {
    cut = 0 ;
    EE = 1 ;
    continue ;
        }
  
        if ( cut = 1 && EE == 1 )
    a[i][j] = 'E' ;
      }
    }
    
    

  }
  else {
    // todo
    int f = s-m+1 ;
    for ( int i = 0 ; i < n ; i ++ ) {
      if ( i != n / 2 ) {
        for ( int j = 0 ; j < m ; j ++ )
    a[i][j] = 'E' ;
      }
      else {
        int j = 0 ;
        for ( j = 0 ; j < m-1 ; j ++ )
    a[i][j] = 'T' ;
        a[i][m-1] = 'E' ;
      }
    }
    int t = f/2 ;
    int cut = 0 ;
    int EE = 0 ;
    for ( int i = (n/2)-1 ; i >= 0 ; i -- ) {
      for ( int j = 0 ; j < m ; j ++ ) {
        if ( cut == 0 ) {
    a[i][j] = 'T' ;
    t -- ;
        }
        if ( t == 0 && EE == 0 ) {
    cut = 1 ;
    EE = 1 ;
    continue ;
        }
  
        if ( cut == 1 && EE == 1 )
    a[i][j] = 'E' ;
      }
    }
    t = f/2 ;
    cut = 0 ;
    EE = 0 ;
    for ( int i = (n/2)+1 ; i < n ; i ++ )  {
      for ( int j = 0 ; j < m ; j ++ ) {
        if ( cut == 0 ) {
    a[i][j] = 'T' ;
    t -- ;
        }
        if ( t == 0 && EE == 0 ) {
    cut = 0 ;
    EE = 1 ;
    continue ;
        }
  
        if ( cut = 1 && EE == 1 )
    a[i][j] = 'E' ;
      }
    }
    

  }



      }
      
      
      
    }
    else {
      
      if ( s <= n  ) {
  for ( int i = 0 ; i < m ; i ++ ) {
    if ( i != m / 2 ) {
      for ( int j = 0 ; j < n ; j ++ )
        a[j][i] = 'E' ;
    }
    else {
      int j = 0 ;
      for ( j = 0 ; (j < n) && (s > 0) ; j ++ , s -- )
        a[j][i] = 'T' ;
      if ( j <= n ) {
        for ( int k = j ; k < n ; k ++ )
    a[k][i] = 'E' ;
      }
      
    }
  }
      }
      else {
  if ( (s-n) % 2 == 0 ) {
    int f = s-n ;
    for ( int i = 0 ; i < m ; i ++ ) {
      if ( i != m / 2 ) {
        for ( int j = 0 ; j < n ; j ++ )
    a[j][i] = 'E' ;
      }
      else {
        int j = 0 ;
        for ( j = 0 ; j < n ; j ++ )
    a[j][i] = 'T' ;
      }
    }
    int t = f/2 ;
    int cut = 0 ;
    int EE = 0 ;
    for ( int i = (m/2)-1 ; i >= 0 ; i -- ) {
      for ( int j = 0 ; j < n ; j ++ ) {
        if ( cut == 0 ) {
    a[j][i] = 'T' ;
    t -- ;
        }
        if ( t == 0 && EE == 0 ) {
    cut = 1 ;
    EE = 1 ;
    continue ;
        }
  
        if ( cut == 1 && EE == 1 )
    a[j][i] = 'E' ;
      }
    }
    t = f/2 ;
    cut = 0 ;
    EE = 0 ;
    for ( int i = (m/2)+1 ; i < m ; i ++ )  {
      for ( int j = 0 ; j < n ; j ++ ) {
        if ( cut == 0 ) {
    a[j][i] = 'T' ;
    t -- ;
        }
        if ( t == 0 && EE == 0 ) {
    cut = 0 ;
    EE = 1 ;
    continue ;
        }
  
        if ( cut = 1 && EE == 1 )
    a[j][i] = 'E' ;
      }
    }
    }
  else {
    // todo
    int f = s-n+1 ;
    for ( int i = 0 ; i < m ; i ++ ) {
      if ( i != m / 2 ) {
        for ( int j = 0 ; j < n ; j ++ )
    a[j][i] = 'E' ;
      }
      else {
        int j = 0 ;
        for ( j = 0 ; j < n-1 ; j ++ )
    a[j][i] = 'T' ;
        a[n-1][i] = 'E' ;
      }
    }
    int t = f/2 ;
    int cut = 0 ;
    int EE = 0 ;
    for ( int i = (m/2)-1 ; i >= 0 ; i -- ) {
      for ( int j = 0 ; j < n ; j ++ ) {
        if ( cut == 0 ) {
    a[j][i] = 'T' ;
    t -- ;
        }
        if ( t == 0 && EE == 0 ) {
    cut = 1 ;
    EE = 1 ;
    continue ;
        }
  
        if ( cut == 1 && EE == 1 )
    a[j][i] = 'E' ;
      }
    }
    t = f/2 ;
    cut = 0 ;
    EE = 0 ;
    for ( int i = (m/2)+1 ; i < m ; i ++ )  {
      for ( int j = 0 ; j < n ; j ++ ) {
        if ( cut == 0 ) {
    a[j][i] = 'T' ;
    t -- ;
        }
        if ( t == 0 && EE == 0 ) {
    cut = 0 ;
    EE = 1 ;
    continue ;
        }
  
        if ( cut = 1 && EE == 1 )
    a[j][i] = 'E' ;
      }
    }
    

  }



      }
      
     
    }
  

  }
    


  print(1) ;
  printf("\n") ;

  for ( int i = 0 ; i < n ; i ++ ) {
    for ( int j = 0 ; j < m ; j ++ )
      printf ( "%c" , a[i][j] ) ;
    printf("\n") ;   
  }
  
  return 0 ;
}
