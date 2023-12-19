#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector<int> > triangle;
    
    int size = 1026;
    
    vector<int> a;
    a.push_back(1); 
    triangle.push_back(a);
    
    for(int x = 0; x < size; x++)
    {
        vector<int> row;
        row.push_back(1);
        for(int y = 1; y < x-1; y++)
            row.push_back(triangle[x][y] + triangle[x][y-1]);
            
        row.push_back(1);
        triangle.push_back(row);
    }
    
    for(int i = 2; i < size; i++)
    {
        for(int j = 0; j < (size-i)/2; j++)
        	cout << " ";
        	
        for(int j = 0; j < i-1; j++)
        {
            if (triangle[i][j]%2 !=0)
            	cout << "00";
            else
                cout << "  ";
        }
        cout << "\n";
    }
    
    return 0;
}

