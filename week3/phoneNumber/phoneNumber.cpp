#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>


#include "tests.h"
using namespace std;

class PhoneNumber {
	/* Принимает строку в формате +XXX-YYY-ZZZZZZ
     Часть от '+' до первого '-' - это код страны.
     Часть между первым и вторым символами '-' - код города
     Всё, что идёт после второго символа '-' - местный номер.
     Код страны, код города и местный номер не должны быть пустыми.
     Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

     Примеры:
     * +7-495-111-22-33
     * +7-495-1112233
     * +323-22-460002
     * +1-2-coursera-cpp
     * 1-2-333 - некорректный номер - не начинается на '+'
     * +7-1233 - некорректный номер - есть только код страны и города
  */
public:
	explicit PhoneNumber(const string& number);

	string GetCountryCode() const;
	string GetCityCode() const;
	string GetLocalNumberCode() const;
	string GetInternatonalNumber() const;

private:
	string country_code_;
	string city_code_;
	string local_number_;

};



PhoneNumber::PhoneNumber(const string& number){
	istringstream iss (number);
	char plus;
	iss>>plus;
	getline(iss, country_code_,  '-');

	if (plus != '+' || country_code_ == "") {
		throw invalid_argument("Phone number should begin with +");
	}

	getline(iss, city_code_, '-');
	if (city_code_ == "") {
		throw invalid_argument("Phone number should contain city code");
	}
	getline(iss, local_number_, '-');
	if (local_number_ == "") {
		throw invalid_argument("Phone number should contain local number");
	}

}

string PhoneNumber::GetCountryCode() const { return country_code_;}
string PhoneNumber::GetCityCode() const { return city_code_;}
string PhoneNumber::GetLocalNumberCode() const { return local_number_;}
string PhoneNumber::GetInternatonalNumber() const { 
	return "+"+country_code_+"-"+city_code_+"-"+local_number_;
}




void TestFullNumber() {
	PhoneNumber p("+38-067-3888411");
	AssertEqual(p.GetInternatonalNumber(), "+38-067-3888411", "full");
}

void TestEmpty() {
	PhoneNumber p("+-067-3888411");
	// AssertEqual(p.GetInternatonalNumber(), "+38-067-3888411", "full");
}
