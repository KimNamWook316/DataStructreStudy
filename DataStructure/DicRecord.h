#pragma once

#include <string>

class CDicRecord
{
public:
    CDicRecord();
    CDicRecord(const std::string& world, const std::string& meaning);
    ~CDicRecord();

public:
    int Compare(const std::string& word);
    int Compare(CDicRecord* record);

	void InOrder();
    bool IsLeaf();

    void Display();

public:
    const std::string& GetWord() const
    {
        return m_Word;
    }

    const std::string& GetMeaning() const 
    {
        return m_Meaning;
    }

    CDicRecord* GetLeft() const
    {
        return m_Left;
    }

    CDicRecord* GetRight() const
    {
        return m_Right;
    }

public:
    void SetLeft(CDicRecord* record)
    {
        m_Left = record;
    }

    void SetRight(CDicRecord* record)
    {
        m_Right = record;
    }
    
private:
    std::string m_Word;
    std::string m_Meaning;

    CDicRecord* m_Left;
    CDicRecord* m_Right;
};

