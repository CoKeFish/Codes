
void showNumber(int digit);
void showNumbers(int *digits);
int* seg7(const int * iBCD);
int* BinTOBcd(long iADC);
long readADC();
void init_UART();
void UART_write(char c);
void UART_print(unsigned char* cadena);
char* ASCII_Con(int a, int b, int c);