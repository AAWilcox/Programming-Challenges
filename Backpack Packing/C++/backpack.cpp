// Filename:             backpack.cpp
// Programmer :          Alyssa Wilcox
// Date :                2 / 16 / 2022
/* Description:          You have two backpacks of volumes Aand B. You also have N objects, for each
                         object i you know its volume Vi. You are planning to go on a trip, so you decide
                         to pack the objects. You take each object in order and try to pack it in the
                         backpack that's got the most room left. If you can't pack an object you are
                         going to leave it home. Find the number of objects left home. 
*/ 

#include <iostream>
#include <vector>

using namespace std;

//Prototype function
void print_vector(const vector<int>&);

int main()
{
    //A = volume of bag A, B = volume of bag B, N = number of items
    int A, B, N;
    cout << "Input the volume of A, B, and the number of objects" << endl;
    cin >> A >> B >> N;

    //To hold the volume of each item in each bag
    //These is not needed in the scope of this problem! It is only personal preference
    vector<int> A_Bag;
    vector<int> B_Bag;

    //The number of items left home
    int ans = 0;
    
    //Get the volumes of each item
    int vol = 0;
    vector<int> volumes;
    cout << "Input the volumes of the objects" << endl;
    for(int i = 0; i < N; i++)
    {
        cin >> vol;
        volumes.push_back(vol);
    }

    //Go through all N objects, place them in bags
    for(int i = 0; i < N; i++)
    {
        //A has more space than B and object fits in bag A
        if (A >= B && volumes[i] <= A)
        {
            //Place object i into bag A
            A_Bag.push_back(volumes[i]);
            //Update the room left in bag A
            A -= volumes[i];
        }
        //B has more space than A and object fits in bag B
        else if(A <= B && volumes[i] <= B)
        {
            //Place object i into bag B
            B_Bag.push_back(volumes[i]);
            //Update the room left in bag B 
            B -= volumes[i];
        //No space for the item
        }
        //Item does not fit in either bag. Leave it home
        else
        {
            //Do not include the item. Update number of items left at home
            ans++;
        }
    }
    
    //Print the volumes of each item in each bag
    cout << "A = ";
    print_vector(A_Bag);
    cout << "B = ";
    print_vector(B_Bag);
    
    //Print the number of items left home
    cout << "Items left home: " << ans << endl;
    
    return 0;
}

//Print a vector, passed by constant reference
void print_vector(const vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}


