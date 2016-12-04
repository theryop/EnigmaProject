#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

std::vector<char> rotate(int amt, std::vector<char> initial);

std:: vector<char> rotate(int amt, std::vector<char> initial)
{
	int counter = 0;
	char temp;
	while (counter < amt)
	{
		temp = initial.at(25);
		initial.pop_back();
		initial.insert(initial.begin(),temp);
		counter++;
	}
	return initial;
}

int main()
{
    // Part 1: Plugboard is initialized, and data is filled into pboard map.
    std::ifstream plugboard;
    std::vector <char> pv3; //resultant plugboard vector
    plugboard.open ("Plugboard.txt", std::ifstream::in);
    if (!plugboard.is_open()) // error checking for a plugboard file
	{
		std::cerr <<"plugboard file not found";
		exit(1);		
	}
	else 
	{
	    std::string pb1;
	    std::string pb2;
	    std::vector <char> pv1;
	    std::vector <char> pv2;
	    getline(plugboard, pb1);
	    getline(plugboard, pb2);
	    for(int i = 0;i < pb1.length(); i++)
	    {
	    	if (+pb1.at(i) != 32) // if current plugboard character is not a space, add char to vector.
	    	{
	    		pv1.push_back(pb1.at(i));	
	    	}
	    }
	    for (int i = 0;i < pb2.length(); i++)
	    {
	    	if (+pb2.at(i) != 32) 
	    	{
	    		pv2.push_back(pb2.at(i));
	    	}
	    }
	    pv3.assign(26, '0');
		for (int i = 0;i < pv1.size(); i++) //adds the connection of both plugboard ends to the map.
		{
			char code1 = pv1.at(i);
			int icode1 = +code1 - 65;
			char code2 = pv2.at(i);
			int icode2 = +code2 - 65;
			
			pv3.at(icode1) = code2;
			pv3.at(icode2) = code1;
			
			
		}
	 std::cout << "plugboard loaded successfully.\n";
	}
	plugboard.close();
	
	//Part 2: This segment accesses the rotors, and places them into their respective vectors.
	std::string rotorchoice;
	std::string rotordata;
	int rotorPosition;
	std::vector <char> rotor1;
	std::vector <char> rotor2;
	std::vector <char> rotor3;
	std::cout << "Which rotor would you like to be the first rotor?\n";
	std::cin >> rotorchoice;
	std::ifstream fRotorStream;
	fRotorStream.open ("Rotor" + rotorchoice + ".txt", std::ifstream::in);
    if (!fRotorStream.is_open()) // error checking for a plugboard file
	{
		std::cerr <<"rotor file not found";
		exit(1);		
	}
	else
	{
		std::cout << "Rotor " << rotorchoice << " chosen as first rotor.\n";
		getline(fRotorStream, rotordata);
		for(int i = 0;i < rotordata.length();i++)
		{
			if (rotordata.at(i) != ' ') 
	    	{
	    		rotor1.push_back(rotordata.at(i));
	    	}
		}
	}
	fRotorStream.close();
	
	std::cout << "what position would you like to set the first rotor at?\n";
	std::cin >> rotorPosition;
	rotor1 = rotate(rotorPosition, rotor1);
	std::cout << "The first rotor has been set to initial position " << rotorPosition << "\n";
	
	std::cout << "Which rotor would you like to be the second rotor?\n";
	std::cin >> rotorchoice;
	std::ifstream sRotorStream;
	sRotorStream.open ("Rotor" + rotorchoice + ".txt", std::ifstream::in);
    if (!sRotorStream.is_open()) // error checking for a plugboard file
	{
		std::cerr <<"rotor file not found";
		exit(1);		
	}
	else
	{
		std::cout << "Rotor " << rotorchoice << " chosen as second rotor.\n";
		getline(sRotorStream, rotordata);
		for(int i = 0;i < rotordata.length();i++)
		{
			if (rotordata.at(i) != ' ') 
	    	{
	    		rotor2.push_back(rotordata.at(i));
	    	}
		}
	}
	sRotorStream.close();
	rotorPosition = 0;
	std::cout << "what position would you like to set the second rotor at?\n";
	std::cin >> rotorPosition;
	rotor2 = rotate(rotorPosition, rotor2);
	std::cout << "The second rotor has been set to initial position " << rotorPosition << "\n";
	
	std::cout << "Which rotor would you like to be the third rotor?\n";
	std::cin >> rotorchoice;
	std::ifstream tRotorStream;
	tRotorStream.open ("Rotor" + rotorchoice + ".txt", std::ifstream::in);
    if (!tRotorStream.is_open()) 
	{
		std::cerr <<"rotor file not found";
		exit(1);		
	}
	else
	{
		std::cout << "Rotor " << rotorchoice << " chosen as third rotor.\n";
		getline(tRotorStream, rotordata);
		for(int i = 0;i < rotordata.length();i++)
		{
			if (rotordata.at(i) != ' ') 
	    	{
	    		rotor3.push_back(rotordata.at(i));
	    	}
		}
	}
	tRotorStream.close();
	std::cout << "what position would you like to set the third rotor at?\n";
	std::cin >> rotorPosition;
	rotor3 = rotate(rotorPosition, rotor3);
	std::cout << "The third rotor has been set to initial position " << rotorPosition << "\n";
	
	std::string useri;
	std::cout << "Please enter the string you'd like to input:\n";
	std::cin >> useri; // We are assuming, in this base program, that the user's input is properly formatted with only Upper Case Roman alphabetical letters.
	
	//Part 3: Userinput is taken in, converted into a vector of characters, then converted into an output;
	std::vector <char> userInVec;
	
	for (int i = 0; i < useri.length();i++) //converts user input into a vector of characters, for ease of replacement.
	{
		userInVec.push_back(useri.at(i));
	}
	
	//first plugboard switch

	for (int i= 0; i < userInVec.size(); i++)
	{
		int tempval = +userInVec.at(i) - 65;
		if (+pv3[tempval] != 48) // if the character isn't a 0, replace the input with the pb character
		{
			userInVec.at(i) = pv3.at(tempval);
		}
	}
	
	//rotors 
	int rotorcounter = 0;
	int r2counter = 0;
	for (int i = 0; i < userInVec.size(); i++)
	{
		int icharval = +userInVec.at(i) - 65;
		rotorcounter++;
		if (r2counter % 26 == 0)
		{
			rotor3 = rotate(1,rotor3);
		}
		else if (rotorcounter % 26 == 0)
		{
			rotor2 = rotate(1,rotor2);
		}
		else
		{
			rotor1 = rotate(1,rotor1);
		}
		userInVec.at(i) = rotor1.at(icharval);
		icharval = +userInVec.at(i) - 65;
		userInVec.at(i) = rotor2.at(icharval);
		icharval = +userInVec.at(i) - 65;
		userInVec.at(i) = rotor3.at(icharval);
		icharval = +userInVec.at(i) - 65;
		userInVec.at(i) = rotor3.at(icharval);
		icharval = +userInVec.at(i) - 65;
		userInVec.at(i) = rotor2.at(icharval);
		icharval = +userInVec.at(i) - 65;
		userInVec.at(i) = rotor1.at(icharval);
		icharval = +userInVec.at(i) - 65;
	}
	
	//2nd Plugboard switch
	for (int i= 0; i < userInVec.size(); i++)
	{
		int tempval = +userInVec.at(i) - 65;
		if (+pv3.at(tempval) != 48)
		{
			userInVec.at(i) = pv3.at(tempval);
		}
	}
	
	std::cout << "The resultant output is:\n";
	for (int i = 0; i < userInVec.size();i++)
	{
		std::cout <<userInVec.at(i);
	}
	return 0;
}
