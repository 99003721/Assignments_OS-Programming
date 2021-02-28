#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

volatile int add;
volatile int remove_h;
volatile int volatile buffer[16];

void clearbuffer()
{
add = 0; remove_h = 0;
for( int i=0; i<16; i++ ) 
{ 
     buffer[i] = 0;
      }
}

int next( int present )
{
return ( present+1 ) & 15;
}
void addtobuffer( int data_val )
{
while( next(add) == remove_h )
 {

} 
{ printf( "Circular buffer error Occur\n" );
 exit(1); 
 }
     buffer[add] = data_val;  
     add = next(add);  
     }         
int removefrombuffer()
{
int data_val;
while( ( data_val = buffer[remove_h] ) == 0 )
{

}
 buffer[remove_h] = 0;  
remove_h = next(remove_h);
return data_val;                  
}