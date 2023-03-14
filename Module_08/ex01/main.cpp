#include "Span.hpp"


int main()
{
    Span sp = Span(5);
    try
    {
          sp.addNumber(6);
          sp.addNumber(3);
          sp.addNumber(17);
          sp.addNumber(9);
          sp.addNumber(11);
          std::cout << sp.shortestSpan() << std::endl;
          std::cout << sp.longestSpan() << std::endl;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }

    return 0;
}


// int main()
// {
//     {
//         Span sp = Span(5);
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(17);
//         sp.addNumber(9);
//         sp.addNumber(11);
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     {
//         Span sppan(15);
//         Span wrong(1);
//         sppan.addNumber(3);
//         sppan.addNumber(43);
//         sppan.addNumber(64);
//         sppan.addNumber(876);
//         sppan.addNumber(2345);
//         sppan.addNumber(1);
//         try
//         {
//             wrong.addNumber(2);
//             wrong.addNumber(32);
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << '\n';
//         }
//         sppan.numberGenerator();
//         std::cout << sppan.shortestSpan() << std::endl;
//         std::cout << sppan.longestSpan() << std::endl;
//     }
//     return 0;
// }
