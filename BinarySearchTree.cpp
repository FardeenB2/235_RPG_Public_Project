//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>

#include "BinarySearchTree.hpp" 


//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////

template<class T>
auto BinarySearchTree<T>::placeNode(std::shared_ptr<BinaryNode<T>> subTreePtr,
                                                                std::shared_ptr<BinaryNode<T>> newNodePtr)
{
   if (subTreePtr == nullptr)
      return newNodePtr;
   else
   {
      if (*subTreePtr->getItem() > *newNodePtr->getItem())
         subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
      else 
         subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
      
      return subTreePtr;
   }  // end if
}  // end placeNode

template<class T>
std::shared_ptr<BinaryNode<T>> BinarySearchTree<T>::removeValue(std::shared_ptr<BinaryNode<T>> subTreePtr,
                                                              const T target, 
                                                              bool& success)
{
   if (subTreePtr == nullptr)           
   {
      // Not found here
      success = false;
      return subTreePtr;
   }
   if (*subTreePtr->getItem() == *target)
   {
      // Item is in the root of some subtree
      subTreePtr = removeNode(subTreePtr);
      success = true;
      return subTreePtr;
   }
   else 
   {
      if (*subTreePtr->getItem() > *target)
      {
         // Search the left subtree
         subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
      }
      else
      {
         // Search the right subtree
         subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
      }
      return subTreePtr;
   }  // end if
}  // end removeValue

template<class T>
auto BinarySearchTree<T>::removeNode(std::shared_ptr<BinaryNode<T>> nodePtr)
{
   // Case 1) Node is a leaf - it is deleted
   // Case 2) Node has one child - parent adopts child
   // Case 3) Node has two children:
   //               Traditional implementation: Find successor node.
   //               Alternate implementation: Find successor value and replace node's value;
   //                  alternate does not need pass-by-reference
   if (nodePtr->isLeaf())
   {
      nodePtr.reset();
      return nodePtr; // delete and return nullptr
   }
   else if (nodePtr->getLeftChildPtr() == nullptr)  // Has rightChild only
   {
      return nodePtr->getRightChildPtr();
   }
   else if (nodePtr->getRightChildPtr() == nullptr) // Has left child only
   {
      return nodePtr->getLeftChildPtr();
   }
   else                                             // Has two children
   {
      // Traditional way to remove a value in a node with two children
      T newNodeValue;
      nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
      nodePtr->setItem(newNodeValue);
      return nodePtr;
   }  // end if
}  // end removeNode

template<class T> 
auto BinarySearchTree<T>::removeLeftmostNode(std::shared_ptr<BinaryNode<T>> nodePtr,
                                                                     T& inorderSuccessor)
{
   if (nodePtr->getLeftChildPtr() == nullptr)
   {
      inorderSuccessor = nodePtr->getItem();
      return removeNode(nodePtr);
   }
   else 
   {
      nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
      return nodePtr;
   }  // end if      
}  // end removeLeftmostNode


// Override findNode because now we can use a binary search:
template<class T>
auto BinarySearchTree<T>::findNode(std::shared_ptr<BinaryNode<T>> subTreePtr,
                                                           const T& target) const 
{
   // Uses a binary search 
   if (subTreePtr == nullptr)
      return subTreePtr;                        // Not found
   else if (*subTreePtr->getItem() == *target)
   { 
      return subTreePtr;                     // Found
   }
   else if (*subTreePtr->getItem() > *target)
   {
      // Search left subtree
      return findNode(subTreePtr->getLeftChildPtr(), target);
   }
   else
   {
      // Search right subtree
      return findNode(subTreePtr->getRightChildPtr(), target);
   }
}  // end findNode

template<class T>
void BinarySearchTree<T>::destroyTree(std::shared_ptr<BinaryNode<T>> subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      destroyTree(subTreePtr->getLeftChildPtr());
      destroyTree(subTreePtr->getRightChildPtr());
      subTreePtr.reset(); // decrement reference count to node
   }  // end if
}  // end destroyTree

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{   }  // end default constructor

template<class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootItem)
: rootPtr(std::make_shared<BinaryNode<T>>(rootItem, nullptr, nullptr))
{  }  // end constructor

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& treePtr)
{
   rootPtr = this->copyTree(treePtr.rootPtr); // Call inherited method
}  // end copy constructor

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

/** @return root_ptr_ **/
template <class T>
std::shared_ptr<BinaryNode<T>> BinarySearchTree<T>::getRoot() const
{
  return rootPtr;
}

template<class T>
bool BinarySearchTree<T>::isEmpty() const
{
   return rootPtr == nullptr;
}  // end isEmpty

template<class T>
int BinarySearchTree<T>::getHeight() const
{
   return this->getHeightHelper(rootPtr); // Call inherited method
}  // end getHeight

template<class T>
int BinarySearchTree<T>::getNumberOfNodes() const
{
   return this->getNumberOfNodesHelper(rootPtr); // Call inherited method
}  // end getNumberOfNodes

template<class T>
void BinarySearchTree<T>::clear()
{
   this->destroyTree(rootPtr); // Call inherited method
   rootPtr.reset();
}  // end clear

template<class T>
bool BinarySearchTree<T>::add(const T& newData)
{
   //std::cout << "Adding " << newData << " to the tree." << std::endl;
   auto newNodePtr = std::make_shared<BinaryNode<T>>(newData);
   rootPtr = placeNode(rootPtr, newNodePtr);
   
   return true;
}  // end add

template<class T>
bool BinarySearchTree<T>::remove(const T& target)
{
   bool isSuccessful = false;
   // call may change isSuccessful
   rootPtr = removeValue(rootPtr, target, isSuccessful);
   return isSuccessful; 
}  // end remove

// Override contains to use our improved findNode:
template<class T>
bool BinarySearchTree<T>::contains(const T& anEntry) const
{
   return (findNode(rootPtr, anEntry) != nullptr);  // nullptr is same as false
}  // end contains

template <class T>
std::shared_ptr<BinaryNode<T>> BinarySearchTree<T>::getPointerTo(const T& target) const
{
  return findNode(rootPtr, target);
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class T>
void BinarySearchTree<T>::preorderTraverse(void visit(T&)) const
{
   this->preorder(visit, rootPtr); // Call inherited method
}  // end preorderTraverse

template<class T>
void BinarySearchTree<T>::inorderTraverse(void visit(T&)) const
{
   this->inorder(visit, rootPtr); // Call inherited method
}  // end inorderTraverse

template<class T>
void BinarySearchTree<T>::postorderTraverse(void visit(T&)) const
{
   this->postorder(visit, rootPtr); // Call inherited method
}  // end postorderTraverse


//////////////////////////////////////////////////////////////
//      Overloaded Operator 
//////////////////////////////////////////////////////////////

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::
                            operator=(const BinarySearchTree<T>& rightHandSide)
{
   if (!isEmpty())
      clear();
   this = copyTree(&rightHandSide); // Call inherited method
   
   return *this;
}  // end operator=




