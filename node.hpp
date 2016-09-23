

#ifndef NODE_H
#define NODE_H
    
#include <iostream>
#include <vector>
#include <sstream>
#include <type_traits>

template<typename T>
class Node {
protected:
    // parent node
    Node<T> * m_parent;
    // list of descendants
    std::vector<Node<T> *> m_offspring;
    // value stored in this node
    T m_value;
public:
    /**
    * default constructor
    */
    Node(){};
    
    /**
    * constructor given value to store
    */
    Node(T _v):m_value(_v){};
    
    /**
    * add descendant
    */
    void add(Node<T> *_node){
        m_offspring.push_back(_node);
    };
    
    /**
    * clone subtree starting from this node
    */
    Node<T> *clone(){
        Node<T> * newNode = new Node<T>(m_value);
        for(unsigned int i=0;i<m_offspring.size();++i){
            newNode->add(m_offspring[i]);
        }
        return newNode;
    };
    
    /**
    * print node
    */
    std::ostream& print(std::ostream& _out){
        _out << m_value ;
        if(!m_offspring.empty()){
            _out << "(";
            for(unsigned int i=0;i<m_offspring.size();++i){
                _out << *m_offspring[i] << " | ";
            }
            _out << ")";
        }
        return _out;
    };
    
    friend std::ostream& operator<<(std::ostream& _out, Node<T>& _node) {
        return _node.print(_out);
    }
};

// template<typename T> class Node<T*>{
//  protected:
//     // parent node
//     Node<T> * m_parent;
//     // list of descendants
//     std::vector<Node<T> *> m_offspring;
//     // value stored in this node
//     T m_value;
// public:
//     /**
//     * default constructor
//     */
//     Node(){};
//     
//     /**
//     * constructor given value to store
//     */
//     Node(T _v):m_value(_v){};
//     
//     /**
//     * add descendant
//     */
//     void add(Node<T> *_node){
//         m_offspring.push_back(_node);
//     };
//     
//     /**
//     * clone subtree starting from this node
//     */
//     Node<T> *clone(){
//         Node<T> * newNode = new Node<T>(m_value);
//         for(unsigned int i=0;i<m_offspring.size();++i){
//             newNode->add(m_offspring[i]);
//         }
//         return newNode;
//     };
//     
//     /**
//     * print node
//     */
//     std::ostream& print(std::ostream& _out){
//         _out << *m_value ;
//         if(!m_offspring.empty()){
//             _out << "(";
//             for(unsigned int i=0;i<m_offspring.size();++i){
//                 _out << *m_offspring[i] << " | ";
//             }
//             _out << ")";
//         }
//         return _out;
//     };
//     
//     friend std::ostream& operator<<(std::ostream& _out, Node<T>& _node) {
//         return _node.print(_out);
//     }   
// };
#endif
    


