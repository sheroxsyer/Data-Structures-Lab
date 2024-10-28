Question#2

(a)
int *number;
	cout << number << endl;
	
	In the above statemeents an integer pointer is declared called number but in the sencond line the address of number is printing.
	To print the value of number then type
	cout<<*number<<endl;

(b)
double *realPtr;
	long *integerPtr;
	integerPtr = realPtr;	
	
	In the above statements the a double pointer called realPtr is declared.
	A second long pointer called integerPtr is declared. The third statement cannot be executed because 
	we cannot convert one datatype to another.

(c)
int * x, y;
	x = y;
	
	x is a pointer while y is not an pointer so the third statement cannot be executed

(d)
char s[] = "this is a character array";
	for (;*s != '\0'; ++s)
	cout << *s << ' ';
	
	The value of “s” is a constant – the place where the compiler put the array.
	You can take a copy like: char *b = s; and then change it, but you can never change s itself

(e)
short *numPtr,
	result; void *genericPtr = numPtr;
	result = *genericPtr + 7;
	return 0;
	
	A void* represents an address, but it doesn’t specify the type of things it points to,
	and at a consequence you cannot operate on it.

(f)
double x = 19.34;
	double xPtr = &x;
	cout << xPtr << endl;
	return 0;
	
	We cannot put the address of a variable in another variable instead of a pointer variable.
	First convert the xPtr variable to a pointer varible like double* xPtr then 
	it can be executed.
