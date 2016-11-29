#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>


int main()
{
    // Part 1: Plugboard is initialized, and data is filled into pboard map.
    std::ifstream plugboard;
    plugboard.open ("Plugboard.txt", std::ifstream::in);
    std::unordered_map <char ,char> pboardmap;
    if (!plugboard.is_open()) // error checking for a plugboard file
	{
		std::cerr <<"plugboard file not found";
		exit(1);		
	}
	else 
	{
	    std::cout << "plugboard loaded successfully.\n";
	    std::string pb1;
	    std::string pb2;
	    std::vector <char> pv1;
	    std::vector <char> pv2;
	    getline(plugboard, pb1);
	    getline(plugboard, pb2);
	    
	    for(int i = 0;i < pb1.length(); i++)
	    {
	    	if (pb1.at(i) != ' ') // if current plugboard character is not a space, add char to vector.
	    	{
	    		pv1.push_back(pb1.at(i));	
	    	}
	    }
	    for (int i = 0;i < pb2.length(); i++)
	    {
	    	if (pb2.at(i) != ' ') 
	    	{
	    		pv2.push_back(pb2.at(i));
	    	}
	    }
		for (int i = 0;i < pv1.size(); i++) //adds the connection of both plugboard ends to the map.
		{
			pboardmap[pv1.at(i)] = pv2.at(i);
			pboardmap[pv2.at(i)] = pv1.at(i);
		}
	}
	plugboard.close();
	
	//Part 2: This segment accesses the rotors, and places them into their respective vectors.
	std::string rotorchoice;
	std::string rotordata;
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
	
	
	return 0;
}
	return 0;
}
