#pragma once
#include <string>  
#include <cctype> 
#ifndef UTILS_
#define UTILS_H

namespace Utilitati{

    inline int CharToInt(char c) { return c - '0'; }  //functie facuta pt claritate in cod, pt a nu scrie " - '0' " la fiecare conversie char - int

    inline bool ContineCifre(const std::string& text) {
        for (char c : text)
            if (isdigit(c))
                return true;
        return false;
    }

}

#endif