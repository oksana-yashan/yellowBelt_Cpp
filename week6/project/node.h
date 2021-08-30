#pragma once
#include "date.h"

#include <map>
#include <set>

enum class Comparison
{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation
{
    Or,
    And
};

class Node
{
public:
    virtual bool Evaluate(const Date &d, const string e) = 0;
};

class EmptyNode : public Node
{
public:
    EmptyNode();
    bool Evaluate(const Date &d, const string e) override;
};

class LogicalOperationNode : public Node
{
public:
    LogicalOperationNode(const LogicalOperation &lO,
                         const shared_ptr<Node> l, const shared_ptr<Node> r);
    bool Evaluate(const Date &d, const string e) override;

private:
    const LogicalOperation logOp;
    const shared_ptr<Node> lNode;
    const shared_ptr<Node> rNode;
};

class EventComparisonNode : public Node
{
public:
    EventComparisonNode(const Comparison &c, const string &e);
    bool Evaluate(const Date &d, const string e) override;

private:
    const Comparison cmp;
    const string event;
};

class DateComparisonNode : public Node
{
public:
    DateComparisonNode(const Comparison &c, const Date &d);
    bool Evaluate(const Date &d, const string e) override;

private:
    const Comparison cmp;
    const Date date;
};
