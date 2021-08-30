
#include <iostream>  
#include <algorithm>   
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;




enum class Gender {
	FEMALE,
	MALE
};

struct Person {
	int age;
	Gender gender;
	bool is_employed;
};


template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
	  if (range_begin == range_end) {
	    return 0;
	  }
	  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	  auto middle = begin(range_copy) + range_copy.size() / 2;
	  nth_element(
	      begin(range_copy), middle, end(range_copy),
	      [](const Person& lhs, const Person& rhs) {
	        return lhs.age < rhs.age;
	      }
	  );
	  return middle->age;
	}


/*
*	persons.begin 	employed_FIT	gender_it	employed_MIT	persons.end
*/

void PrintStats(vector<Person> persons) {
	//   all
	cout<<"Median age = "<<ComputeMedianAge(persons.begin(), persons.end())<<endl;

	// all females
	auto gender_it = partition(persons.begin(), persons.end(), 
		[](Person& p1){return p1.gender == Gender::FEMALE;});

	cout<<"Median age for females = "<<ComputeMedianAge(persons.begin(), gender_it)<<endl;

	//	all males
	// it = partition(persons.begin(), persons.end(), 
	// 	[](Person& p){ return p.gender == Gender::MALE;});
	cout<<"Median age for males = "<<ComputeMedianAge(gender_it, persons.end())<<endl;


//	all employed females
	auto emloyed_FIt = partition(persons.begin(), gender_it, 
		[](Person& p){ return (p.gender == Gender::FEMALE && p.is_employed);});
	cout<<"Median age for employed females = "<<
		ComputeMedianAge(persons.begin(), emloyed_FIt)<<endl;

//	all unemployed females
	// it = partition(emloyed_FIt, persons.end(), 
	// 	[](Person& p){ return (p.gender == Gender::FEMALE && !p.is_employed);});
	cout<<"Median age for unemployed females = "<<ComputeMedianAge(emloyed_FIt, gender_it)<<endl;



//	all employed males
	auto emloyed_MIt = partition(gender_it, persons.end(), 
		[](Person& p){ return (p.gender == Gender::MALE && p.is_employed);});
	cout<<"Median age for employed males = "<<ComputeMedianAge(gender_it, emloyed_MIt)<<endl;

//	all unemployed males
	// it = partition(persons.begin(), persons.end(), 
	// 	[](Person& p){ return (p.gender == Gender::MALE && !p.is_employed);});
	cout<<"Median age for unemployed males = "<<ComputeMedianAge(emloyed_MIt, persons.end())<<endl;







}


int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}