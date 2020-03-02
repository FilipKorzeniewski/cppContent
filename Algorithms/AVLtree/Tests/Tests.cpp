#include "Tests.hpp"
#include "AVLtree.hpp"

void count_words_test(){

    cout << "COUNT WORDS FUNCTION TEST:" << endl << endl;
    AVLtree<string,string> A;
    ifstream fin;
    fin.open("test2.txt");
    int howmany = count_words(A, fin);
    A.printIn();
    cout << endl << "There are "<< howmany <<" words in the file" << endl;
    cout << "----------------------------" << endl;
}

void insert_remove_test(){
    
    cout << "INSERT/REMOVE FUNCTION TEST" << endl << endl;
    AVLtree<string,string> A;
    ifstream fin;
    fin.open("test3.txt");
    count_words(A, fin);
    A.printIn();
    cout<<endl<<endl;
    cout << "Starting values:" << endl;
    AVLtree<int,int> B;
    B.insert(7,2);
    B.insert(8,3);
    B.insert(5,1);
    B.insert(6,1);
    B.insert(4,3);
    B.print();
    cout << endl << "After Removing 7:" << endl;
    B.remove(7);
    B.print();
    cout << endl << "After Removing 154:" << endl;
    B.remove(154);
    B.print();
    cout << endl << "After Removing 4:" << endl;
    B.remove(4);
    B.print();
    cout<<endl;
    
    cout << "----------------------------" << endl;
}

void rotate_test(){
    cout << "ROTATE TESTS" << endl << endl;

    cout << "Left Left Case:" << endl << endl;
    cout << "Starting values:" << endl;
    AVLtree<int,int> A;
    A.insert(7,2);
    A.insert(8,3);
    A.insert(5,1);
    A.insert(6,1);
    A.insert(4,3);
    A.print();
    
    cout << "After adding 1:" << endl;
    A.insert(1,2);
    A.print();
    
    
    cout << "Right Right Case:" << endl << endl;
    cout << "Starting values:" << endl;
    A.remove(1);
    A.print();
    
    cout << "After adding 9: "<< endl;
    A.insert(9,4);
    A.print();
    
    A.clearAll();

    
    cout << "Left Right Case:" << endl << endl;
    cout << "Starting values:" << endl;
    A.insert(5,3);
    A.insert(7,4);
    A.insert(1,3);
    A.insert(3,5);
    A.print();
    
    cout << "After adding 2: "<< endl;
    A.insert(2, 4);
    A.print();
    
    A.clearAll();
    
    
    cout << "Right Left Case:" << endl << endl;
    cout << "Starting values:" << endl;
    A.insert(4,3);
    A.insert(3,2);
    A.insert(9,2);
    A.insert(7,4);
    A.print();
    
    cout << "After adding 8: "<< endl;
    A.insert(8,3);
    A.print();
    
    cout<<endl;
    cout << "----------------------------" << endl;
}

