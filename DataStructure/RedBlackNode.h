#pragma once

class RedBlackNode 
{
public:
    enum class Color
    {
        RED,
        BLACK
    };

protected:
    RedBlackNode* m_Parent;
    RedBlackNode* m_Left;
    RedBlackNode* m_Right;
    Color m_Color;
    int m_Data;

public:
    RedBlackNode() = delete;
    RedBlackNode(int data, Color color = Color::RED);
    ~RedBlackNode();

public:
    void Clear();

public:
    int GetData() const
    {
        return m_Data;
    }

    Color GetColor() const
    {
        return m_Color;
    }

    void SetColor(Color color)
    {
        m_Color = color;
    }

    RedBlackNode* GetLeft()
    {
        return m_Left;
    }

    RedBlackNode* GetRight()
    {
        return m_Right;
    }

    RedBlackNode* GetParent()
    {
        return m_Parent;
    }

    void SetLeft(RedBlackNode* node)
    {
        m_Left = node;
    }

    void SetRight(RedBlackNode* node)
    {
        m_Right = node;
    }

    void SetParent(RedBlackNode* node)
    {
        m_Parent = node;
    }
};

