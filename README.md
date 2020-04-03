# PURPOSE
A recent project required the usage of the Standard Library's Vector class.
While utilizing this data type, multiple operations needed to be performed on the vector, such as "Does this list contain x?", "I want to map every element in this vector to another data type.", etc.
As the project grew in size, a lot of code started being copied over and over again.
I thought that this would be the perfect usage for a library of functions which abstract away these requests into simple function calls.
For example, if I wanted to check if a vector contained an element, I would perform the falling function invocation:

	std::vector<int> myList = /* a vector of integers */;
	int const searchForMe = 5;
	bool const contains = Iterators<int>::contains(myList, searchForMe);

instead of doing the following over and over again:

	std::vector<int> myList = /* a vector of integers */;
	int const searchForMe = 5;
	typename std::vector<int>::iterator itr(myList.begin());
	for (; itr!=myList.end(); ++itr) if (searchForMe == *itr) /* do something */;

This provided multiple advantages, the primary two being increased readability and decoupled code.
