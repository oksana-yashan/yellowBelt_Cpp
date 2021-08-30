#include "node.h"

EmptyNode::EmptyNode() { }

bool EmptyNode::Evaluate(const Date &d, const string e) {
    return true;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &lO,
                         const shared_ptr<Node> l, const shared_ptr<Node> r) 
    : logOp(lO), lNode(l), rNode(r) { }

bool LogicalOperationNode::Evaluate(const Date &d, const string e) {
    switch(logOp) {
        case LogicalOperation::Or:
            return lNode->Evaluate(d, e) || rNode->Evaluate(d,e);
            break;
        case LogicalOperation::And:
            return lNode->Evaluate(d, e) && rNode->Evaluate(d,e);
            break;
        default:
            return 0;
            break;
    }
}




EventComparisonNode::EventComparisonNode(const Comparison &c, const string &e) 
    : cmp(c), event(e) { }

bool EventComparisonNode::Evaluate(const Date &d, const string e) {
    switch(cmp) {
        case Comparison::Less:
            return e < event;
            break;
        case Comparison::LessOrEqual:
            return e <= event;
            break;
        case Comparison::Greater:
            return e > event;
            break;
        case Comparison::GreaterOrEqual:
            return e >= event;
            break;
        case Comparison::Equal:
            return e == event;
            break;
        case Comparison::NotEqual:
            return e != event;
            break;
        default:
            return 0;
            break;
    }
}


DateComparisonNode::DateComparisonNode(const Comparison &c, const Date &d) 
    : cmp(c), date(d) { }

bool DateComparisonNode::Evaluate(const Date &d, const string e) {

    switch (cmp)
    {
    case Comparison::Less:
        return d<date;
        break;
    case Comparison::LessOrEqual:
        return d<=date;
        break;
    case Comparison::Greater:
        return d>date;
        break;
    case Comparison::GreaterOrEqual:
        return d>=date;
        break;
    case Comparison::Equal:
        return d==date;
        break;
    case Comparison::NotEqual:
        return d!=date;
        break;
    default:
        return 0;
        break;
    }
}

