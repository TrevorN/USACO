/*
ID: trevor.1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int dictSize;

char numToChar(int input, int index)
{
    index = (input * 10) + index;
    
    switch (index)
    {
        case 20: return 'A';
        case 21: return 'B';
        case 22: return 'C';
        case 30: return 'D';
        case 31: return 'E';
        case 32: return 'F';
        case 40: return 'G';
        case 41: return 'H';
        case 42: return 'I';
        case 50: return 'J';
        case 51: return 'K';
        case 52: return 'L';
        case 60: return 'M';
        case 61: return 'N';
        case 62: return 'O';
        case 70: return 'P';
        case 71: return 'R';
        case 72: return 'S';
        case 80: return 'T';
        case 81: return 'U';
        case 82: return 'V';
        case 90: return 'W';
        case 91: return 'X';
        case 92: return 'Y';
    }
    
    return 'Z';
}

char* possibleName(int* name, int num, int length)
{
	char* newName = new char[length];
    
    int i = 0;
    while(i < length)
    {
        newName[i] = numToChar(name[i], (num * 3 / (int) pow(3, length - i)) % 3);
        
//	cout << (num * 3 / (int) pow(3, length - i)) % 3;
	        
        i++;
    }

    return newName;
}

int checkReal(char* name, char* dict, int length)
{
    
    int i = 0;
    
    while(i < dictSize)
    {
        int j = 0;
        int flag = 1;
        
        while(j < length)
        {
            
            if(name[j] != dict[i])
            {
                flag = 0;
            }
            
            j++;
            i++;
        }
        
        if(flag == 1)
        {
            return 1;
        }
    }
               
    return 0;
}

char* initializeDict(int length)
{
	ifstream fin ("dict.txt");
    
	char* names = new char[5000 * length];
    
    int i = 0;
	int j = 0;
    
	while(i < 5000)
	{
		char *tmp;
        
		fin >> (tmp = new char);
        
        int flag = 1;
        
        int x = 0;
        
        while(x < length)
        {
            if(tmp[x] == 0)
            {
                flag = 0;
            }
            
            x++;
        }
        
        if(tmp[length] != 0)
        {
            flag = 0;
        }
        
		if(flag == 1)
		{
			int m = 0;
            
			while(m < length)
			{
				names[j] = tmp[j % length];
				j++;
				m++;
			}
            
		}
        
        if(tmp[0] == 'Z' && tmp[1] == 'Y' && tmp[2] == 'T' && tmp[3] == 'A' && length == 4)
        {
            break;
        }
        
        delete [] tmp;
        
        i++;
	}
    
    //Now shrink to fit.
    
    int bigLength = 0;
    while(bigLength < 5000 * length)
    {
        if(names[bigLength] == 0)
        {
            break;
        } else {
            bigLength++;
        }
    }
    
    char* finalArray = new char[bigLength];
    
    i = 0;
    while(i < bigLength)
    {
        finalArray[i] = names[i];
        i++;
    }

    delete[] names;
    
    dictSize = bigLength;
    
	return finalArray;
}

int main()
{
	ofstream fout ("namenum.out");
	ifstream fin ("namenum.in");
	
	unsigned int name;
	fin >> name;
	cout << name << endl;
	unsigned int namecpy = name;
	int length = 0;

	while(namecpy != 0)
	{
		cout << namecpy << endl;
		namecpy /= 10;
		length++;
	}

//DEBUGGING
	cout << length << endl;
//ENDDEBUGGING
    
    	int* parsedName = new int[length];

	int i = 0;
	while(i < length)
	{
		parsedName[length - i - 1] = name % 10;
		name /= 10;
		i++;
	}
    
//DEBUGGING
    i = 0;
    while(i < length)
    {
        cout << parsedName[i];
        i++;
    }
    
    cout << endl;
//ENDDEBUGGING

	char* dict = initializeDict(length);
    
//End input
	
	int tmp = (int) pow(3, length);

	char* possibleNames = new char[tmp * length];

	i = 0;

	while(i < tmp * length)
	{
		possibleNames[i] = 0;
		i++;
	}

	int j = 0;
	i = 0;

	while(i < tmp)
	{
        
		if(checkReal(possibleName(parsedName, i, length), dict, length) == 1)
		{
            
			int m = 0;

			char* toStore = possibleName(parsedName, i, length);

			while(m < length)
			{
				possibleNames[j] = toStore[m];
				j++;
				m++;
			}
		}

		i++;
	}
/*
	i = 0;

	while(i < pow(3, length))
	{
		int m = 0;

		char* toStore = possibleName(parsedName, i, length);

		while(m < length)
		{
			cout << toStore[m];
			m++;
		}

		cout << endl;
		
		i++;
	}
*/
	i = 0;
   	int printed = 0;
    
	while(i < tmp)
	{
		if(possibleNames[i] == 0)
		{
			break;
		} else {
			cout << possibleNames[i];
			fout << possibleNames[i];
			printed++;
		}

		if(i % length == length - 1)
		{
			cout << endl;
			fout << endl;
		}
        
	        i++;
	}

	if(printed == 0)
	{
		fout << "NONE" << endl;
	}

	return(0);
}
