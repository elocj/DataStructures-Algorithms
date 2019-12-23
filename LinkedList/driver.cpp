//
// Created by Anthony Joo on 2019-02-26.
//

#include <iostream>
#include "LinkedList.h"
#include "Child.h"
//#include "LinkedList.cpp"
//#include "Child.cpp"

using namespace std;


int main(){
    Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13),c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
    Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
    LinkedList<Child> class1, class2, soccer, chess;
    int a = 1, b = -1, c = 13;
    class1.Insert(&c1);
    class1.Insert(&c2);
    class1.Insert(&c3);
    class1.Insert(&c4);
    class1.Insert(&c5);
    class1.Insert(&c6);
    class1.Insert(&c5);
    cout << "class1: "<< class1 << endl;
    if(class1.Insert(&c1))
    {
        cout << "ERROR::: Duplicate"<< endl;
    }
    class2.Insert(&c4);
    class2.Insert(&c5);
    class2.Insert(&c6);
    class2.Insert(&c7);
    class2.Insert(&c10);
    cout << "Class2: "<< class2 << endl;
    class1.Merge(class2);
    class2.Merge(class1);
    class1.Merge(class2);
    class1.Merge(class1);
    cout << "class1 and 2 Merged: "<< class1 << endl;
    if(!class2.isEmpty())
    {
        cout << "ERROR:: Class2 should be empty empty"<< endl;
    }
    class1.Remove(c4, c11);
    class1.Remove(c5, c11);
    class1.Remove(c11, c11);
    if(class1.Remove(c1, c11))
    {
        cout << "Removed from class1, student "<< c11 << endl;
    }
    cout << "class1: "<< class1 << endl;
    soccer.Insert(&c6);
    soccer.Insert(&c4);
    soccer.Insert(&c9);
    cout << "soccer: "<< soccer << endl;
    soccer += class1;
    cout << "soccer += class1 : "<< soccer << endl;
    LinkedList<Child> football = soccer;
    if(football == soccer)
    {
        cout << "football: "<< football << endl;
    }
    if(football.Peek(c6, c11))
    {
        cout << c11 << " is on the football team"<< endl;
    }
    soccer.DeleteList();
    if(!soccer.isEmpty())
    {
        cout << "ERROR: soccer should be empty"<< endl;
    }
    LinkedList<int> numbers;
    numbers.Insert(&a);
    numbers.Insert(&b);
    numbers.Insert(&c);
    cout << "These are the numbers: "<< numbers << endl;
    numbers.DeleteList();

    // Test BuildList
    LinkedList<Child> test, temp;
    test.BuildList("/Users/anthonyjoo/Google Drive/CSS342Lab4/text3.txt");
    temp.Insert(&c1);
    temp.Insert(&c2);
    temp.Insert(&c3);
    temp.Insert(&c4);
    temp.Insert(&c5);
    temp.Insert(&c6);
    temp.Insert(&c5);
    if(test == temp)
    {
        cout << "Both BuildList and the equality (==) operator work properly" << endl;
        cout << "From Insert temp = " << temp << endl;
        cout << "From BuildList test = " << test << endl;
    }

    // Test DeleteList and isEmpty
    temp.DeleteList();
    if(temp.isEmpty())
    {
        cout << "Both DeleteList and isEmpty work properly" << endl;
    }

    // Test LinkedList of string

    // Tests Merge
    LinkedList<string> list1, list2, list3, list4;
    string val1 = "hey", val2 = "dodgy", val3 = "water", val4 = "to", val5 = "vanilla", val6 = "wafer", val7;
    list1.Insert(&val1);
    list1.Insert(&val2);
    list1.Insert(&val3);
    list2.Insert(&val1);
    list2.Insert(&val2);
    list2.Insert(&val3);
    if(!list1.Merge(list2))
    {
        cout << "Confirms that Merge will return false when passed in two equal lists" << endl;
    }
    if(!list1.Merge(list3))
    {
        cout << "Confirms that passing in an empty list into merge will return false" << endl;
    }
    list3.Insert(&val4);
    list3.Insert(&val5);
    list3.Insert(&val6);
    list4.Insert(&val1);
    list4.Insert(&val2);
    list4.Insert(&val3);
    list4.Insert(&val4);
    list4.Insert(&val5);
    list4.Insert(&val6);
    list1.Merge(list3);
    if(list1 == list4)
    {
        cout << "Merge works for a linked list of strings as well" << endl;
        cout << "list1 = " << list1 << endl;
        cout << "list4 = " << list4 << endl;
    }
    if(list3.isEmpty())
    {
        cout << "Confirms that Merge properly deletes the passed in list (in this case list3)" << endl;
    }
    list2.BuildList("/Users/anthonyjoo/Google Drive/CSS342Lab4/text.txt");
    cout << "Tests whether or not BuildList can build onto a preexisting list" << endl;
    cout << "list2: " << list2 << endl;
    list3.BuildList("/Users/anthonyjoo/Google Drive/CSS342Lab4/text.txt");
    cout << "Test whether BuildList works for non-Child objects such as string" << endl;
    cout << "list3: " << list3 << endl;
    list1.DeleteList();
    list2.DeleteList();
    list3.DeleteList();
    list1.Insert(&val2);
    list1.Insert(&val3);
    list1.Insert(&val4);
    list2.Insert(&val3);
    list2.Insert(&val4);
    list2.Insert(&val5);
    list3.Insert(&val2);
    list3.Insert(&val3);
    list3.Insert(&val4);
    list3.Insert(&val3);
    list3.Insert(&val4);
    list3.Insert(&val5);
    list1.Merge(list2);
    if(list1 == list3)
    {
        cout << "Confirms that Merge can properly merge two lists with SOME identical elements" << endl;
        cout << "list1: " << list1 << endl;
        cout << "list3: " << list3 << endl;
    }

    // Tests overloaded operators
    list1.Insert(&val1);
    list1.Insert(&val2);
    list1.Insert(&val3);
    list2.Insert(&val4);
    list2.Insert(&val5);
    list2.Insert(&val6);
    list3 = list1 + list2;
    list1 += list2;
    if(list1 == list3)
    {
        cout << "Operators =, +, ==, and += work as proven by the equality of list1 and list3" << endl;
        cout << "list3 = list1 + list2: " << list3 << endl;
        cout << "list1 += list2: " << list1 << endl;
    }
    if(list1 == list2)
    {
        cout << "Operator == does not work if this statement is printed" << endl;
    }
    if(list1 != list3)
    {
        cout << "Operator != does not work if this statement is printed" << endl;
    }
    if(list1 != list2)
    {
        cout << "Operator != works since the inequality in the if statement passes" << endl;
    }

    // Tests the Peek
    list4.DeleteList();
    list1.Peek(val2, val7);
    cout << "Tests whether Peek works when we are looking for the first value in the list (dodgy)" << endl;
    cout << "val7: " << val7 << endl;
    list1.Peek(val3, val7);
    cout << "Tests whether Peek works when we are looking for the last value in the list (water)" << endl;
    cout << "val7: " << val7 << endl;
    list1.Peek(val5, val7);
    cout << "Tests whether Peek works for a value somewhere in the middle of the list (vanilla)" << endl;
    cout << "val7: " << val7 << endl;
    if(!list4.Peek(val1, val7))
    {
        cout << "Peek functions correctly, returning false if the linked list is empty" << endl;
    }

    // Tests Remove
    list1.Remove(val2, val7);
    cout << "If the first value in list1 (dodgy) is removed and referenced to val7 then Remove works" << endl;
    cout << "list1: " << list1 << endl;
    cout << "val7: " << val7 << endl;
    list1.Remove(val3, val7);
    cout << "If the last value in list1 (water) is removed and referenced to val7 then Remove works" << endl;
    cout << "list1: " << list1 << endl;
    cout << "val7: " << val7 << endl;
    list1.Remove(val5, val7);
    cout << "If the last value in list1 (vanilla) is removed and referenced to val7 then Remove works" << endl;
    cout << "list1: " << list1 << endl;
    cout << "val7: " << val7 << endl;
    if(!list4.Remove(val1, val7))
    {
        cout << "Remove functions correctly, returning false if the linked list is empty" << endl;
    }

    // Some tests for Linked Lists with integers

    // Testing insert
    int d = 29, e = 35, f = 22, g = 15, h = 31, i = 41, j;
    LinkedList<int> num;
    num.Insert(&d);
    num.Insert(&e);
    num.Insert(&f);
    num.Insert(&g);
    cout << "Testing if Insert works properly when inserting into the front of the linked list "<< endl;
    cout << "num: " << num << endl;
    num.Insert(&h);
    cout << "Testing if Insert works properly when inserting into the middle of the linked list "<< endl;
    cout << "num: " << num << endl;
    num.Insert(&i);
    cout << "Testing if Insert works properly when inserting into the end of the linked list "<< endl;
    cout << "num: " << num << endl;

    // Testing Remove
    num.Remove(g, j);
    cout << "Testing if Remove works properly when removing from the front of the linked list "<< endl;
    cout << "num: " << num << endl;
    cout << "removed: " << j << endl;
    num.Remove(h, j);
    cout << "Testing if Remove works properly when removing from the middle of the linked list "<< endl;
    cout << "num: " << num << endl;
    cout << "removed: " << j << endl;
    num.Remove(i, j);
    cout << "Testing if Remove works properly when removing from the end of the linked list "<< endl;
    cout << "num: " << num << endl;
    cout << "removed: " << j << endl;

    // Testing Peek
    num.Peek(f, j);
    cout << "Testing if Peek works properly when peeking onto the front of the linked list "<< endl;
    cout << "num: " << num << endl;
    cout << "peeked: " << j << endl;
    num.Peek(d, j);
    cout << "Testing if Peek works properly when peeking onto the middle of the linked list "<< endl;
    cout << "num: " << num << endl;
    cout << "peeked: " << j << endl;
    num.Peek(e, j);
    cout << "Testing if Peek works properly when peeking onto the end of the linked list "<< endl;
    cout << "num: " << num << endl;
    cout << "peeked: " << j << endl;

    // Testing Remove (cont.)
    if(!num.Remove(a, j))
    {
        cout << "Remove should return false because a is a value that does not exist in the list" << endl;
        cout << "num: " << num << endl;
    }
    num.Remove(f, j);
    num.Remove(d, j);
    num.Remove(e, j);
    if(!num.Remove(f, j))
    {
        cout << "Remove should return false because the list is empty" << endl;
        cout << "num: " << num << endl;
    }

    // Testing Peek (cont.)
    num.Insert(&f);
    cout << num << endl;
    if(!num.Peek(a, j))
    {
        cout << "Peek should return false because a is a value that does not exist in the list" << endl;
        cout << "num: " << num << endl;
    }
    num.Remove(f, j);
    if(!num.Peek(f, j))
    {
        cout << "Peek should return false because the list is empty" << endl;
        cout << "num: " << num << endl;
    }

    // Testing BuildList

    // Building List with an empty file
    LinkedList<Child> sample;
    sample.BuildList("/Users/anthonyjoo/Google Drive/CSS342Lab4/text4.txt");
    cout << "Should print an empty Linked List" << endl;
    cout << "sample: " << sample << endl;

    // Building List with a file with one element
    sample.BuildList("/Users/anthonyjoo/Google Drive/CSS342Lab4/text5.txt");
    cout << "Should print a Linked List with only one value" << endl;
    cout << "sample: " << sample << endl;
    return 0;
}