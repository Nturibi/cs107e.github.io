extern int __bss_start__;
extern int __bss_end__;

extern void main();
 
void _cstart() {
  /* Zero out BSS */
  int* bss = &__bss_start__;
  int* bss_end = &__bss_end__;
  while( bss < bss_end )
    *bss++ = 0;
  
  main(); 
}
