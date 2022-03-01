#include <bits/stdc++.h>
#include <cstring> //for strlen
using namespace std; 
int main()
{

  //   Vector in C++ STL    " #include <vector> " 
   /* Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is
    inserted or deleted, with their storage being handled automatically by the container.
    Vector elements are placed in contiguous storage so that they can be accessedand traversed using iterators.
    In vectors, data is inserted at the end.Inserting at the end takes differential time, 
    as sometimes there may be a need of extending the array.Removing the last element takes only constant time because
    no resizing happens.Insertingand erasing at the beginning or in the middle is linear in time.
    Certain functions associated with the vector are :
    Iterators
        1- begin() – Returns an iterator pointing to the first element in the vector 
        2- end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector 
        3- rbegin() – Returns a reverse iterator pointing to the last element in the vector(reverse beginning).
        It moves from last to first element
        4- rend() – Returns a reverse iterator pointing to the theoretical element preceding
        the first element in the vector(considered as reverse end)
        5- cbegin() – Returns a constant iterator pointing to the first element in the vector. 
        6- cend() – Returns a constant iterator pointing to the theoretical element that follows the last element
        in the vector.
        7- crbegin() – Returns a constant reverse iterator pointing to the last element in the vector(reverse beginning).
        It moves from last to first element
        8- crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element
        in the vector(considered as reverse end)*/

    /*vector <int>g1;
    for (int i = 0; i < 5; i++) {
        g1.push_back(i);
    }
    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); i++) {
        cout << *i << " ";
    }
    cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";

    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << " ";

    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << " ";*/
 
    /*Capacity

       1- size() – Returns the number of elements in the vector.
       2- max_size() – Returns the maximum number of elements that the vector can hold.
       3- capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of
        elements.
       4- resize(n) – Resizes the container so that it contains ‘n’ elements.
       5- empty() – Returns whether the container is empty.
       6- shrink_to_fit() – Reduces the capacity of the container to fit its sizeand destroys all elements
        beyond the capacity.
       7- reserve() – Requests that the vector capacity be at least enough to contain n elements.*/

    //vector<int> g1;

    //for (int i = 1; i <= 5; i++)
    //    g1.push_back(i);

    //cout << "Size : " << g1.size();
    //cout << "\nCapacity : " << g1.capacity();
    //cout << "\nMax_Size : " << g1.max_size();

    //// resizes the vector size to 4
    //g1.resize(4);

    //// prints the vector size after resize()
    //cout << "\nSize : " << g1.size();

    //// checks if the vector is empty or not
    //if (g1.empty() == false)
    //    cout << "\nVector is not empty";
    //else
    //    cout << "\nVector is empty";

    //// Shrinks the vector
    // g1.shrink_to_fit();
    //cout << "\nVector elements are: ";
    //for (auto it = g1.begin(); it != g1.end(); it++)
    //    cout << *it << " ";

    //cout << "\nCapacity : " << g1.capacity(); // see the Capacity after shrink to fit function 

    /*Element access :

    1- reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
    2- at(g) – Returns a reference to the element at position ‘g’ in the vector
    3- front() – Returns a reference to the first element in the vector
    4- back() – Returns a reference to the last element in the vector
    5- data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.*/

    //vector<int> g1;

    //for (int i = 1; i <= 10; i++)
    //    g1.push_back(i * 10);

    //cout << "Reference operator [g] : g1[2] = " << g1[2];

    //cout << "\nat : g1.at(4) = " << g1.at(4);

    //cout << "\nfront() : g1.front() = " << g1.front();

    //cout << "\nback() : g1.back() = " << g1.back();

    //// pointer to the first element
    //int* pos = g1.data();

    //cout << "\nThe first element is " << *pos;

      
     /* Modifiers:

        1- assign() – It assigns new value to the vector elements by replacing old ones
        2- push_back() – It push the elements into a vector from the back
        3- pop_back() – It is used to pop or remove elements from a vector from the back.
        4- insert() – It inserts new elements before the element at the specified position
        5- erase() – It is used to remove elements from a container from the specified position or range.
        6- swap() – It is used to swap the contents of one vector with another vector of same type.Sizes may differ.
        7- clear() – It is used to remove all the elements of the vector container
        8- emplace() – It extends the container by inserting new element at position
        9- emplace_back() – It is used to insert a new element into the vector container,
           the new element is added to the end of the vector*/
//
//           // Assign vector
//vector<int> v;
//
//// fill the array with 10 five times
//v.assign(5, 10);
//
//cout << "The vector elements are: ";
//for (int i = 0; i < v.size(); i++)
//    cout << v[i] << " ";
//
//// inserts 15 to the last position
//v.push_back(15);
//int n = v.size();
//cout << "\nThe last element is: " << v[n - 1];
//
//// removes last element
//v.pop_back();
//
//// prints the vector
//cout << "\nThe vector elements are: ";
//for (int i = 0; i < v.size(); i++)
//    cout << v[i] << " ";
//
//// inserts 5 at the beginning
//v.insert(v.begin(), 5);
//
//cout << "\nThe first element is: " << v[0];
//
//// removes the first element
//v.erase(v.begin());
//
//cout << "\nThe first element is: " << v[0];
//
//// inserts at the beginning
//v.emplace(v.begin(), 5);
//cout << "\nThe first element is: " << v[0];
//
//// Inserts 20 at the end
//v.emplace_back(20);
//n = v.size();
//cout << "\nThe last element is: " << v[n - 1];
//
//// erases the vector
//v.clear();
//cout << "\nVector size after erase(): " << v.size();
//
//// two vector to perform swap
//vector<int> v1, v2;
//v1.push_back(1);
//v1.push_back(2);
//v2.push_back(3);
//v2.push_back(4);
//
//cout << "\n\nVector 1: ";
//for (int i = 0; i < v1.size(); i++)
//    cout << v1[i] << " ";
//
//cout << "\nVector 2: ";
//for (int i = 0; i < v2.size(); i++)
//    cout << v2[i] << " ";
//
//// Swaps v1 and v2
//v1.swap(v2);
//
//cout << "\nAfter Swap \nVector 1: ";
//for (int i = 0; i < v1.size(); i++)
//    cout << v1[i] << " ";
//
//cout << "\nVector 2: ";
//for (int i = 0; i < v2.size(); i++){
//    cout << v2[i] << " ";
//}


             // pointers 

//
//int intarray[] = { 31, 54, 77, 52, 93 }; //array
//int* ptrint; //pointer to int
//ptrint = intarray; //points to intarray
//for (int j = 0; j < 5; j++) //for each element,
//cout << *(ptrint++) << endl; //print value
  
////  Ordering with Pointers
//void bsort(int*, int); //prototype
//const int N = 10; //array size
////test array
//int arr[N] = { 37, 84, 62, 91, 11, 65, 57, 28, 19, 49 };
//bsort(arr, N); //sort the array
//for (int j = 0; j < N; j++) //print out sorted array
//    cout << arr[j] << " ";
//cout << endl;


// Memory Management : newand delete 

//The new Operator
//C++ provides a different approach to obtaining blocks of memory : the new operator. This versatile
//operator obtains memory from the operating systemand returns a pointer to its starting
//point.The NEWINTRO example shows how new is used :
//#include <cstring> //for strlen 

//If your program reserves many chunks of memory using new, eventually all the available memory
//will be reservedand the system will crash.To ensure safeand efficient use of memory, the
//new operator is matched by a corresponding delete operator that returns memory to the operating
//system.In NEWINTRO the statement
//delete[] ptr;
//returns to the system whatever memory was pointed to by ptr.
//
//ptr = new SomeClass; // allocate a single object
//. . .
//delete ptr; // no brackets following delete
//delete[] str; // deleting array 

//int x = 10;
//void* i;
//i = &x;
////cout << *i << endl; // error 




    return 0; 
}

