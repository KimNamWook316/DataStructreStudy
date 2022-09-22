#pragma once

#include "DicRecord.h"

class CDictionary
{
public:
    CDictionary();
    ~CDictionary();

public:
    CDicRecord* SearchWord(const std::string& word);

    bool Insert(const std::string& word, const std::string& meaning);
    bool Remove(const std::string& word);

    void PrintRecord();

private:
    CDicRecord* m_Root;
};

