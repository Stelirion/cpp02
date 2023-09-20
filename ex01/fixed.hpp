#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(int intNumber);
	Fixed(float floatNumber);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed&operator=(const Fixed &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _number ;
	const static int _numberFractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);