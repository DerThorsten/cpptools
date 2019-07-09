#pragma once
#ifndef CPPTOOLS_CPPTOOLS_HPP
#define CPPTOOLS_CPPTOOLS_HPP

#include <cstdint>
#include <iostream>

namespace cpptools {
    
    class MyClass
    {
    public:
        MyClass(const uint64_t size)
        : m_size(size)
        {

        }
        
        void hello_world()
        {
            std::cout<<"Hello World!\n";
        }
    private:
        uint64_t m_size;
    };

} // end namespace cpptools


#endif // CPPTOOLS_CPPTOOLS_HPP