
#include "Manipulate_string.h"
string add_commas_to_values_and_wages(int value)
{
	//if the amount of numbers is 8, add a comma before the third character
	//same logic for the rest of the if statements
	string str = to_string(value);
	if (str.size() == 8) {
		str.insert(2, ",");
		str.insert(6, ",");
	}

	if (str.size() == 7) {
		str.insert(1, ",");
		str.insert(5, ",");
	}

	if (str.size() == 6)
		str.insert(3, ",");
		
	if (str.size() == 5)
		str.insert(2, ",");
	return str;
	
}
//Convert all letters to capitals as that is how the names are stored in the text file
string convertupper(string& name) {

	std::transform(name.begin(), name.end(), name.begin(),
		[](char c) { return toupper(c); });

	return name;
}
// Convert all letters to lower apart from the beginning letter
string convertlower(string& name) {
	for (int i = 1; i < name.size(); i++) {
		
		name[i] = std::tolower(name[i]);
	}
	return name;
}
