int i;
int j;

extern int printd( int i );
extern int printd( int i );


void main() {
   for (i=0; i<10; i=i+1) {
	if (i==5) break;
   }
   printd(printd(i));
   printd(i);
   printd(i);
   return;
}
