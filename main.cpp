/*
Rohan Kakade
02/12/23
Program to find the modulus and argument of a complex number
Allows adding and subtracting two complex numbers using operator overloading
*/

#include "mbed.h"

//definin a new data type called "complex_numbers"
class complex_numbers
{
   //declaring two fields or variables
   int real; //represnts the real component 
   int imaginary; //represents the imaginary component

   public:
   //constructor defined here to allow writing eg., "complex_numbers num1(3,4);" in main()
   complex_numbers(int r, int i)
   {
      //take value entered in main() and copy it
       real = r; 
       imaginary = i;
   }
   //method (member function) to find amplitude
   float modulus() //decimal point result is possible and so float
   {
       return sqrt(real*real + imaginary*imaginary);
   }
   //method (member function) to find argument (angle)
   double argument() //atan2() is mathematical function that returns a double
   {
       return (atan2(imaginary,real))*(180/3.14);
   }
   //method (member function) to get real component of a complex number
   int getrealvalue()
   {
       return real;
   }
   //method (member function) to get imaginary component of a complex number
   int getimagvalue()
   {
       return imaginary;
   }

   //this is operator overload method to dictate how two complex numbers will be summed up
   complex_numbers operator+(complex_numbers const&other)
   {
       return complex_numbers(real+other.real,imaginary+other.imaginary);
   }

   //this is operator overload method to dictate how two complex numbers will be subtracted
   complex_numbers operator-(complex_numbers const&other)
   {
       return complex_numbers(real-other.real,imaginary-other.imaginary);
   }


};

// main() runs in its own thread in the OS
int main()
{
    //defining 2 objects of complex_numbers type
    //each initialised to certain values
    complex_numbers num1(8,6);
    complex_numbers num2(3,4);

    //defining 2 additional objects of complex_numbers type
    //each initialised to store nothing
    complex_numbers num3(0,0);
    complex_numbers num4(0,0);

    //methods (member functions) are called to extract modulus and argument of the first object
    float num1mod = num1.modulus();
    double num1arg = num1.argument();

    //displaying these values on CoolTerm
    printf("For the 1st complex number: \n");
    printf("Modulus of (%d + %di) is: %1.2f \n", num1.getrealvalue(),num1.getimagvalue(),num1mod);
    printf("Argument of (%d + %di) is: %1.2f degrees \n", num1.getrealvalue(),num1.getimagvalue(),num1arg);
    
    printf("------------------------------------- \n");

    //methods (member functions) are called to extract modulus and argument of the first object
    float num2mod = num2.modulus();
    double num2arg = num2.argument();

    //displaying these values on CoolTerm
    printf("For the 2nd complex number: \n");
    printf("Modulus of (%d + %di) is: %1.2f \n", num2.getrealvalue(),num2.getimagvalue(),num2mod);
    printf("Argument of (%d + %di) is: %1.2f degrees \n", num2.getrealvalue(),num2.getimagvalue(),num2arg);

    printf("------------------------------------- \n"); 

    //operator+ overload method (defined in the class definition) allows doing this
    num3 = num1+num2;
    
    printf("For the sum of the first two complex numbers: \n");
    printf("Modulus of (%d + %di) is: %1.2f \n", num3.getrealvalue(),num3.getimagvalue(),num3.modulus());
    printf("Argument of (%d + %di) is: %1.2f degrees \n", num3.getrealvalue(),num3.getimagvalue(),num3.argument());

    printf("------------------------------------- \n"); 

    //operator- overload method (defined in the class definition) allows doing this
    num4 = num2-num1;
    
    printf("For the difference of the first two complex numbers (2nd - 1st): \n");
    printf("Modulus of (%d + %di) is: %1.2f \n", num4.getrealvalue(),num4.getimagvalue(),num4.modulus());
    printf("Argument of (%d + %di) is: %1.2f degrees \n", num4.getrealvalue(),num4.getimagvalue(),num4.argument());

    //line to ensure board goes to sleep after doing its job above
    while (true) { sleep(); }
}

