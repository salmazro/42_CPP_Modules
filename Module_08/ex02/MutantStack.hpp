#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


# include <iostream>
# include <deque>
# include <stack>
# include <list>
# include <iterator>
# include <algorithm>

template<typename T>
class MutantStack : public std::stack<T>
{
public:

    typedef typename std::deque<T>::iterator iterator;

	iterator    begin() { return (this->c.begin()); }
    iterator    end()   { return (this->c.end()); }
};

#endif
