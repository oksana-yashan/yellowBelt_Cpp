#include <iostream>
#include <string>
#include <memory>
#include <stack>

using namespace std;


class Node {
public:
	virtual int Evaluate() const = 0;
};


class Digit : public Node {
public:
	Digit(char d) : value_(d-'0') {	}

	int Evaluate() const override  {
		return value_;
	}
private:	
	const uint8_t value_;
};



class Variable : public Node {
public:
	Variable(const int& x) : x_(x) { }

	int Evaluate() const override {
		return x_;
	}
private:
	const int& x_;
};


class Operation : public Node {
public:
	// Operation(const char& oper, shared_ptr<Node> left, shared_ptr<Node> right) 
	// 				:oper_(oper), left_(left), right_(right) {

	// }

	Operation(char oper) : priority([oper] {
					if (oper == '*' || oper == '/')
						return 1;
					else return 2;
			}()), oper_(oper) {}

	int Evaluate() const override {
		if (oper_ == '*') {
			return left_->Evaluate() * right_->Evaluate();
		}
		else if (oper_ == '/') {
			return left_->Evaluate() / right_->Evaluate();
		}
		else if (oper_ == '+') {
			return left_->Evaluate() + right_->Evaluate();
		}
		else if (oper_ == '-') {
			return left_->Evaluate() - right_->Evaluate();
		}
		return 0;

	}
	const uint8_t priority;
	void SetLeft(shared_ptr<Node> left) { left_ = left;}
	void SetRight(shared_ptr<Node> right) { right_ = right;}

private:
	const char oper_;
	shared_ptr<Node> left_, right_;
};


template<typename Iterator>
shared_ptr<Node> Parse(Iterator token, Iterator end, const int& x) {
	if (token == end)
		return make_shared<Digit>('0');

	stack<shared_ptr<Node>> values;
	stack<shared_ptr<Operation>> ops;

	auto PopOps = [&] (int priority) {
		//поки є більш пріоритетні задачі
		while(!ops.empty() && ops.top()->priority <= priority){
			auto r = values.top();
			values.pop();
			auto l = values.top();
			values.pop();
			auto op = ops.top();
			ops.pop();

			op->SetRight(r);
			op->SetLeft(l);
			// forms an value with operation
			values.push(op);
		}
	};
	//  */*-+/*   1) <- *  2)* <- / => v1*v2 /     3)/ ->*=> r1/v3 *
	//   4) * <- - => r2*v4 -  5) - <- + 

	while (token != end)  {
		const auto& value = *token;
		if (value >= '0' && value <='9')
			values.push(make_shared<Digit>(value));
		else if (value == 'x') {
			values.push(make_shared<Variable>(x));
		}
		else if (value == '*' || value == '/') {
			PopOps(1);
			ops.push(make_shared<Operation>(value));
		}
		else if (value == '+' || value == '-') {
			PopOps(2);
			ops.push(make_shared<Operation>(value));
		}
		++token;
	}

	while(!ops.empty())
		PopOps(3);

	return values.top();
}






int main() {
	cout<<"Enter expression: ";
	string tokens;
	getline(cin, tokens);


	int x = 6;
	auto node = Parse(tokens.begin(), tokens.end(), x);

	// shared_ptr<Node> five = make_shared<Digit>(5);
	// shared_ptr<Node> seven = make_shared<Digit>(7);
	// shared_ptr<Node> var_x = make_shared<Variable>(x);

	// shared_ptr<Node> res1 = make_shared<Operation>('+',five, seven);
	// shared_ptr<Node> res2 = make_shared<Operation>('*', var_x, var_x);
	// shared_ptr<Node> res3 = make_shared<Operation>('-', res1, res2);
	// shared_ptr<Node> res4 = make_shared<Operation>('+', res3, var_x);



	
	// auto expr = Parse(tokens, x);
	cout<<"Enter x: ";
	while (cin>>x) {
		cout<<"expression value: "<<node->Evaluate()<<endl;
		cout<<x<<endl;
		cout<<"Enter x: ";
	}
	
	return 0;
}