void operator_constructor_test(){
    
    cout << "OPERATOR/CONSTRUCTOR TESTS" << endl << endl;
    cout << "Default constructor ():" << endl;
    AVLtree<int,int> A;
    A.print();
    
    cout << endl;
    cout << "Copy constructor:" << endl;
    cout << "Tree A is empty:" << endl;
    A.print();
    cout<<endl;
    cout << "B(A):" << endl;
    AVLtree<int,int> B(A);
    B.print();
    cout << endl;
    cout << "Starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.insert(3,2);
    A.insert(5,3);
    A.print();
    cout << "After using C(A); tree C values: " << endl;
    AVLtree<int,int> C(A);
    C.print();
    A.clearAll();
    B.clearAll();
    C.clearAll();

    cout << "Operator = test:" << endl<< endl;
    cout << "First case - starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.print();
    cout << "Tree B values:" << endl;
    B.insert(3,2);
    B.insert(5,3);
    B.print();
    cout << "After A = B:" << endl;
    cout << "Tree A values:" << endl;
    A = B;
    A.print();
    A.clearAll();
    B.clearAll();
    
    cout << "2nd case - starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.print();
    cout << "Tree B values:" << endl;
    B.insert(3,2);
    B.insert(5,3);
    B.print();
    cout << "After B = A:" << endl;
    cout << "Tree B values:" << endl;
    B = A;
    B.print();
    
    
    cout << "3rd case - starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.insert(2,4);
    A.insert(4,2);
    A.insert(1,5);
    A.insert(5,1);
    A.print();
    cout << "Tree B values:" << endl;
    B.insert(3,2);
    B.insert(5,3);
    B.print();
    cout << "After B = A:" << endl;
    cout << "Tree B values:" << endl;
    B = A;
    B.print();
    
    cout << "4th case - self-assign:" << endl;
    cout << "Tree A values:" << endl;
    A.print();
    cout << "After A = A:" << endl;
    A = A;
    A.print();
    cout << endl;
    A.clearAll();
    B.clearAll();
    
    cout << "Operator += test:" << endl<< endl;
    cout << "First case - starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.print();
    cout << "Tree B values:" << endl;
    B.insert(3,2);
    B.insert(5,3);
    B.print();
    cout << "After A += B:" << endl;
    cout << "Tree A values:" << endl;
    A += B;
    A.print();
    A.clearAll();
    B.clearAll();
    
    cout << "2nd case - starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.print();
    cout << "Tree B values:" << endl;
    B.insert(3,2);
    B.insert(5,3);
    B.print();
    cout << "After B = A:" << endl;
    cout << "Tree B values:" << endl;
    B += A;
    B.print();
    
    cout << "3rd case - starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.insert(2,4);
    A.insert(4,2);
    A.insert(1,5);
    A.insert(5,1);
    A.print();
    cout << "Tree B values:" << endl;
    B.insert(3,2);
    B.insert(5,3);
    B.print();
    cout << "After B += A:" << endl;
    cout << "Tree B values:" << endl;
    B += A;
    B.print();
    
    cout << "4th case - self-assign:" << endl;
    cout << "Tree A values:" << endl;
    A.print();
    cout << "After A = A:" << endl;
    A += A;
    A.print();
    cout << endl;
    A.clearAll();
    B.clearAll();
    
    cout << "Operator + test:" << endl<< endl;
    cout << "First case - starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.print();
    cout << "Tree B values:" << endl;
    B.insert(3,2);
    B.insert(5,3);
    B.print();
    cout << "After C = A + B:" << endl;
    cout << "Tree C values:" << endl;
    C = A + B;
    C.print();
    A.clearAll();
    B.clearAll();
    C.clearAll();
    
    cout << "2nd case - starting values:" << endl;
    cout << "Tree A values:" << endl;
    A.insert(2,4);
    A.insert(4,2);
    A.insert(1,5);
    A.insert(5,1);
    A.print();
    cout << "Tree B values:" << endl;
    B.insert(3,2);
    B.insert(5,3);
    B.print();
    cout << "After C = A + B:" << endl;
    cout << "Tree C values:" << endl;
    C = A + B;
    C.print();
    A.clearAll();
    B.clearAll();
    C.clearAll();
    
    cout << endl;
    cout << "----------------------------" << endl;
}

void find_test(){
    
    cout << "FIND FUNCTION TEST" << endl << endl;
    AVLtree<int,int> A;
    cout << "For empty case:" << endl;
    cout << "Tree A:" << endl;
    A.print();
    cout << "Looking for 5:" << endl;
    A.find(5);
    cout << endl;
    cout << "Starting values:" << endl;
    A.insert(7,2);
    A.insert(8,3);
    A.insert(5,1);
    A.insert(6,1);
    A.insert(4,3);
    A.print();
    
    cout << "Starting values:" << endl;
    cout << "Looking for 32:" << endl;
    A.find(32);
    cout << endl;
    cout << "Looking for 5:" << endl;
    A.find(5);
    A.clearAll();
    
    
    cout<<endl;
    cout << "----------------------------" << endl;
}

