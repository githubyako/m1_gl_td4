#include <iostream>
#include "matrix.hpp"
#include "node.hpp"
#include "person.hpp"

int main(int argc, char **argv) {
    std::vector<std::vector<int> > v1,v2;
    std::vector<int> r1{1, 0}, r2{-1,3},r3{3,1},r4{2,1};
    v1.push_back(r1);
    v1.push_back(r2);
    v2.push_back(r3);
    v2.push_back(r4);
    Matrix<int> m1(v1),m2(v2);

    std::cout << "m1:" << std::endl;
    m1.show();
    std::cout << "m2:" << std::endl;
    m2.show();
    
    Matrix<int> m3;
    
    m3 = m1;
    std::cout << "m3=m1:" << std::endl;
    m3.show();
    std::cout << std::endl;
    m1*m2;
    Matrix<int> m4= m1*m2;
    std::cout << "m4:" << std::endl;
    m4.show();
    std::cout << "m4 inverted:" << std::endl;
    m4.invert();
    m4.show();
    std::cout << "Matrix<int> m5 = { 2, 3, 1, 2, 3, 4, 5, 6}" << std::endl;
    Matrix<int> m5 = { 2, 3, 1, 2, 3, 4, 5, 6};
    m5.show();
    std::cout << "Matrix<int> m6( { 2, 3, 1, 2, 3, 4, 5, 6} ) " << std::endl;
    Matrix<int> m6( { 2, 3, 1, 2, 3, 4, 5, 6} );
    m6.show();
    std::cout << "Matrix<int> m7(2, 3, { -1, -2, -3, -4, -5, -6});" << std::endl;
    Matrix<int> m7(2, 3, { -1, -2, -3, -4, -5, -6});
    m7.show();
    
    
    /*
     * 
     *      NODES INT
     * 
     */
    std::cout << std::endl << "NODES INT: " << std::endl;
    Node<int> * n1 = new Node<int>(1), * n2= new Node<int>(11),* n3= new Node<int>(12),* n4= new Node<int>(111),* n5= new Node<int>(112);
    n1->add(n2);
    n1->add(n3);
    n2->add(n4);
    n2->add(n5);
    std::cout << *n1 << std::endl;
    Node<int> * n1clone = n1->clone();
    std::cout << "clone de n1=" << std::endl << *n1clone << std::endl;
    
    /*
     *      NODES PERSON
     * 
     */
    std::cout << std::endl << "NODES PERSON: " << std::endl;
    
    Person p1("Ma Dalton", 60), p2("Averell", 30), p3("Joe", 31), p4("William", 29), p5("Jack", 28);
    Node<Person> * np1 = new Node<Person>(p1), *np2 = new Node<Person>(p2), *np3 = new Node<Person>(p3), *np4 = new Node<Person>(p4), *np5 = new Node<Person>(p5);
    np1->add(np2);
    np1->add(np3);
    np1->add(np4);
    np1->add(np5);
    std::cout << *np1 << std::endl;
    Node<Person> * np1clone = np1->clone();
    std::cout << "clone de np1=" << std::endl << *np1clone << std::endl;
    
    /*
     *      NODES PERSON POINTERS
     * 
     */
    std::cout << std::endl << "NODES PERSON POINTERS: " << std::endl;
    
    Person * pp1 = new Person("Ma Dalton", 60), * pp2 = new Person("Averell", 30),* pp3 = new Person("Joe", 31),* pp4 = new Person("William", 29),* pp5 = new Person("Jack", 28);
    Node<Person*> * npp1 = new Node<Person*>(pp1), *npp2 = new Node<Person*>(pp2), *npp3 = new Node<Person*>(pp3), *npp4 = new Node<Person*>(pp4), *npp5 = new Node<Person*>(pp5);
    npp1->add(npp2);
    npp1->add(npp3);
    npp1->add(npp4);
    npp1->add(npp5);
    std::cout << *npp1 << std::endl;
    Node<Person*> * npp1clone = npp1->clone();
    std::cout << "clone de npp1=" << std::endl << *npp1clone << std::endl;
    
    /*
     * 
     * 
     * SOLUTION: UTILISER LE POLYMORPHISME POUR FAIRE UNE BASE CLASS POUR LES METHODES GENERIQUES ET DEUX CLASSES FILLES, UNE POUR LES <T> ET L'AUTRE POUR LES <T*>
     * PROBABLEMENT QUE PRINT A REDEFINIR? 
     * LA FLEMME!
     * 
     * 
     */
    return 0;
}
