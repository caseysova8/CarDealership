
#include <string>

class Car {
	
private:
	
	std::string carMake;
	int price;

public:	
		
	Car(std::string carType, int carPrice)
		: carMake{carType}, price{carPrice} {
	}
	
	std::string getMake() const {
		return carMake;
	}
	
	int getPrice() const {
		return price;
	}
};
