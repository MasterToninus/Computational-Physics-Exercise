// http://www.cplusplus.com/reference/complex/complex/
// http://www.cplusplus.com/reference/complex/conj/


#include <iostream>     // std::cout
#include <complex>      // std::complex

int main ()
{
  std::complex<double> mycomplex;

  mycomplex = 10.0;   // 10
  mycomplex += 2.0;   // 12

  mycomplex = std::complex<double>(10.0,1.0);  // 10+i

  mycomplex = mycomplex + 10.0 ;               // 20+i

  if (mycomplex == std::complex<double>(20.0,1.0))
    std::cout << "mycomplex is " << mycomplex << '\n';

  std::cout<< "prove mie!\n\n";
  std::complex<int> z(1,2);
  std::complex<int> i (0,1);
  std::cout<<" (1+2i+2+3*i)* = "<<std::conj(z+2+3*i)<<'\n';




  return 0;
}
