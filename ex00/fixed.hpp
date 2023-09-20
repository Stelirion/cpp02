#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int number);
	Fixed(const float number);
	~Fixed();
	Fixed&operator=(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _number ;
	const static int _numberFractionalBits = 8;
};