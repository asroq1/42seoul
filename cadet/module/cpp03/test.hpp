#ifndef TEST_HPP
# define TEST_HPP

class test
{
private:
	/* data */

public:
	test();
	test(const test& ref);
	~test();

	test&	operator=(const test& ref);
};

#endif
