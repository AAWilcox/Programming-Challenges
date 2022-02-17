// Filename:             backpack.cpp
// Programmer :          Alyssa Wilcox
// Date :                2 / 16 / 2022
/* Description:          You have two backpacks of volumes Aand B. You also have N objects, for each
                         object i you know its volume Vi. You are planning to go on a trip, so you decide
                         to pack the objects. You take each object in order and try to pack it in the
                         backpack that's got the most room left. If you can't pack an object you are
                         going to leave it home. Find the number of objects left home. 
*/

//A = volume of bag A, B = volume of bag B, N = number of items
var A = 7;
var B = 5;
const N = 8;

//Number of items left home
var ans = 0;

//Volumes of items to pack
const volumes = [3, 1, 4, 2, 5, 1, 4, 3];

//To hold the volumes of the items placed in each bag
//Not necessary in the scope of this problem!
const bag_A = [];
const bag_B = [];

//Go through each item
volumes.forEach(function(item)
{
    //A has more space than B and object fits in bag A
    if(A >= B && item <= A)
    {
        //Place object into bag A
        bag_A.push(item);
        //Update the volume of bag A
        A = A - item;
    }
    //B has more space than A and object fits in bag B
    else if(A < B && item <= B)
    {
        //Place object into bag B
        bag_B.push(item);
        //Update the volume of bag B
        B = B - item;
    }
    //Item does not fit in either bag. Leave it home
    else
    {
        //Update the number of items left at home
        ans++;
    }
});

//Display results
console.log("Volumes of items in bag A: ", bag_A);
console.log("Volumes of items in bag B: ", bag_B);
console.log("The number of items left home: ", ans);