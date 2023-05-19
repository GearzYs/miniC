int i;
int j;
int i;

extern int printd( int i );

int main() {
   int i;
   int j;
   for (i=0; i<10; i=i+1) {
	if (i==5) break;
   }
   printd(i);
   printd(i);
   printd(i);
   return i+3;
}
