#include <iostream>
#include "DicRecord.h"

CDicRecord::CDicRecord()    :
    m_Left(nullptr),
    m_Right(nullptr)
{
}

CDicRecord::CDicRecord(const std::string& world, const std::string& meaning)    :
    m_Left(nullptr),
    m_Right(nullptr),
    m_Word(world),
    m_Meaning(meaning)
{
}

CDicRecord::~CDicRecord()
{
}

int CDicRecord::Compare(const std::string& word)
{
    // 같을 때
    if (m_Word.compare(word) == 0)
        return 0;

    // 내 문자가 사전순 앞일때
    else if (m_Word.compare(word) < 0)
        return -1;

    // 내 문자가 사전순 뒤일때
    else
        return 1;
}

int CDicRecord::Compare(CDicRecord* record)
{
    return Compare(record->GetWord());
}

void CDicRecord::InOrder()
{
    if (m_Left)
    {
        m_Left->InOrder();
    }

    Display();

    if (m_Right)
    {
        m_Right->InOrder();
    }
}

bool CDicRecord::IsLeaf()
{
    return (!m_Left && !m_Right);
}

void CDicRecord::Display()
{
    std::cout << "Word : " << m_Word << ", Meaning : " << m_Meaning << '\n';
}