void bsort(int* ptr, int n)
{
    void order(int*, int*); //prototype
    int j, k; //indexes to array
    for (j = 0; j < n - 1; j++) //outer loop
        for (k = j + 1; k < n; k++) //inner loop starts at outer
            order(ptr + j, ptr + k); //order the pointer contents
}
//--------------------------------------------------------------
void order(int* numb1, int* numb2) //orders two numbers
{
    if (*numb1 > *numb2) //if 1st larger than 2nd,
    {
        int temp = *numb1; //swap them
        *numb1 = *numb2;
        *numb2 = temp;
    }
}
//The Bubble Sort
//The bsort() function sorts the array using a variation of the bubble sort.This is a simple
//(although notoriously slow) approach to sorting.Here’s how it works, assuming we want to
//arrange the numbers in the array in ascending order.First the first element of the array
//(arr[0]) is compared in turn with each of the other elements(starting with the second).If it’s
//greater than any of them, the two are swapped.When this is done we know that at least the
//first element is in order; it’s now the smallest element.Next the second element is compared in
//turn with all the other elements, starting with the third, and again swapped if it’s bigger.When
//we’re done we know that the second element has the second - smallest value.This process is
//continued for all the elements until the next - to - the - last, at which time the array is assumed to
//be ordered.Figure 10.8 shows the bubble sort in action(with fewer items than in PTRSORT).
//In PTRSORT, the number in the first position, 37, is compared with each element in turn, and
//swapped with 11. The number in the second position, which starts off as 84, is compared with
//each element.It’s swapped with 62; then 62 (which is now in the second position) is swapped
//with 37, 37 is swapped with 28, and 28 is swapped with 19. The number in the third position,
//which is 84 again, is swapped with 62, 62 is swapped with 57, 57 with 37, and 37 with 28. The
//process continues until the array is sorted.
//The bsort() function in PTRSORT consists of two nested loops, each of which controls a
//pointer.The outer loop uses the loop variable j, and the inner one uses k.The expressions
//ptr + j and ptr + k point to various elements of the array, as determined by the loop variables.
//The expression ptr + j moves down the array, starting at the first element(the top) and stepping
//down integer by integer until one short of the last element(the bottom).For each position
//taken by ptr + j in the outer loop, the expression ptr + k in the inner loop starts pointing one
//below ptr + j and moves down to the bottom of the array.Each time through the inner loop, the
//Chapter 10
//450
//elements pointed to by ptr + j and ptr + k are compared, using the order() function, and if the
//first is greater than the second, they’re swapped.Figure 10.9 shows this process.