void map_compare_test(){
    
    cout << "COMPARING WITH MAP.H TEST" << endl << endl;

    
    map<string,string> mapObj;
    map<string,string>::iterator it;

    AVLtree<string,string> A;
    AVLtree<string, string>::iterator itA = AVLtree<string,string>::iterator(A, nullptr);
    std::ifstream fin;
    fin.open("test.txt");

    string exist;
    string word;
    string random;
    
    auto startAVL1 = chrono::high_resolution_clock::now();
    int total_number_of_words = 0;
    while(fin >> word){
        total_number_of_words++;
        exist = "0";
        itA = A.insert(word,exist);
        exist = to_string(stoi(itA.getInfo()) + 1);
        itA.setInfo(exist);
    }
    auto stopAVL1 = chrono::high_resolution_clock::now();
    auto durationAVL1 = chrono::duration_cast<chrono::microseconds>(stopAVL1 - startAVL1);
    fin.close();
    
    fin.open("test.txt");
    auto startMap1 = chrono::high_resolution_clock::now();
    total_number_of_words = 0;
    while(fin >> word){
        total_number_of_words++;
        random = to_string( total_number_of_words%100 + 1 );
        mapObj.insert(make_pair(word, random));
    }
    auto stopMap1 = chrono::high_resolution_clock::now();
    auto durationMap1 = chrono::duration_cast<chrono::microseconds>(stopMap1 - startMap1);
    
    fin.close();
    
//    A.printIn();
    cout << "there are " << total_number_of_words << " words in text" << endl;
    cout << "Looking for \"where\" word:" << endl;
    cout << "AVL tree function:" << endl;
    
    auto startAVL2 = chrono::high_resolution_clock::now();
    A.find("where");
    auto stopAVL2 = chrono::high_resolution_clock::now();
    auto durationAVL2 = chrono::duration_cast<chrono::microseconds>(stopAVL2 - startAVL2);

    cout << endl;
    cout << "For \"map.h\":" << endl;
    
    auto startMap2 = chrono::high_resolution_clock::now();
    it = mapObj.find("where");
    auto stopMap2 = chrono::high_resolution_clock::now();
    auto durationMap2 = chrono::duration_cast<chrono::microseconds>(stopMap2 - startMap2);
    
    cout << "key: " << it->first << " info: " << it->second << endl;
    
    cout << endl;
    cout << "Measured time of inserting elements:" << endl;
    cout << "For AVLtree class: " << durationAVL1.count() << endl;
    cout << "For \"map.h\": " << durationMap1.count() << endl;
    
    cout << endl;
    cout << "Measured time of finding a \"where\" word:" << endl;
    cout << "For AVLtree class: " << durationAVL2.count() << endl;
    cout << "For \"map.h\": " << durationMap2.count() << endl;
    
    
    
    cout << "Looking for \"Muggle\" word:" << endl;
    cout << "AVL tree function:" << endl;
    
    auto startAVL3 = chrono::high_resolution_clock::now();
    A.find("Muggle");
    auto stopAVL3 = chrono::high_resolution_clock::now();
    auto durationAVL3 = chrono::duration_cast<chrono::microseconds>(stopAVL3 - startAVL3);

    cout << endl;
    cout << "For \"map.h\":" << endl;
    
    auto startMap3 = chrono::high_resolution_clock::now();
    it = mapObj.find("Muggle");
    auto stopMap3 = chrono::high_resolution_clock::now();
    auto durationMap3 = chrono::duration_cast<chrono::microseconds>(stopMap3 - startMap3);
    
    cout << "key: " << it->first << " info: " << it->second << endl;
    
    cout << endl;
    cout << "Measured time of finding an element:" << endl;
    cout << "For AVLtree class: " << durationAVL3.count() << endl;
    cout << "For \"map.h\": " << durationMap3.count() << endl;
}

