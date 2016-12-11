#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

std::vector<char> rotate(int amt, std::vector<char> initial);

std::vector<char> rotate(int amt, std::vector<char> initial)
{
    int counter = 0;
    char temp;
    while (counter < amt)
    {
        temp = initial.at(127);
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
	  pv1.push_back(pb1.at(i));
        }
        for (int i = 0;i < pb2.length(); i++)
        {
	  pv2.push_back(pb2.at(i));
        }
        pv3.assign(128, -1);
        for (int i = 0;i < pv1.size(); i++) //adds the connection of both plugboard ends to the map.
        {
            char code1 = pv1.at(i);
            int icode1 = code1;
            char code2 = pv2.at(i);
            int icode2 = code2;
            
            pv3.at(icode1) = code2;
            pv3.at(icode2) = code1;
            
            
        }
	
        std::cout << "plugboard loaded successfully.\n";
    }
    plugboard.close();
    
    //Part 2: This segment accesses the rotors, and places them into their respective vectors.
    char c;
    std::string rotorchoice;
    int rotorPosition;
    std::vector <char> rotor1;
    std::vector <char> rotor2;
    std::vector <char> rotor3;
    std::cout << "Which rotor would you like to be the first rotor?\n";
    std::cin >> rotorchoice;
    std::ifstream fRotorStream;
    fRotorStream.open ("rotor/Rotor" + rotorchoice + ".txt", std::ifstream::in);
    if (!fRotorStream.is_open()) // error checking for a plugboard file
    {
        std::cerr <<"rotor file not found";
        exit(1);
    }
    else
    {
        std::cout << "Rotor " << rotorchoice << " chosen as first rotor.\n";
        while(fRotorStream.get(c))
        {
	  rotor1.push_back(c); //push in all chars in the file

        }
    }
    fRotorStream.close();
    
    if(rotor1.size() == 129)
      {
	rotor1.pop_back(); //takes care of extra newline at the end of the file}
      }
    
    std::cout << "what position would you like to set the first rotor at?\n";
    std::cin >> rotorPosition;
    rotor1 = rotate(rotorPosition, rotor1);
    std::cout << "The first rotor has been set to initial position " << rotorPosition << "\n";
    std::cout << "Which rotor would you like to be the second rotor?\n";
    std::cin >> rotorchoice;
    std::ifstream sRotorStream;
    sRotorStream.open ("rotor/Rotor" + rotorchoice + ".txt", std::ifstream::in);
    if (!sRotorStream.is_open()) // error checking for a plugboard file
    {
        std::cerr <<"rotor file not found";
        exit(1);
    }
    else
    {
        std::cout << "Rotor " << rotorchoice << " chosen as second rotor.\n";
        while(sRotorStream.get(c))
        {
	  rotor2.push_back(c); //push in all chars in the file
        }
    }
    sRotorStream.close();
    
    rotorPosition = 0; //reset the rotor position
    
    if(rotor2.size() == 129)
      {
	rotor2.pop_back(); //takes care of extra newline at the end of the file}
      }
    
    std::cout << "what position would you like to set the second rotor at?\n";
    std::cin >> rotorPosition;
    rotor2 = rotate(rotorPosition, rotor2);
    std::cout << "The second rotor has been set to initial position " << rotorPosition << "\n";
    
    std::cout << "Which rotor would you like to be the third rotor?\n";
    std::cin >> rotorchoice;
    std::ifstream tRotorStream;
    tRotorStream.open ("rotor/Rotor" + rotorchoice + ".txt", std::ifstream::in);
    if (!tRotorStream.is_open())
    {
        std::cerr <<"rotor file not found";
        exit(1);
    }
    else
    {
        std::cout << "Rotor " << rotorchoice << " chosen as third rotor.\n";
        while(tRotorStream.get(c))
        {
	  rotor3.push_back(c); //push in all the characters in the file
	}
    }
    tRotorStream.close();

    rotorPosition = 0; //reset the rotor position
    
    if(rotor3.size() == 129)
      {
	rotor3.pop_back(); //takes care of extra newline at the end of the file}
      }
    
    std::cout << "what position would you like to set the third rotor at?\n";
    std::cin >> rotorPosition;
    rotor3 = rotate(rotorPosition, rotor3);
    std::cout << "The third rotor has been set to initial position " << rotorPosition << "\n";
    
    std::cout << "Which reflector would you like to use? (B or C)\n";
    std::string ref;
    std::vector <char> Reflector;
    std::cin >> ref;
    std::ifstream refStream;
    refStream.open("Reflector" + ref + ".txt", std::ifstream::in);
    if (!refStream.is_open())
    {
        std::cerr << "Reflector file not found";
        exit(1);
    }
    else
    {
        std::string rf1;
	while(refStream.get(c))
        {
	  Reflector.push_back(c);
        }
    }
    refStream.close();
    
    std::string useri;
    std::cout << "Please enter the string you'd like to input:\n";
    std::cin.ignore();
    getline(std::cin, useri);
    
    //Part 3: Userinput is taken in, converted into a vector of characters, then converted into an output;
    std::vector<char> userInVec;
    
    for (int i = 0; i < useri.length();i++) //converts user input into a vector of characters, for ease of replacement.
    {
        userInVec.push_back(useri.at(i));
    }
    
    //first plugboard switch
    
    for (int i= 0; i < userInVec.size(); i++)
    {
        int tempval = userInVec.at(i);
        if (pv3[tempval] != -1) // if the character isn't a 0, replace the input with the pb character
        {
            userInVec.at(i) = pv3.at(tempval);
        }
    }
    
    //rotors
    int rotorcounter = 1;
    int r2counter = 1;
    for (int i = 0; i < userInVec.size(); i++)
    {
      int icharval = userInVec.at(i);
      rotorcounter++;
      if (r2counter % 128 == 0)
	{
	  rotor3 = rotate(1,rotor3);
	  rotor2 = rotate(1,rotor2);
                r2counter++;
	}
      else if (rotorcounter % 128 == 0)
	{
	  rotor2 = rotate(1,rotor2);
                r2counter++;
	}
      rotor1 = rotate(1,rotor1);
      userInVec.at(i) = rotor1.at(icharval);
      
      icharval = userInVec.at(i);
      userInVec.at(i) = rotor2.at(icharval);
      
      icharval = userInVec.at(i);
      userInVec.at(i) = rotor3.at(icharval);
      
      icharval = userInVec.at(i);
      userInVec.at(i) = Reflector.at(icharval);   //Reflector character
      
      char revRotorChar;
      for (int j = 0; j < rotor3.size(); j++)
	{
	  if (userInVec.at(i) == rotor3.at(j))
	    {
	      revRotorChar = j;
	      break;
	    }
	}
      userInVec.at(i) = revRotorChar;
      
      for (int j = 0; j < rotor2.size(); j++)
	{
	  if (userInVec.at(i) == rotor2.at(j))
	    {
	      revRotorChar = j;
	      break;
	    }
	}
      userInVec.at(i) = revRotorChar;
      
      for (int j = 0; j < rotor1.size(); j++)
	{
	  if (userInVec.at(i) == rotor1.at(j))
	    {
	      revRotorChar = j;
                    break;
	    }
	}
      
      userInVec.at(i) = revRotorChar;
    }
    
    //2nd Plugboard switch
    for (int i= 0; i < userInVec.size(); i++)
    {
        int tempval = +userInVec.at(i);
        if (pv3.at(tempval) != -1)
        {
            userInVec.at(i) = pv3.at(tempval);
        }
    }
    
    std::cout << "The resultant output is:\n";
    for (int i = 0; i < userInVec.size();i++)
    {
      std::cout << userInVec.at(i);
    }
    std::cout << "\n";
    return 0;
}
