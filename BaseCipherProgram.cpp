#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>


int main()
{
    std::ifstream plugboard;
    plugboard.open ("Plugboard.txt", std::ifstream::in);
    std::unordered_map <char ,char> pboardmap;
    if (!plugboard.is_open()) // error checking for a plugboard file
	{
		std::cerr <<"plugboard file not found";
		exit(1);		
	}
	else // creates the plugboard, loads the two lines in vectors, and creates associations in pboardmap.
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
	
	
	return 0;
}
